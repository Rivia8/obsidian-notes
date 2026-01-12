23-01-2025 14:11

Status: #new

Tags:  [[Python]]

# State and Types
The state of an object in programming refers to the value of its attributes at a particular moment. 

In Python, state is usually associated with classes and objects. When we create an instance of a class, its attributes hold the state of that instance.

# Data Types
## Numeric Types
**int**: Integer Numbers
```Python
age = 25
```

**float:** Floating-point numbers
```Python
height = 5.9
```

**complex:** Complex Numbers
```Python
complex_number = 3 + 4j
```

## Sequence Type
**str:** String, a sequence of characters.
```Python
name = "Alice"
```

**list:** Ordered, mutable sequence of items
```Python
fruits = ["apple", "banana", "cherry"]
```

**tuple:** Ordered, immutable (cannot be changed after creation) sequence of items
```Python
coordinates = (10, 20)
```

Looking at lists and tuples, tuples are immutable so they cannot be changed. This makes tuples generally more faster and more memory-efficient that lists.
Lists are used when you need a dynamic collection of items that may change in size or content, such as a list of names, tasks, etc.

## Mapping Types:
**dict**: Dictionary, a collection of key-value pairs.
```Python
person = {"name": "Alice", "age": 30}
```

## Set Types:
**set:** Unordered collection of unique items.
```Python
unique_numbers = {1, 2, 3, 4, 5}
```

**frozen_set**: Immutable version of a set.
```Python
frozen_set = frozenset([1, 2, 3, 4, 5])
```

## Boolean Types
**bool**: Represents `True` or `False`.
```Python
is_student = True
is_teacher = False
```

## None Type:
**NoneType:** Represents the absence of a value or a null value
```Python
data = None
```

# Type Checking
You can check the type of a variable using the `type` function:

```Python
x = 10
print(type(x)) # Output: <class 'int'>>

y = "Hello"
print(type(y)) # Output <<class 'str'>>

```