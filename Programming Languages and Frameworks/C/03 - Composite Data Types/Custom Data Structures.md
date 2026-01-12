17-10-2025 15:21

Tags: [[C]]

# Custom Data Structures

These are very useful in C. They aggregate several fields of various types, they are created and manipulated with the `struct` keyword.

Defining a struct:
```C
struct person {
	char name[10]
	float size_in_meters;
	int weight_in_grams;
}
```

Here we have defined a `struct` with the name 'person'.

Now using the struct:

```C
void print_person(struct person p){
	printf("%s has a size of %f meters and weights %d grams\n", p.name, p.size_in_meters, p.weight_in_grams)
}
```

As you can see to access the variables within the `struct` you need to use a dot (`.`) after the name of the **instantiation** of the `struct`, here we have instantiated the `struct` as `p`.

In memory the fields of a struct are placed contiguously.

## Using `typedef`

Remember when trying to create [[Custom Types|custom types]] we used the keyword `typedef` we can do the same here in order to create a `struct` that is of a type:

``` C
typedef struct person {
	char name[10]
	float size_in_meters;
	int weight_in_grams;
} person;
```

Now we can quickly create `structs`.

## With Pointers

Data structures are often passed as [[Pointers|pointers]]. 
`structs` themselves can have pointer fields.

Here is an example of a `struct` with fields as pointers:

```C
typedef struct {
    int int_member1;
    int int_member2;
    int *ptr_member;
} my_struct;
```

Also if we had a previously declared `struct`, we can use a point to that variable:

```C
my_struct ms;

my_struct *p = &ms
```

Now we have the variable `*p` that holds the memory address of the `struct` `ms`.
In order to access the fields we'll need to dereference the variable `*p`:

```C
(*p).int_member1 = 1 
```
*parentheses are needed since `.` takes precedence over `*`*

There is also a shortcut but this is 'syntactic sugar' meaning they are exactly the same:

```C
p->int_member2 = 2
```
*`a->b` is just a shortcut for `(*a).b`, they are totally equivalent*

