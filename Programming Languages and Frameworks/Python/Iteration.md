23-01-2025 14:57

Status: #new

Tags: [[Python]]

# Iteration
The most common types of loops used in Python are `for` loops and `while` loops.

## for loops:
The `for` loop is used to iterate over a sequence, (like a list, tuple, dictionary, set, or string) and perform a block of code for each item in the sequence:
```Python
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
	print(fruit)
```

It can also be used to iterate over a range of numbers:
```Python
for i in range(5):
	print(i)
```
## While loops:
The `while` loop will repeatedly execute a block of code as long as a given condition is true.

```Python
i = 0
while i < 5:
	print(i)
	i += 1
```

## Nested loops:
You can nest loops inside each other to perform more complex iterations
```Python
for i in range93):
	for j in range(2):
		print(f"i={i}, j={j}")
```

## Iterating with Built-in Functions and Tools
Python provides several built-in functions and tools to facilitate iteration. 

`enumerate`: loops through a sequence and gets the index and a value.
```Python
fruits = ["apple", "banana", "cherry"]
for index, fruit in enumerate(fruits):
    print(index, fruit)
```

```Output
0 apple
1 banana
2 cherry
```

`zip`: loops through multiple sequences in parallel.
```Python
names = ["Alice", "Bob", "Charlie"]
ages = [25, 30, 35]
for name, age in zip(names, ages):
    print(f"{name} is {age} years old")
```

```Output
Alice is 25 years old
Bob is 30 years old
Charlie is 35 years old
```

`iter`: create an iterator from an object
```Python
my_list = [1, 2, 3]
it = iter(my_list)
print(next(it))
print(next(it))
print(next(it))
```

```Output
1
2
3
```

**List Comprehensions**: A nice way to create lists
```Python
squares = [x**2 for x in range(10)]
print(squares)
```

```Output
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
```

