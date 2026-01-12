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

## C Arrays are Pointers

Under the hood, arrays are implemented as [[Pointers|pointers]] in C.
Arrays can be quite large, and so it would be very inefficient to pass them by copy.

```C
void negate_int_array(int *ptr, int size) { // function taking pointer as parameter
    for(int i=0; i<size; i++)               // also need the size to iterate properly
        ptr[i] = -ptr[i];      // use square brackets like a standard array
}

int main(int argc, char **argv) {
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    negate_int_array(array, 7); // to get the pointer just use the array's name
    for(int i=0; i<7; i++)
        printf("array[%d] = %d\n", i, array[i]);
    return 0;
}
```

This function here takes the input parameter of a pointer, but as you can see in the main function we pass an array instead. This is because arrays pointers themselves.
In the function `negate_int_array`, we loop through each individual item via a `for` loop and the item is then negated and assigned back to the position it was at.

