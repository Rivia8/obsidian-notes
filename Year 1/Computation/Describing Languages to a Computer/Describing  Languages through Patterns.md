10-02-2025 19:40

Tags: [[Computation]]

# Describing Languages through Patterns

It is difficult for a computer to cope with something like:
$$ \{ (01)^n | n \in \mathbb{N} \} $$
We already know from looking at [[Defining New Languages from Old Ones]] that this can be expressed as $\{01\}^*$.

We already know that this language refers to a collection of strings that are comprised of 
"01's'" concatenated with each other.

But how would a computer understand this? 
What we would have to do is to create a ***pattern***.  We would need to make the notation of the language easy for the computer to understand: $\{ (01)^n | n \in \mathbb{N} \}$ -> $(01)^*$. 

That example was quite easy to produce a pattern for. But what about:

$$\{ 0^n \,\, |\,\, n \in \mathbb{N}\} \,\,\cup \,\, \{1^n\,\, | \,\, n\in \mathbb{N}\} = \{x^n \,\, | \,\, x = 0 \,\, or \,\, x=1\} $$

This shows a union of two sets, the first represents all strings consisting of only zeros of any natural number length and the second represents all strings consisting of only ones of any natural number length, but how do we present a pattern like the first example?

In essence we need to say 'or' in a way the computer will understand. How?

With **'|'**. So the example would translate to: $0^* \, | \, 1^*$ .

So far we have been using the idea of a pattern intuitively, we have not said how we can form patterns.

In order to do so we need to look at [[Regular Expressions]].

