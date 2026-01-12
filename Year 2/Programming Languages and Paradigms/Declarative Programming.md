05-10-2025 08:10

Tags: [[Programming Languages & Paradigms]]

# Declarative

In **declarative** programming, the programmer describes how the result should look like.
A good example of a pure declarative language is HTML, it is used to construct web pages, declaring elements such as headings and paragraphs with tags.
Declarative programming is at a much higher level of abstraction compared to imperative programming that is closer to the machine model.

With declarative programming languages, a few lines of code can describe complex programs and the low level can be abstracted but the downside is that the code can be easily convoluted and hard to understand in large programs. 

Examples of pure declarative languages include: **HTML, SQL, XML, CSS, LaTeX**

## Declarative **Functional** Programming 

In this paradigm, the programmer calls and composes functions to describe the program:

```Haskell
add_10 x = x + 10
twice f = f . f
main = do
    print $ twice (add_10) 7
```

Here the function `add_10` takes on parameter and adds ten to it.
We also define another function that takes another function as a parameter and applies it twice.
The last line will print 27, as it first adds 10 to 7 and passes the result as a parameter to a second call of `add_10`.

### First Class and Higher-Order Functions

 These are two concepts that can be found within **functional programming** and are closely related to one another:

#### First-Class Function

A **first-class function** is a function that the programming language treats as a 'first-class' citizen. This means that you can treat a function just like any other variable (like `ints` or `Strings`)

#### Higher-Order Function

A **higher-order function** is a direct result of having first-class functions - it is a function that operates on other functions.

A function is considered a higher-order function if it meets at least one of these two conditions:

**1. It takes one or more functions as arguments**
**2. It returns a function as a result**

It pretty much is a function that is 'in charge' of other functions. Common examples of these include: `map`, `filter` and `reduce`.

```JavaScript
// 'numbers' is an array of numbers.
const numbers = [1, 2, 3, 4];

// 'double' is a simple function that will be our tool.
const double = (x) => x * 2;

// 1. 'map' is a higher-order function because it takes another
//    function ('double') as its argument.
const doubledNumbers = numbers.map(double);

console.log(doubledNumbers); // Outputs: [2, 4, 6, 8]
```

#### The Relationship

You need first-class functions in a language to be able to create higher-order functions. The ability to treat functions like any other variable is what allows you to pass them into and get them out other functions.

### Loops Implementation

In imperative programming, we use `for` and `while` loops, but in functional programming we avoid loops because they often require changing a state variable (like a counter `i`)
Instead, it uses **recursion**, where a function calls itself until it hits a stop condition.

Functional recursion:

```Haskell
-- The sum of numbers up to n is...
sum n =
  if n <= 0
    then 0 -- The sum of nothing is 0 (stop condition)
    else n + sum (n - 1) -- n plus the sum of all numbers below it
```

## Declarative Concurrent Programming

Some declarative languages also provide ways to describe concurrent operations, e.g. Erlang provides what is called the actor model. One of the advantages of this model is a reduction in synchronisation operations.
Declarative concurrent languages are useful when designing distributed applications, web services, and so on.

