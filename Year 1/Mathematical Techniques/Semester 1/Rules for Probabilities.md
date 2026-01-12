25-12-2024 17:33

Status: #new

Tags: [[Maths]] 

# Rules for Probabilities

![[Pasted image 20241225173552.png#invert]]

1. *P(S) = 1*
- This means the probability of the entire sample space *S* is 1. In other words, something is guaranteed to happen from the set of all possible outcomes

2. *P(Φ) = 0*
- The probability of the empty set (an event that cannot happen) is 0. This represents the fact that it is impossible for an event that does not exist to occur.

3. $P(S∖A)=1 - P(A):$ 
- This rule tells us that the probability of the complement of event A (all outcomes not in A) is equal to 1 minus the probability of A. It is a way to understand probabilities in terms of what doesn't happen.

4. $P(A∖B) = P(A) - P(A \cap B)$ 
- The probability of A occurring but not B is the probability of A minus the probability of both A and B happening together. This isolates the part of A that does not include B.

5. $P(A∪B)= P(A) + P(B) - P(A \cap B):$
- The probability of either event A or event B happening (or both) is the sum of the probabilities of A and B, minus the probability of both A and B happening simultaneously, since we have counted that part twice.

6. $A\subseteq B$ **implies** $P(A)\leq P(B)$  
- If event A is a subset of event B (meaning A is entirely contained within B), the probability of A happening is less than or equal to the probability of B happening. This makes sense because everything that can happen in A can also happen in B.