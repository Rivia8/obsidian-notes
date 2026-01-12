28-02-2025 14:46

Tags: [[Computation]]

# Parsing and Ambiguity

When a compiler deals with a piece of code it has to *parse* it. Parsing is the reversal of the process of grammar derivation (in grammar derivation we take the start symbol of the grammar and apply rules to produce a string).
Instead of finding a derivation it is often more meaningful to create a **parse tree** which gives a better overview of how the various bits fit together.

![[Pasted image 20250228150418.png#invert]]

The reason we use parse trees is because it eliminates the troubles you have with derivations having different orders to get to the same string.

But you can also have **ambiguous** grammars:
![[Pasted image 20250228151540.png#invert]]

As you can see there are two different parse trees for the same word, we call this **ambiguously generated**.

![[Pasted image 20250228151806.png#invert]]

The problem with ambiguity is that it will result in the same string being processed in different ways, like the example above, $5 \times 3 - 4$ can be expressed as $(5 \times 3) - 4 = 11$ or $5 \times (3 - 4)=-5$.

In order to prevent this we may need to rewrite the grammar to prevent ambiguity.

