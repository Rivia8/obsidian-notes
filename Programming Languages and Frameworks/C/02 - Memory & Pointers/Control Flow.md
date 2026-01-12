17-10-2025 10:17

Tags: [[C]]

# Control Flow

## Conditionals

### If Statement

To create a **conditional** we use the `if` statement. 
Its quite simple, if the condition within the parentheses is true, the code within the braces will be executed:

```C
if (x==50){
	printf("the value of x is 50\n");
}
```

We can use `else` to define a block of code that is executed only if the condition is false:

```C
if(x < 50) {
    printf("The value of x is strictly less than 50\n");
} else if (x == 50) {
    printf("The value of x is exactly 50\n");
} else {
    printf("The value of x is strictly more than 50\n");
}
```

### Writing the Condition

There is no `boolean` type in C.
A condition is false if it evaluates to 0 ad it is true if it evaluates to anything but `0`.
We **do** have the following **boolean** operators: 
- `&&` (logical AND),
- `||` (logical OR),
- `!` (negation)

### Switch Statement

If you have to write a long `if` statement (there are a lot of `if` ... `else` chains) the best thing to do is to use a `switch` statement:

```C

switch(x) {
    case 1:
        printf("x is 1\n");
        break;
    case 2:
        printf("x is 2\n");
        break;
    case 3:
        printf("x is 3\n");
        break;
    default:
        printf("x is neither 1, nor 2, nor 3\n");
}
```

## Loops

### While loops

The `while` loop keeps executing its body as long as a given condition is true.
There are two flavours of the regular `while` loop:

1. 
```C
int x = 10;
while (x > 0) {
    printf("x is %d\n", x);
    x = x - 1;
}
```

```C
int x = 10;
do {
    printf("x is %d\n", x);
    x = x - 1;
} while (x > 0);
```

### For loops

The `for` loop allows the use of an iterator to seamlessly fit in, in a `for` loop we have a header that has 3 things:
1. An initial statement that is executed once at the beginning of the loop,
2. A condition checked before each iteration of the loop,
3. If true the loop continues, if false, it exits.

```C
for(int i = 0; i<10; i = i + 1) {
    printf("i is %d\n", i);
}
```

### `break` and `continue`

These two keywords are present in `for` and `while` loops.

`break` will directly exit the loop.
`continue` will jump straight into the next iteration.