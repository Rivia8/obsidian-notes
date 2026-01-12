06-10-2025 12:20

Tags: [[C]]

# Syntax

The syntax is what we have already looked at and seen in [[Java]] this is because Java was actually inspired by C's syntax:

```C
#include <stdio.h>
int main() {
    printf("hello, world!\n");
    return 0;
}
```

The first line that says `#include <stdio.h>` allows us to get access to functions from external libraries,
The reason we need the external library is because we need the `printf` function from `stdio.h` to be able to get a standard output.

At the end of `main()` we have `return 0`, this actually triggers the  exit of the program and returns with the code 0.


## Comments

Comments are annotations in the source file that will not be processed by the compiler.
It is important for a programmer to comment code a bit to explain what it does.

```C
/* style 1 */
// style 2
```


## Operators

Operators are special symbols that tell the compiler to perform specific mathematical, logical, or memory-related operations.

Here is a list of operators:

**Arithmetic Operators:**

| **Operator** | **Name**       | **Example**    | **Description**                                                                       |
| ------------ | -------------- | -------------- | ------------------------------------------------------------------------------------- |
| **`+`**      | Addition       | `a + b`        | Adds two numbers.                                                                     |
| **`-`**      | Subtraction    | `a - b`        | Subtracts one number from another.                                                    |
| **`*`**      | Multiplication | `a * b`        | Multiplies two numbers.                                                               |
| **`/`**      | Division       | `a / b`        | Divides one number by another. (Note: `5 / 2` will be `2`, as it's integer division). |
| **`%`**      | Modulus        | `a % b`        | Returns the remainder of a division (e.g., `5 % 2` is `1`).                           |
| **`++`**     | Increment      | `a++` or `++a` | Increases an integer's value by one.                                                  |
| **`--`**     | Decrement      | `a--` or `--a` | Decreases an integer's value by one.                                                  |

**Relational Operators:**

| **Operator** | **Name**                 | **Example** | **Description**                                                              |
| ------------ | ------------------------ | ----------- | ---------------------------------------------------------------------------- |
| **`==`**     | Equal to                 | `a == b`    | Checks if two values are equal. (A common bug is using `=` instead of `==`). |
| **`!=`**     | Not equal to             | `a != b`    | Checks if two values are _not_ equal.                                        |
| **`>`**      | Greater than             | `a > b`     | Checks if the left value is greater than the right.                          |
| **`<`**      | Less than                | `a < b`     | Checks if the left value is less than the right.                             |
| **`>=`**     | Greater than or equal to | `a >= b`    | Checks if the left value is greater than or equal to the right.              |
| **`<=`**     | Less than or equal to    | `a <= b`    | Checks if the left value is less than or equal to the right.                 |

**Logical Operators:**

| **Operator** | **Name**    | **Example**         | **Description**                                                     |
| ------------ | ----------- | ------------------- | ------------------------------------------------------------------- |
| **`&&`**     | Logical AND | `(a > 5 && b < 10)` | Returns `1` (true) only if **both** conditions are true.            |
| **`          |             | `**                 | Logical OR                                                          |
| **`!`**      | Logical NOT | `!(a == b)`         | Inverts a condition. Turns `true` to `false` and `false` to `true`. |

**Assignment Operators:**

| **Operator** | **Name**                  | **Example** | **Shorthand For...** |
| ------------ | ------------------------- | ----------- | -------------------- |
| **`=`**      | Assignment                | `a = 10`    | `a = 10`             |
| **`+=`**     | Addition Assignment       | `a += 5`    | `a = a + 5`          |
| **`-=`**     | Subtraction Assignment    | `a -= 5`    | `a = a - 5`          |
| **`*=`**     | Multiplication Assignment | `a *= 5`    | `a = a * 5`          |
| **`/=`**     | Division Assignment       | `a /= 5`    | `a = a / 5`          |
| **`%=`**     | Modulus Assignment        | `a %= 5`    | `a = a % 5`          |

**Bitwise Operators:**

|**Operator**|**Name**|**Example**|
|---|---|---|
|**`&`**|Bitwise AND|`a & b`|
|**`|`**|Bitwise OR|
|**`^`**|Bitwise XOR|`a ^ b`|
|**`~`**|Bitwise NOT (Complement)|`~a`|
|**`<<`**|Left Shift|`a << 2`|
|**`>>`**|Right Shift|`a >> 2`|

**Pointers and Memory Operators:**

|**Operator**|**Name**|**Example**|**Description**|
|---|---|---|---|
|**`&`**|Address-of|`int* ptr = &myVar;`|Gets the memory address of a variable.|
|**`*`**|Dereference|`int value = *ptr;`|Gets the value _at_ a memory address (the "opposite" of `&`).|
|**`sizeof()`**|Size-of|`int size = sizeof(int);`|Returns the size (in bytes) of a data type or variable.|

**Other:**

|**Operator**|**Name**|**Example**|**Description**|
|---|---|---|---|
|**`?:`**|Ternary Operator|`(a > b) ? a : b`|A shorthand `if-else`. "If `a > b` is true, use `a`, otherwise use `b`."|
|**`[]`**|Array Subscript|`myArray[0]`|Accesses an element in an array.|
|**`()`**|Function Call|`myFunction()`|Calls a function.|
|**`.`**|Member Access|`myStruct.member`|Accesses a member of a `struct`.|
|**`->`**|Pointer Member Access|`myStructPtr->member`|Accesses a member of a `struct` _via a pointer_.|