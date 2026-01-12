25-11-2024 12:09

Tags: [[Maths]] [[Maths Notes.pdf]]

# Probabilities: Simple Examples and Formal Definitions
This topic is explained thoroughly in the notes in section 4.1 .

## Coin Example with Trees

![[Pasted image 20241125122728.png#invert]]

If we were to find say the probability of getting Heads, Tails, Heads, we would trickle down the tree diagram, multiplying each branch:
$$\frac1{2} * \frac1{2} * \frac1{2} = \frac1{8}$$
Since the coin is fair and we are using such a simple example, the effect will be that each outcome will be the same no matter what: e.g. *TTT* = *HHH* etc.

If we wanted to find the probability that the same symbol occurs three times: *HHH* or *TTT* it would be:
$$ \frac1{8} + \frac1{8} = \frac1{4} $$
Which would mean the event: {*HHH, TTT*}.

## Counting 
When modelling situations with probability we often have to count how many possibilities there are, and how many of those have particular properties.

### Selection with return:
Assuming we are in a situation where there are *n* options to choose from, and that we may choose the same option as many times as we like. If we choose *i* many times and we record the choices in the order we made them, then there are: $$n^i$$
possible different outcomes.

![[Pasted image 20241125133847.png#invert]]
The reason it is called 'Selection with return' is that if we think of the choice being made by pulling different coloured balls from an urn (without being able to look into the urn), then one should picture this as drawing a ball, recording its colour before returning it to the urn, drawing a second ball, recording its colour before returning it, and so on.

### Selection without return:
If we have a choice of *n* possibilities, and we choose *i* times in a row, but we may not choose the same item twice, then there are:
![[Pasted image 20241125134545.png#invert]]
different combinations.

## Ordering

### Selection with Ordering
If we have *n* different items, then there are *n!* many ways of ordering them, that is, of writing them one after another. This is the same as choosing without return *n* times from *n* possible options. If the items are not all different then the number of visibly, different possibilities is smaller.
![[Pasted image 20241125135343.png#invert]]
Explanation:
- We have 5 mugs: 1 red, 1 blue and 3 black
- If all mugs were different, we could arrange them in 5! ways, which is $5 * 4 * 3 * 2 * 1 = 120$ ways.
- Since there are 3 black mugs that are the same, swapping them does not create a new arrangement, so it would be 120 if all 5 mugs were unique, but since three are indistinguishable from each other, swapping them would make no difference.
- So it would actually be: $$\frac{5!}{3!} = \frac{120}{6} = 20$$
The general formula of unique arrangements would follow as:
![[Pasted image 20241125142638.png#invert]]
### Selection without ordering:
Sometimes we are confronted with the situation where we have to count how many different selections there are, but where we are not told the order in which the selection arises.  
A typical example is a lottery draw:
One way of counting these is to list all the options, but that gets cumbersome if the numbers involved are bigger. A different way is to count how many selections there are with ordering being taken into account, and then dividing by the number of different orderings there are for each choice.
If we look at the ice cream scoop example once again:

Imagine you have three flavours of ice cream: Vanilla (V), Chocolate (C), and Strawberry (S). You want to pick two scoops, but the order doesn't matter (so picking Vanilla and Chocolate is the same as picking Chocolate and Vanilla).

1. **List All Combinations with Order:**
    - Vanilla and Chocolate: VC, CV
    - Vanilla and Strawberry: VS, SV
    - Chocolate and Strawberry: CS, SC
    So, there are 6 combinations if we consider the order.
2. **Remove Duplicate Combinations:**
    - VC and CV are the same.
    - VS and SV are the same.
    - CS and SC are the same.
    We end up with 3 unique combinations: VC, VS, CS.

The formula to calculate the number of ways to choose *i* items from *n* different ones without considering the order is as follows:
![[Pasted image 20241127123807.png#invert]]

## Summary:
A table with the formulae summarised:
![[Pasted image 20241127124113.png#invert]]

# Axioms of Probability (NON-EXAMINABLE)
**Axiom:**
	An axiom is a basic principle or statement that is accepted without proof. It serves as a starting point for further reasoning and arguments. In mathematics and logic, axioms are foundational building blocks, from which other truths are derived, 

The idea underlying probability theory is that we often find ourselves in a situation where we can work with
- A sample space *S* of all possible outcomes,
- A set of events *ℰ* (which is a subset of the powerset of *S*),
- A probability distribution which is given by a function:
	- 𝑃 : ℰ -> \[0, 1]\,
	- Where \[0, 1]\, is the interval of real numbers from 0 to 1.  

![[Pasted image 20241127131405.png#invert]]
![[Pasted image 20241127131819.png#invert]]


# Probability Space: Discrete Case:
![[Pasted image 20241207193303.png#invert]]
In order to specify a probability space we have to say what the outcomes are, which sets of outcomes are events, and we have to give a probability for each event. These have to satisfy rules to ensure we can calculate with probabilities as we expect.

## Explanation:
A probability space is a way to look at all possible outcomes and their probabilities. 
1. **Sample Set(`S`)** : This is just the list of all possible outcomes. For example, if you're rolling a six-sided die, the sample set is {1,2,3,4,5,6}
2. **Set of Events (`E`)**: These are groups of outcomes that we care about. For instance, rolling an even number is an event, and in our die example, the set of events for this would be {2,4,6}
3. **Probability Distributions (`P)`)**: This tells us how likely each event is. For example, if each die roll is equal likely, the probability of each number is 1/6.

Rules:
- The probability of something happening must be between 0 and 1.
- The probability of the whole sample set (like getting any number when rolling a die) is 1.
- If you have events that can't happen at the same time (like rolling a 2 and a 4 in one roll), the probability of either happening is the sum of their individual probabilities.
