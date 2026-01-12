28-01-2025 16:00

Status: #new

Tags: [[Java]]

# Control Structures
We are quite familiar with control structures already.

## Conditionals
1. `if` statement
```Java
if (condition) {
	// code to be executed if the condition is true
}
```

2. `if-else` statement
```Java
if (condition) {
	// code to be executed if the condition is true
} else {
	// code to be executed if the condition is false
}
```

3. `else-if` ladder: for multiple conditions
```Java
if (condition1) {
	// code to be executed if the condition1 is true
} else if (condition2) {
	// code to be executed if the condition2 is true
} else {
	// code to be executed if both conditions are false
}
```

### Switch Statement
This is a new type of programming construct that we have not seen before in python (we have seen in the Verilog HDL).
This executes one out of many blocks of code based on the value of a variable.

```Java
switch (variable) {
	case value1:
		// code to be executed if variable == value1
		break;
	case value2:
		// code to be executed if variable == value2
		break;
	// you can have any number of case statements
	default:
		// code to be executed if variable does not match any case
}
```

**Example:**
```Java
int month = 5; // Let's assume 5 represents May
String monthName;

switch (month) {
    case 1: // if month = 1, 
        monthName = "January"; // monthName = "January"
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    //... the rest of the months
}

System.out.println("The month is: " + monthName);

```

Looking at this example, the input variable is `month` which was assigned the value 5.
The switch statement evaluates the value of `month`. The `default` class acts as a error handler where if a number is entered that is not between 1 and 12, it outputs "Invalid Month".
Since `month` holds the value 5, the output would be: "The month is: May".



## Iterations

1. `for` loop
```Java
for (initialization; condition; update) {
    // code to be executed
}
```
**Example:**
```Java
for (int i = 0; i < 10; i++) {
    System.out.println(i);
}
```

2. `while` loop
```Java
while (condition) {
	// code to be executed
}
```

**Example:**
```Java
int i = 0;
while (i < 10) {
    System.out.println(i);
    i++;
}
```

3. `do {..} while loop`
This is a new construct, it is similar to the while loop, but the block of code is executed at least once before the condition is tested.
```Java
do {
    // code to be executed
} while (condition);
```

**Example:**
```Java
int i = 0;
do {
    System.out.println(i);
    i++;
} while (i < 10);
```

The output of this example would be:
```
0
1
2
3
4
5
6
7
8
9
```

But the key thing to remember about `do-while` loops is that it guarantees the block of code will run at least once since the condition is evaluated after the `do` block.

### Enhanced For loop

We can also have enhanced for loops that are used to iterate through elements of a collection or an array easily - without using an iterator or index.

```Java
for (String item : shoppingList) {
	System.out.println(item);
}
```

### For each

This is a more modern, functional way to iterate over collections and streams. 
You give the collection a piece of code (the lambda) to run on each of its elements.

```Java
List<String> fruits = List.of("Apple", "Banana", "Cherry");

// "For each 'fruit' in the fruits list, execute this code."
fruits.forEach(fruit -> System.out.println(fruit));
```

