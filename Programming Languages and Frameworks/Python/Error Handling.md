23-01-2025 18:52

Status: #new

Tags: [[Python]]

# Error Handling
Error handling refers to the process of anticipating, detecting, and resolving errors or exceptions that occur during the execution of a program. Effective error handling ensures that a program can gracefully recover from unexpected situations, providing a better user experience and maintaining the integrity of the program.

## Types of Errors
1. Syntax Errors:
	Essentially represents a grammatical error, like misspelled variable names, missing (semi)colons, incorrect format in selection and loop statements etc.

2. Semantic Errors:
	Occurs when a computer is asked to do something that it is unable to reliably do, like using a none initialised variable, errors in expressions, having an array index out of bounds...

3. Logic Errors:
	Occurs when the program runs without crashing but produces incorrect results. It is usually produces from a flaw in the program's design and as a result is harder to detect and debug.
	Examples could be multiplying when you should have divided, opening and using data from the wrong file and displaying the wrong message.

4. Compile Time Errors:
	Something that happens when you violate the rules of the syntax. So essentially are syntax errors but the compiler usually prompts the error. This must be fixed before the code can be compiled. Common errors include: Missing parenthesis, printing an undeclared value, missing semicolon etc.

5. Runtime Errors:
	These occur during the execution of the program after a successful compilation. It can sometimes be hard to find as the compiler doesn't always point to the error. A common error is a divide by zero error.

## Dealing with Errors
### try and except 
The `try` and `except` blocks are used to catch and handle exceptions. this prevents the program from crashing and allows you to provide a meaningful response to the error.

**Example:**
```Python
try:
	result = 10/0
except ZeroDivisionError:
	print("Error: Cannot Divide by zero!")
```

```Python
while True:
    try:
        x = int(input("Please enter a number: "))
        break
    except ValueError:
        print("Oops!  That was no valid number.  Try again...")
```

#### Using an else block
The `else` block can be used to execute code only if no exceptions were raised in the try block.

**Example:**
```Python
try:
    result = 10 / 0
except ZeroDivisionError:
    print("Error: Cannot divide by zero!")
else:
    print("Division successful:", result)
```

#### Using finally
The `finally` block is always executed, regardless of whether an exceptions was raised or not. It is useful for cleaning up resources.

**Example:**
```Python
try:
    file = open("example.txt", "r")
    content = file.read()
except FileNotFoundError:
    print("Error: File not found!")
finally:
    print("Finished")
```

#### Raising Exceptions
You can raise exceptions intentionally using the `raise` keyword. This is useful when you want to signal an error condition in your code.

**Example:**
```Python
def check_age(age):
    if age < 18:
        raise ValueError("Age must be 18 or older.")
    return "Valid age"

try:
    check_age(16)
except ValueError as e:
    print(e)
```

In the example, the exception object is assigned to the variable `e` using `as e`WE can then use the variable `e` to print or access the exception message or other attributes.
#### Creating Custom Exceptions
You can define your own exceptions by creating custom exception classes. This is useful for creating specific error conditions related to your application.

**Example:**
```Python
class CustomError(Exception):
    pass

def risky_function():
    raise CustomError("Something went wrong!")

try:
    risky_function()
except CustomError as e:
    print(e)

```