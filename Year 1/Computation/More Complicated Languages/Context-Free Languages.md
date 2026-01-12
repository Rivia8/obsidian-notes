28-02-2025 15:32

Tags: [[Computation]]

# Context-Free Languages

For [[Regular Languages|regular languages]] we have seen how we can build new ones from old ones and how you can do this by any way like unions, intersections and complements but for CFGs it can be more difficult.

## Concatenation

Let's assume we have two grammars, $G_1$ and $G_2$. 
$G1$ 
$S_1 \rightarrow aT_1$
$T_1 \rightarrow aT_1 ~|~ bT_1 ~|~ cT_1 ~|~ \epsilon$ 

$G2$ 
$S_2 \rightarrow T_2b$
$T_1 \rightarrow aT_2 ~|~ bT_2 ~|~ cT_2 ~|~ \epsilon$ 

First add subscripts 1 and 2 to the non-terminals (they have already been done so) to distinguish the two grammars from each other.

Now we add a new start symbol:

$$S \rightarrow S_1S_2$$ 

Here we have simply provided a procedure for concatenation for the two grammars since $S_1$ will follow the derivation of its grammar and the same for $S_2$.

## Union

For union we would do the same start procedure by doing the renaming,

$G1$ 
$S_1 \rightarrow aT_1$
$T_1 \rightarrow aT_1 ~|~ bT_1 ~|~ cT_1 ~|~ \epsilon$ 

$G2$ 
$S_2 \rightarrow T_2b$
$T_1 \rightarrow aT_2 ~|~ bT_2 ~|~ cT_2 ~|~ \epsilon$ 

And we have the new start symbol of:

$$S \rightarrow S_1 ~|~ S_2$$

## Kleene Star

This is also relatively simple:

If we would like to generate a word that is $n$-fold concatenation of words, we would add the production rule:

$$S \rightarrow SS ~|~ \epsilon$$
Where you can change the $S$ into $S \rightarrow SS$ $n$ times and stop by making it an $\epsilon$.

## Reversal

For this take each production rule and replace the string on the right by its reverse.
If we had: $$ S \rightarrow aTbC$$
It would be replaced with the rule: $$S \rightarrow cbTc $$
And you would replace any of the $T$ production rules with the reverse.

