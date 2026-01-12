10-02-2025 13:42

Tags: [[Computation]]

---
# Intro 

Computers need to be able to read and interpret files, interpret inputs from a wide variety of peripherals and need to be able run the resulting code from compiling languages such as C, Java or ML. 
So we give the computer very large inputs, but from that very large input how does it *know* what to do with? How does it decide what variables to create and what values to give to it?

In order to organise, or parse, the given input the computer must recognise specific strings (commands like `if else` and `for`), so the ability to be able to find certain specific strings is very important.

The unit of Computation will help to understand how the computer breaks down inputs and *computes* the information to  retrieve certain bits of information that fill certain requirements.

For an example: 
How do online shopping assistants work? They find a given product at various shops and tell you what it costs. How do they extract the information, in particular since some of the pages describing the product are created on demand only?

# Describing Languages to a Computer

In order to solve the problems posed, we need to describe to the computer what it is looking for.
In only very simple cases it will be just one or two strings - in general we would want the computer to look for a much larger collection of words.

## Terminology

We have to introduce a few terms so that we can talk about the various concepts involved.

### Symbol
This is a building for a string. Symbols cannot be sub-divided, they are essentially the atoms of everything we build.
In *formal languages* they are often referred to as **letters**.

	e.g. a, A, 0, 1, %, @

We use letters from the end of the Roman alphabet, like x, y, z, to refer to an arbitrary symbol.

### Alphabet
An **alphabet** is a collection of letters. We think of it as a set. 

	e.g. {0, 1}, {0, 1, … , 9}, {𝑎, 𝑏, … , 𝑧}, {𝑎, 𝑏, … , 𝑧, 𝐴, 𝐵, … , 𝑍},.

We use capital Greek letters, typically $\Sigma$, to refer to an arbitrary alphabet. Arbitrary meaning that any characters can be chosen to represent the alphabet

### String
A **String** is something we build from 0 or more symbols. In *formal languages* we usually speak of **words**. 

	e.g. 𝑎𝑏𝑎𝑏𝑎𝑏, 0, 1001 

Every letter can be a viewed as a one-lettered word.
#### The Empty Word
This consists of 0 letters, it is hard to denote. We use $\epsilon$ to denote it.
Something to remember is that when you concatenate the empty word with a word or a letter you just get the same letter/word.

### Concatenation
This is performed on words and letters to obtain longer words.

	e.g. When concatenating 𝑎 with 𝑏 we get 𝑎𝑏, and we can concatenate that with the word 𝑏𝑎 to obtain 𝑎𝑏𝑏𝑎.

### Using the *Power* notation
We use the notation of powers as follows: 

if $s$ is a word then $(S)^n$ is the word we get by concatenating $n$ copies of $s$. 
For example: $(010)^3$ = 010010010, $1^2$ = 11, $𝑏^0$ = 𝜖 and $c^1$ = 𝑐.

### Language
A language is a collection of words, which we think of as a set. Examples are:
{𝜖}, ∅, {𝑎𝑏, 𝑎𝑏𝑐, 𝑎𝑏𝑎} and {𝑎 𝑛 ∣ 𝑛 ∈ ℕ}. We use letters such as L, L1 and L ′ to refer to an arbitrary language.

## Defining Languages
If a language is finite, then we can describe it quite easily - you just list all the elements. 
However, this doesn't work when the language is **infinite** AND when the language is very large.

When defining languages we can use set-theoretic notation.

We are familiar with terminologies like **Union**, **Intersection** and **Set Difference.**

Here are some you might not be familiar with:

### Complement
Given a language $L$ over an alphabet $\Sigma$, the **complement** of $L$, denoted as $L'$ or $\overline{L}$, is the set of all strings over the alphabet $\Sigma$ that are **not** in $L$.
It is defined as:
$$ L' = \Sigma^*\backslash L $$
Where:
- $\Sigma^*$: This represents the set of all possible strings (including the empty string) that can be formed using the alphabet $\Sigma$ - note that in our format we can have $L(\Sigma)$ as a universal set.

Let's look at an example:
- Alphabet $\Sigma$ = {a, b}
- Language $L$ = {a, ab}

Then:
- $\Sigma^*$ = {ϵ, a, b, aa, ab, bb, ba, aaa,…} (all possible strings over {a, b})
- $L'$ = {ϵ, a, b, aa, bb, ba, aaa,...} (all possible values except those in $L$)

So the compliment of $L$, $L'$ includes every possible string over the alphabet that is **not** in the original string. 

### Concatenation
In formal languages **Concatenation**, is about joining strings from two languages together, end-to-end.

Concatenation of two languages $L_1$ and $L_2$ is the set of all strings that can be formed by taking a string from $L_1$ and following it by a string from $L_2$. 

Let's say we have:
- $\Sigma$ = {a, b}
- $L_1$ = {ab, aa}
- $L_2$ = {bb, a}

The concatenation $L_1 \cdot L_2$ consists of all possible strings formed by taking each word (or string) from $L_1$ and joining it with each string from $L_2$.

- Taking "ab" from $L_1$ and "bb" from $L_2$, we get "abbb".
- Taking "ab" from$L_1$ and "a" from $L_2$, we get "aba".
- Taking "aa" from $L_1$ and "bb" from $L_2$, we get "aabb".
- Taking "aa" from $L_1$ and "a" from $L_2$, we get "aaa".

So, $L_1 \cdot L_2$ would be:
$$ L_1 \cdot L_2 = \{abbb, aba, aabb, aaaa\} $$


### $n$-ary Concatenation
**$n$-ary Concatenation** involves repeatedly concatenating a language with itself $n$ times. 

Given a language $L$ and a non-negative integer $n$:
- $L^n$ represents the set of all strings formed by concatenating $L$ with itself $n$ times,
- If $n = 0$, $L^0$ is defined to be the set containing the empty word, $\{\epsilon\}$. 

Consider the language $L = \{a, b\}$:
- $L^1$ is just $L: \{a, b\}$
- $L^2$ is the set of all strings formed by concatenating $L$ with itself once: $\{aa, ab, ba, bb\}$ 
- $L^3$ is the set of all strings formed by concatenating $L$ with itself twice: $\{aaa, aab, aba, aba, abb, baa, bab, bba, bbb\}$

### Kleene Star
The **Kleene Star** is denoted as $L^*$, is an operation that allows for the creation of any number of concatenations of strings from a given language $L$. It includes the empty word, $\epsilon$, and can concatenate the language with itself zero or more times.

So pretty much in simple terms its a language that has done the **$n$-ary concatenation** but instead of a finite integer, $n$, it concatenates itself an infinite number of times.

$$L^* = \{ \epsilon, a, b, aa, ab, ba, bb, aaa, aab, aba, baa, bab, bba, bbb, ...\}$$

![[Pasted image 20250210173521.png#invert]]
- - - 
### Applying It:
![[Pasted image 20250210181155.png#invert]]
