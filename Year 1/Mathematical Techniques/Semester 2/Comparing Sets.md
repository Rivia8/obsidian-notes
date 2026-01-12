02-02-2025 19:01

Status: #new

Tags: [[Maths]]

# Comparing Sets

## Comparative Sizes of Sets
Remember that an **injunctive function** is a function that from a set $S$ to a set $T$ is a function where each element $S$ is mapped to a unique element in $T$. No two elements in $S$ map to the same element in $T$ - no two elements in $S$ map to the same element in $T$.

In terms of **size** this means that set $S$ must be less than or equal to the size of set $T$ for every element of set $S$ to map to a unique element in $T$.

![[Pasted image 20250202191151.png#invert]]
### Looking at the Infinite Set Example
#### Natural Numbers to Integers
Set $N$: So we first have the set $N$ which includes all positive whole numbers - 0, 1, 2, 3, and so on.
Set $Z$: This set includes all whole numbers, both positive and negative - … , -3, -2, -1, 0, 1, 2, 3 and so on

We can define a function $f$ that maps each natural number to $n$ itself, so $f(n) = n$ which means that each element in $N$ is matched to a unique element in $Z$. Hence, the size of $N$ is less than or equal to the size of $Z$.

#### Integers to Natural Numbers
We can also find the injective function for the reverse process.
Let's define a function that:
![[Pasted image 20250202201739.png#invert]]

- if $n \ge 0: f(n) =2n$ 
- if $n<0: f(n) = - (2n+1)$
![[Pasted image 20250202204518.png#invert]]

To show that this is injective, we show that $f(m) = f(n)$ to imply that $m = n$   

![[Pasted image 20250202201954.png#invert]]

## Two Sets having the Same Size
What does it mean when two sets are considered to have the same size?

![[Pasted image 20250202203428.png#invert]]

The example before shows us an instance where two sets have the same size. 
If we can fine an injective function from set $S$ to set $T$, and from set $T$ to set $S$ (like the previous example) we say that they have the same size.
Often when trying to compare infinite sets, we often need to use two different functions to show they have the same size.

### Example of Infinite Sets
- Set $N$ (Natural Numbers): 0, 1, 2, 3, 4, 5 …
- Set ($e$) (Even Numbers):: 0, 2, 4, 6,

For every even number $e$, we can map it to a natural number $N$:
$$g(e) = \frac{e}{2}$$
and, for every natural number $N$ we can map it to an even number $e$:
$$f(N) = 2N$$
This demonstrates bijection since no two different even numbers will map to the same natural number (injection) and every natural number is covered.

The important takeaway is that bijections shows that two sets have the same size, even if they are infinite.

## Infinite Sets

![[Pasted image 20250202223535.png#invert]]
For finite sets, an injection from the set to itself uses the entire set. However, with infinite sets, we can find injective functions from the set to a subset of itself, which is not possible with finite sets.

With infinite sets we use **injections to map elements uniquely, both ways, to show same size.**
By finding injective functions both ways, we prove that two infinite sets have the same size, even if it does not seem intuitive.

## Countable and Uncountable Sets

![[Pasted image 20250202234218.png#invert]]

A set is countable if its elements can be matched one-to-one with the set of natural numbers (injective with $N$). This means that essentially we can 'list' the elements of the set in a sequence, even if the set is infinite.

A set is uncountable if it is not possible to match its elements one-to-one with the set of natural numbers $(N$). This means that the set is too large to be listed in a sequence, even if the set is infinite.