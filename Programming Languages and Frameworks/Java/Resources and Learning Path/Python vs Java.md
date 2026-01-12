28-01-2025 11:13

Status: #new

Tags:  [[Java]] [[Python]]

# Python vs Java

## Similarities
- Both languages support object-orientated programming, allowing for encapsulation, inheritance, and polymorphism.
- Both are cross-platform languages, which means code written in either language can run on various operating systems without modification.
- They both have large standard libraries 

## Differences
- Python has a simpler, more readable syntax, which makes it easier for beginners to learn and use. Java syntax is more verbose and strict, **requiring explicit declarations.**
- Python is an interpreted language, which means it executes code line by line, making it suitable for rapid development and scripting. However, **Java is a compiled language**, and it requires code to be compiled into bytecode before it can be ran on the **Java Virtual Machine** (JVM), which makes it generally faster and more efficient.
- Python is popular in data science, machine learning, scripting and web development thanks to its simplicity and extensive libraries like NumPy, Pandas and Django. Java is commonly used in large-scale enterprise applications, Android app development, web services due to its robustness and performance capabilities.
- Java typically offers **better performance** and scalability compared to Python due to its compiled nature and the optimisations provided by the JVM.
- Python is considered a 'Duck Typing' language, where the language allows an object's behaviour to determine its suitability for a task. The name comes from the phrase "If it looks like a duck, swims like a duck, and quacks like a duck, then it probably is a duck.". Java is not considered a duck type language since its statically typed, so types are explicitly declared and checked at compile-time.

Python is what is known as a Strongly Typed language, meaning typing errors are prevented at runtime. Java is also Strong Typed *but* errors are prevented at **Compile Time**. 

The difference between the two when it comes *when* the the errors are discovered would be described as Python being **Dynamically Typed** and Java being **Statically Typed**. However, being a Compiled and Interpreted language does not always define whether you are Dynamically or statically typed.


| Feature       | Java                                                                                                                                                                                          | Python                                                                                                                                                                                                                                                                                                     |
| ------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Execution     | Compiled then Interpreted. Your .java source code is explicitly compiled into bytecode (.class files) by the programmer. This bytecode is then interpreted by the Java Virtual Machine (JVM). | Interpreted (with a hidden compile step). When you run a .py script, the interpreter first compiles it to bytecode (.pyc files) behind the scenes. This bytecode is then interpreted by the Python Virtual Machine (PVM). It feels like a pure interpreted language because the compile step is automatic. |
| Type System   | Strongly Typed. You cannot perform operations on mismatched types. 5 + "hello" will result in a compile-time error.                                                                           | Strongly Typed. You cannot perform operations on mismatched types. 5 + "hello" will result in a TypeError at runtime.                                                                                                                                                                                      |
| Type Checking | Statically Typed. You must declare the type of a variable before you use it (int x = 5;), and this is checked by the compiler before the program runs.                                        | Dynamically Typed. You do not declare a variable's type (x = 5). The type is checked as the code executes (at runtime). You can reassign the same variable to a different type (x = "hello").                                                                                                              |
