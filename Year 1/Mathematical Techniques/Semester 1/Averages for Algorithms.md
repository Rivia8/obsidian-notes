11-01-2025 21:49

Status: 

Tags: [[Maths]]

# Averages for Algorithms
An important application of expected values in Computer Science is the *average complexity* of an algorithm.

## Linear Search
Assuming we have an array of integers (e.g. student IDs) and we are trying to find a particular ID number in that array.
If there are $n$ student ID's the Expected Value is (assuming it is equally likely for each ID to be the one we are looking for):
$$ E(X) = \frac{1}{n} \cdot 1 + \frac{1}{n} \cdot 2 + ... + \frac{1}{n}(n-1) + \frac{1}{n} n  $$
$$ \frac{1}{n} ∑^n_i i $$
$$ \frac{n+1}{2} $$

## Binary Search
Binary searching involves looking at a sorted array (that is ascending) right at the middle and comparing the value being searched that index. If its larger then it looks at the top half from the middle, if its smaller then it looks at the bottom and repeats until it finds the searched value.

![[Pasted image 20250111224838.png#invert]]

When looking at the relationship between the 'nodes' and the trees:
![[Pasted image 20250111231053.png#invert]]

## Comparing Functions
**Motivation**: Lets say we have a problem of size **n**, and we have Algorithm A and Algorithm B to solve the problem. 
Which one should we choose?

![[Pasted image 20250112202400.png#invert]]
So we can say that a function dominates another function, if for every input, the output from one function is greater than or equal to the other function.

However, some functions will eventually 'dominate' another.

![[Pasted image 20250112204214.png#invert]]

