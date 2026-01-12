27-02-2025 20:07

Tags: [[Computation]]

# Limitations of Regular Languages

Regular languages is a language that matches a pattern.

We have described these patterns with:
- Regular expressions
- DFAs
- NFAs
- NFAs+$\epsilon$ 

The thing is a non-regular language can also be expressed with these devices.

Let's look at an example:
$$ L_1 = \{a^nb^n~|~n \in \mathbb N \}$$ 
This language is **not** regular. This is because firstly, the language can go infinitely, our automatons however, cannot count something infinitely since they have a finite number of states, sort of.
Another example: $$L_2 = \{(01)^n~|~n\in \mathbb N\}$$
$L_2$ can be expressed by an automata. The reason for this is the fact that $L_2$ can be handled with a fixed number states by simply alternating between them whereas $L_1$ requires you to count how many $a$'s there are and then count the same amount of $b$'s but that requires you an infinite number of states given the infinite nature of the input.

The [[Pumping Lemma|pumping lemma]] for regular languages helps 