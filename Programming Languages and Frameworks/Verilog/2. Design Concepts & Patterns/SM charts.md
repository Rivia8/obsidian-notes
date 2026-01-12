19-10-2025 19:11

Tags: [[Verilog]]

# SM charts

When we are designing [[Year 1/Computer Engineering/Sequential Systems|sequential systems]] we need to produce a state transition diagram, however they can often get cluttered very easily when there are many inputs/outputs in the systems or there are a large number of states.
It can sometimes be unintuitive to look at so instead we use **SM Charts.**

## Components

1. State Box
![[Pasted image 20251019191340.png#invert|600]]

Like in a state transition diagram we move from one state to the next, it has an entry path and an exit path where the exit path can lead to a number of exits.
Each state box needs to have a unique state name.

2. Decision Box
![[Pasted image 20251019191539.png#invert|600]]
This is where we make decisions, using input signals, as to the path to the next state.
It has one input and two outputs.
It can lead to more decision boxes or conditional output boxes.

3. Conditional Output Box
![[Pasted image 20251019191650.png#invert|600]]
This is used to identify outputs that only go active when a conditional decision has been met. It has one input and one output.
**Whether a condition is satisfied or not is determined by a decision box, so they must always follows after a decision box.**

If a SM chart has a Conditional Output Box then it is a Mealy Machine, if it doesn't then its a Moore machine:
<mark class="hltr-blue">Remember from the explanation of [[Synchronous Paradigm|Moore and Mealy Machines]], if you then have an **Conditional Output Box** which then also requires a **Decision Box** its the same as your outputs depending on the current **inputs** *as well as* the current states, in other words a Mealy Machine.</mark>


## The SM Block

![[Pasted image 20251019215328.png#invert|600]]

The SM block describes the operation when in a particular state.
It encapsulates the behaviour when in a particular state, each state has one state box but can have any number of decision boxes and conditional output boxes.
There may be many multiple outputs from the SM block (state) to other states.

The best way to think about this is to understand that an SM block is the name for the **entire group of boxes** which associate to a single state.
SM Blocks have concurrent evaluation, meaning the inputs are fed into the circuit at the same time.

## Examples:

1. 
![[Pasted image 20251019220748.png#invert|800]]

These two implement the exact same logic.

2. 
![[Pasted image 20251019220839.png#invert|400]]
This is a very simple counter.


## Link Path Extraction

This refers to following the path of a signal and seeing what conditions are required to get to that:
![[Pasted image 20251019221110.png#invert|800]]

As you can see to get to from A to B, $A \rightarrow B$, we need to have a false $X$ and false $Y$, $\bar{X} \bar{Y}$.


## Serial and Parallel Designs

• Serial structure … one path only to the next state
• Parallel structure … many link paths but only one next state

![[Pasted image 20251019221404.png#invert|600]]

This would be invalid for something like a flow chart since you cannot move down through multiple 'flows' in a flowchart.
