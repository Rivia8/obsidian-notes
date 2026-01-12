10-02-2025 22:41

Tags: [[Computation]]

# Regular Expressions

Here we are going to look at how exactly we can form patterns and properly define when a word matches a pattern.

![[Pasted image 20250210230031.png#invert]]
So like we have seen in [[Describing  Languages through Patterns]] we can define patterns with **regular expressions.** 

So looking at **Definition 1** we can see that the operators are quite limited, in the sense that it doesn't include things like: '?' and '+'. The reason why is purely the face that we do not need it. Keeping the language as simple as possible is the best thing we can do.

## Matching Regular Expressions

![[Pasted image 20250211112444.png#invert]]

**Definition 2** explains what it means to match a pattern. 

In order for simplicity it is best to understand that pattern matching is essentially just having a word and seeing if it fits to a pattern.
Let's look at an example:

For the alphabet:
$$ \Sigma = \, \{a,b,c\}$$
We have pattern:
$$a(ba)^*$$
Now let's look at some words to see if matches the pattern:
$$aba$$
Looking at $aba$ we can split the $a$ from the $ba$, $a \, ba$, and we can see that it does indeed match the pattern since the pattern dictates that it is $a$ concatenated with any number of $ba$'s.

Let's look at the word: $$aaa$$
Once again we will split the word to match the format of the pattern, $a \, aa$, we can see the first part does indeed match the pattern. But now, looking at the second part $aa$, we can see that it **does not** match the pattern as it is not following the criteria of $(ba)^*$, ($a$ followed by any number of $ba$'s).

(*watch the the third video titled 'Regular Expressions' for more examples *)

## The Language Described the Regular Expression

![[Pasted image 20250213153726.png#invert]]

Looking at the definition, we can see that $p$, a regular expression, describes a set of words (strings) over an alphabet $\Sigma$. Where $L(p)$ is the set of all possible words over $\Sigma$ that match the pattern described by the regular expression $p$. $\Sigma^*$ represents the set of all possible words that can be formed using the alphabet $\Sigma$.

So …
The part $L(p) = \{s \, \, \in \, \, \Sigma^* \,\, | \,\, s \,\, matches \,\, p \}$, means that a language defined by the regular expression is any word that belongs any of the words possible to be made by the alphabet such that it matches the regular expression!

## Regular Languages

Now we have defined a category of language, the category of language that is defined by regular expressions, hence, **regular languages**.

![[Pasted image 20250213161042.png#invert]]
![[Pasted image 20250213161127.png#invert]]

Remember that given the language to be **finite** you can always find a regular expression to define it, meaning it is always regular language. The reason for this is because you could just define a regular expression that just lists the entire language as an expression:

For the language: $$\{W_1, W_2, W_3,... W_n \}$$
We could have the regular expression: $$(W_1|W_2|W_3|...|W_n)$$
Therefore any arbitrary finite language will be regular.