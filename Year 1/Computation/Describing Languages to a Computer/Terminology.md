10-02-2025 19:32

Status:

Tags: [[Computation]]

# Describing Languages to a Computer

In order to solve the problems posed, we need to describe to the computer what it is looking for.
In only very simple cases it will be just one or two strings - in general we would want the computer to look for a much larger collection of words.

## Terminology

We have to introduce a few terms so that we can talk about the various concepts involved.

### Symbol
This is a building block for a string. Symbols cannot be sub-divided, they are essentially the atoms of everything we build.
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

