03-06-2025 01:47

Tags: [[Java]]

# Operators

Operators are used to perform operations on variables and values.

## Arithmetic Operators

There are used to perform common mathematical operations.


| Operator | Name           | Description                            |
| -------- | -------------- | -------------------------------------- |
| +        | Addition       | Adds two values together               |
| -        | Subtraction    | Subtracts on value from another        |
| *        | Multiplication | Multiplies two values together         |
| /        | Division       | Divides one value by another           |
| %        | Modulus        | Returns the division remainder         |
| ++       | Increment      | Increases the value of a variable by 1 |
| --       | Decremenet     | Decreases the value of a variable by 1 |

## Java Assignment operators

Assignment operators are used to assign values to variables.

```Java
int x = 10;
```

We also have something called the **addition assignment** which adds a value to a variable (this is good for loops):

```Java
int x = 10;
x += 5;
```

| Operator | **Example** | **Same As** |
| -------- | ----------- | ----------- |
| =        | x = 5       | x = 5       |
| +=       | x += 3      | x = x + 3   |
| -=       | x -= 3      | x = x - 3   |
| \*=      | x \*= 3     | x = x * 3   |
## Java Comparison Operators

Comparison operators are used to compare two values (or variables). 
The return value of a comparison operator is either `true` or `false`, which are Boolean values.

| Operator | Name         | Example |
| -------- | ------------ | ------- |
| ==       | Equals to    | x == y  |
| !=       | Not equal to | x != y  |
| >        | Greater than | x > y   |
| <        | Less than    | x < y   |

## Java Logical Operators

You can also test for `true` or `false` with logical operators, this is similar to that of how binary gates work.

| Operator | Name        | Description                                                        |
| -------- | ----------- | ------------------------------------------------------------------ |
| &&       | Logical and | Returns true if both statements are true                           |
| \|\|     | Logical or  | Returns true if only one statement is true                         |
| !        | Logical not | Reverses the result, so if the result is false then returns true., |

