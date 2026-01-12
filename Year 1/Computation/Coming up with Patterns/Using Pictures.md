20-02-2025 12:49

Tags: [[Computation]]

# Pictures

Coming up with patterns that describes a particular language can be quite difficult, you have to develop an intuition about how to think of the words in the desired language, and turn that into a characteristic for a pattern to be created.

## Example

Let's say we have the example of identifying words with an even number of $0$'s.
We could track the number of $0$'s and report back whether the number of them is odd or even, but we do not need to do that:
Instead, we could define that we have **two states**, where we have an even number of $0$'s and an odd number of $0$'s and when we see an $a$ we can swap between the two states.

We could produce a picture for this description that would look like this:

![[Pasted image 20250220130108.png#invert]]
So evert time we see a $0$ we switch from the 'even' state to the 'odd' state and *vice versa*.

We can also include seeing anything **other** than a $0$, like for an example $1$:

![[Pasted image 20250220130323.png#invert]]
If you look we have also abbreviated their names to make it look nicer.

But where do we start? Did we start with an odd number or even number of $0$'s.
We indicate this by having an arrow pointing towards the state where we should start in:

![[Pasted image 20250220130546.png#invert]]
Then we can mark the criteria we are looking for with an inner circle:

![[Pasted image 20250220132822.png#invert]]
The circle with an inner circle can be classified as an **accepted** state.

This diagram is what is known as a **[[Deterministic Finite-State Automata]]**.

