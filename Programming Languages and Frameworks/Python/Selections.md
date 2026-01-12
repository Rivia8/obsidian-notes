23-01-2025 17:51

Status: #new`

Tags:  [[Python]]

# Selections
Selections are also known as conditional statements, in Python they allow you to execute specific blocks of code based on certain conditions. These are crucial for decision-making in programs.

## if Statement
The `if` statement is used to test a condition. If the condition is true, the block of code under the `if`statement is executed.

```Python
if condition:
	# block of code to execute if condition is true
```

**Example:**
```Python
age = 18
if age >= 18:
    print("You are an adult.")
```

## if-else Statement
This provides an alternative block of code to execute if the condition is `False`.

```Python
if condition:
    # Block of code to execute if condition is true
else:
    # Block of code to execute if condition is false

```

**Example:**
```Python
age = 16
if age >= 18:
    print("You are an adult.")
else:
    print("You are a minor.")

```

## if-elif-else Statement
The `if-elif-else` statement allows you to test multiple conditions. It’s a chain of `if-elif-else` blocks where each `elif` condition is tested if the previous conditions were `False`.

```Python
if condition1:
    # Block of code to execute if condition1 is true
elif condition2:
    # Block of code to execute if condition2 is true
else:
    # Block of code to execute if none of the above conditions are true
```

**Example:**
```Python
score = 85
if score >= 90:
    print("Grade: A")
elif score >= 80:
    print("Grade: B")
elif score >= 70:
    print("Grade: C")
elif score >= 60:
    print("Grade: D")
else:
    print("Grade: F")
```

## Conditional Expressions (Ternary Operator)
Python also provides a short way to write simple `if-else` statements using a conditional expression.

```Python
result = value_if_true if condition else value_if_false
```

**Example:** 
```Python
age = 18
status = "Adult" if age >= 18 else "Minor"
print(status) # Output: Adult
```
## Logical Operators
You can combine multiple conditions using logical operators (`and`, `or`, `not`).

**Example**:
```Python
age = 20
is_student = True

if age > 20 and is_student:
	print("Eligible for student discount")
else:
	print("Not eligible for student discount")
```

## Membership and Identity Operators
You can use membership operators (`in`, `not in`) and identity operators (`is`, `is not`) in conditional statements

**Example:**
```Python
fruits = ["apple", "banana", "cherry"]
if "apple" in fruits:
	print("Apple is in the list")

name = "Alice"
if name is "ALice":
	print("The name is Alice")
```
