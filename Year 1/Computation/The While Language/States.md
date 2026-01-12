15-03-2025 16:28

Tags: [[Computation]]

# States

## Describing States

What determines the values of arithmetic and Boolean expressions?:
- Variable Values

What does running a program do?:
- Changes the values of variables

The **state** refers to the collection of values stored in the variables at any given point during the program's execution.

In a program we have a finite number of variables, but we assume there is an **infinite set** (denoted as $Vars$) available. 


![[Pasted image 20250315170341.png#invert]]

The precise mathematical definition for this:
$$ f~ \sigma~:~Vars~ \rightarrow~ \mathbb{Z}$$
where $\sigma$ is the name of the states.

such that: $$\{x \in Vars~|~\sigma~x \ne 0\}$$is finite.

(There are a finite number of variables that are mentioned, so there are finite number of variables that are non-zero:)

We can have a shorthand notation to define a state (the values for variables):
$$\{x\mapsto3, y\mapsto4, z\mapsto{-1}\}$$
Where all the variables not mentioned have the value 0, so variables that are 0 are **not mentioned**.

--- 

We could have: 
$(\{ x\mapsto3, y\mapsto4, z\mapsto{-1} \})~y$ 
and since $y$ **has** been defined this would equal 4:
$(\{ x\mapsto3, y\mapsto4, z\mapsto{-1} \})~y = 4$ 

If we had:
$(\{ x\mapsto3, y\mapsto4, z\mapsto{-1} \})~w$
$w$ is not included so it would equal $0$:
$(\{ x\mapsto3, y\mapsto4, z\mapsto{-1} \})~w = 0$ 

- - - 

## Manipulating States

It is very important that for every variable that does appear only appears once.

As statements are carried out in a program, we expect the state to change.
We use: $$\sigma[x \mapsto n]$$
which means that given a state $\sigma$, a new state is defined where the variable $x$ has been updated to hold the value $n$.

![[Pasted image 20250315175814.png#invert]]
This means that, if the variable $y$ is equal to $x$, we obtain the updated value of $n$, if not then it remains the same.

- - -

Suppose we had the state: $$ \sigma = \{x\mapsto10,y\mapsto3\}$$
And we wanted to to update $x$ to hold $y$, the update notation would be: $$\sigma = \{x\mapsto3, y\mapsto3\}$$
This results in the state of: $$\sigma = \{x\mapsto3, y\mapsto3\}$$
- - -

We can do multiple updates with the notation: $$\sigma~[d\mapsto r, r\mapsto 1]$$
Key point to remember is that $\{x\mapsto1, x\mapsto2\}$ is not a valid state, and if you had an update like: $\sigma [x \mapsto 1, x \mapsto 2]$, the last update will stick and so will be: $\sigma [x\mapsto2]$.






