16-10-2025 19:04

Tags: [[C]]

# Arrays

In order to define an array in C you do the following:

```C
int array[4];
```

Here we have defined an array with 4 elements.

We can define what are in what slots by doing the following:

```C
array[0] = 10;
array[1] = 20;
```

**Note: C has 0 indexing, so the first element is at `array[0]`**

Arrays are stored contiguously in memory:

![[arrays.svg#invert]]

## Multi-dimensional Arrays

Arrays can be of multiple dimensions, to declare one you use several pairs of square brackets:

```C
int my_2d_array[3][4];
```

This is a 3 by 4 array.

## Static Initialisation

This is shown here:

```C
int array[] = {1, 2, 3, 4, 5};
int array_2d[][2] = { {1, 2}, {3, 4}, {5, 6} };
```

Here we have initialised 3 arrays of size 2 with the declaration.

