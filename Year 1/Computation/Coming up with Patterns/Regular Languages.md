26-02-2025 19:42

Tags: [[Computation]]

# Regular Languages

We have already looked at defining [[Regular Expressions#Regular Languages|Regular Languages]] before but not fully delved into it.
We have also looked at defining [[Defining New Languages from Old Ones|new languages from old ones]].  

The set of Regular Languages is closed under Union, Concatenation and Kleene Star. This means that performing these operations on them always results in another regular language. *Remember that a language is regular if it can be described by a regular expression.*

Assume we have the language $L_1$ and $L_2$, and they have the patterns $p_1$ and $p_2$, for these languages we already know how to do concatenation ($L(p_1p_2$)), Kleene star and the Complement.
## Reversal

If $s$ is a word over some alphabet $\Sigma$ then we can construct another word over the same alphabet by reading $s$ backwards - so reversing it.

### Definition 20

![[Pasted image 20250226232302.png#invert]]

## Union

If we have the regular expressions for $L_1$ and $L_2$, say $p_1$ and $p_2$ it is easy to do the union since it would just be $p_1|p_2$. 

## Intersection

This one isn't so easy, since we need to check the word twice by two automata but how do we do that as automata 'consume' the word as you progress.

![[Pasted image 20250226233432.png#invert]]
We call the result the **product of the two automata.**

To produce the automata, you make pairs with the states, the accepting state will be the pair that has includes both accepting states. You then connect the states based on the original automata.

e.g.:

![[Pasted image 20250226235100.png#invert]]

![[Pasted image 20250226235117.png#invert]]
