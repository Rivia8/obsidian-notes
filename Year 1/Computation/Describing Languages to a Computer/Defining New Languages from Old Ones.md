10-02-2025 19:32

Tags: [[Computation]]

# Defining Languages

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
- $\Sigma^*$ = {ϵ, a, b, aa, ab, bb, ba,…} (all possible strings over {a, b})
- $L'$ = {ϵ, a, b, aa, bb, ba,...} (all possible values except those in $L$)

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
#### How the Kleene Star Works
For Languages that are represented like:
$$\{0\}^*\{1\}^*$$
It would mean that it would contain all possible strings that start with any number of '0's followed by any number of '1's, so '010' would not be included nor would '10'.

- - - 
### Applying It:
![[Pasted image 20250210181155.png#invert]]
