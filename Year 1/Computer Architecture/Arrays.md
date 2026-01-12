09-12-2024 12:39

Status: #new 

Tags: [[Architecture]]

# Arrays
An array is a data structure that stores a collection of items, typically of the same type, in a contiguous memory location. Each item can be access using an index.

You can have one-dimensional arrays and multi-dimensional arrays. Multi-dimensional arrays are arrays of arrays, such as matrices.

Arrays are heavily used in **scientific computation**:
**Iterative solutions**: 
- Arrays are critical for solving systems of partial differential equations iteratively. These equations often model physical phenomena and require iterative methods to find solutions.
**Finite Difference and Finite Element Methods**: 
- These numerical techniques use arrays to approximate solutions to differential equations. They are widely used in engineering and physics simulation.
**Matrix Operation**:
- In coupled systems, matrix operations are essential. Arrays store and manipulate these matrices efficiently.


The Advantages of using arrays are that:
- **Fast Access**: Indexed access allows for quick retrieval and update of elements.
- **Memory Efficient**: Contiguous memory allocation reduces overhead and improves cache performance.

The Disadvantages:
- **Fixed Size**: Arrays cannot be resized dynamically, which can lead to wasted memory or the need to allocate new arrays.
- **Insertion/Deletion Costs**: Inserting or deleting elements can be inefficient as it may require shifting elements.

## Arrays in Python
![[Pasted image 20241209154748.png#invert]]
![[Pasted image 20241209154811.png#invert]]

## Arrangement of Arrays in Memory
1. Integer Arrays:
	- Each element in the integer array is 32 bits (4 bytes in size)
![[Pasted image 20241209155009.png#invert |400]]
2. 1-D Arrays:
	- In simple one-dimensional arrays, elements are stored consecutively in memory. This means that each element follows directly after the previous one without any gaps.
3. Accessing Array Elements:
	- To access any individual element in the array, you need to know two things: the base address of the array and the element's index (or position).
	- The formula to find the address of an element `i` in the array is:
	- `Address of element i = Base address + 4i `
	- This formula works because each element is 4 bytes, so multiplying the index by 4 gives the correct offset from the base address.


So an element `i` is at: base address + 4`i`. The processor stores the base address of the array, this is known as the 'pointer to the array', because it points to where the array is stored in memory.
The processor needs to know the index (or offset) `i` to access a specific element in the array.

## Using an Array in RISCV
1. Declare the array:
	Array of students, heights:
	`heights defb 0,150,160,165,155,150,170,175,180,155,160`
2. Set up base address and index:
	`li a0, 10` - index set to student number 10 
	`la a1, heights` - making a1 the pointer to the array.
3. Access element 10 of the array:
	`add a1, a1, a0` - set current student number to 10 by adding the index to the pointer
	`lb a2, 0[a1]` - height is at base address + `i`

![[Pasted image 20241212204720.png#invert]]
## Multiplying and Dividing by Powers of 2
Remember that when you shift binary numbers to the left or right you are multiplying or dividing by 2.
`slli`: shift left logical immediate,
`srli` : shift right logical immediate.

## Out of Bounds Accesses
This is an attempt to access an array element that is outside the memory area of the actual array.
For an example:
```python
for i in range (1,N):
	a[i] = i
```
What would happen if N = 20?
If N is a constant then it might be possible to detect the problem at compile time and issue a warning.
However, `x = a[ b * c + d ];`
if b, c and d are variables the compiler cannot know the values that `b * c + d` will have at run time.

### Arrays Bounds Checking
If we had code of the form `b = a[x * x]`
Each element is 4 bytes long.
```R
mul a1, a0, a0
slli a1, a1, 2
add a1, a1, a2 ;adding to the current address
lw a3, 0[a1]
```

to check that` a1` is within bounds when `lw` is executed:
```R
mul a1, a0, a0
li a4, N ; compare a4, N
bge a1, a4, ErrorCode ; if index > N
slli a1, a1, 2
```
 if the result of the multiplication `[x*x]` is larger than N, then it will jump to an error procedure.
This requires you storing the size of the array (N) somewhere.

**Additional Considerations**:
There may be reason to check the lower bound too, this means that the compiler could cause the target address to be checked against both upper and lower array bounds. Bounds checking requires additional code and may require additional registers, memory etc. This means that bounds checking takes time and resources, some compilers may provide the option of switching bounds checking off - 'Full optimisation' for speed and code size, but only use this if you are sure that the code cannot generate an array index out of range, whatever the data.

#### OS Memory Bounds Checking
The OS will have a memory management system:
Users will have an allocated space, users should not be able to access memory outside their allocated space, it may be that user space and data space are separately managed by the OS, that does not prevent user code from accessing an invalid party of the user space so the code still needs to do bounds checking.

## Arrays of Objects
Python arrays can be arrays of objects, not just bytes or integers:
`s = ["str1", "str2", "str3", …]`
	this is an array of strings.
Python is slower compared to that of C or C++ when it comes to dealing with arrays, that is due to python using dynamic typing, meaning that the type of a variable is determined at runtime. 
When it comes to arrays, Python's array implementation typically implements them as lists, which are dynamic arrays that can grow or shrink in size. Each element in a list is **a reference to an object**, adding a layer of indirection and increasing memory usage. Arrays in C and C++ are implemented as contiguous blocks of memory, with each element directly accessible via its index. This allows for fast, constant-time access and minimal memory overhead.

Implementing an array of strings in RISCV.
In RISCV:
```R
; Assume a1 points to s.
; s is an array of 4-byte
; addresses so element 2 is:
addi a1, a1, 8
lw a0, 0[a1] ;a0 now points to s(2)
lb a2, 0[a0]; ;a2 now contains ‘a’
addi a0, a0, 1
lb a2, 0[a0] ;a2 now contains ‘b’
etc
```
![[Pasted image 20241212224108.png#invert]]

### Multi-Dimensional Arrays
You can also have something called multi-dimensional arrays, e.g.
	`m = [[0,1,2,3],[4,5,6,7]]`

![[Pasted image 20241212224505.png#invert]]
#### Storage of Elements
In some languages the entire array is stored contiguously in memory.
If the size of the array is (M, N),  in this case a 3x3 row by column:
- a(i, j) can be accessed as if it were element `j + N * i` of an 1-D array of size `M x N`
- The whole array can be accessed by sequentially by autoincrementing:
```R
lw a0, 0[a1]
addi a1, a1, 4
```
![[Pasted image 20241212225446.png#invert]]