21-04-2025 13:46

Tags: [[Data Science]]

# Probability Distributions

We have two forms of [[Probabilities Random Variables|Random Variables]]:

**Discrete:** This is used when you are dealing with countable incomes, thinks that can be listed or numbered.

**Continuous:** This is used when you're dealing with **uncountably** **infinite** outcomes, usually within a range or interval, e.g. height of people.
## Probability Theory

**Probability Theory:** This is a branch of mathematics that studies uncertainty and randomness - it provides a framework to model uncertain situations, make predictions and analyse outcomes.

We have some basic terminology:

1. **Experiment:** An action/process that leads to one or more outcomes.
2. **Sample Space**: the set of all possible outcomes of an experiment: $\Omega = \{1,2,3,4,5,6\}$ 
3. **Event**: A subset of a sample space: Rolling an even number $\rightarrow E = \{2,4,6\}$ 

### Conditional Probability and Bayesian Statistics

**Conditional Probability**: $A$ given $B$ is written as $P(A|B)$.

And this can be reduced to a formula:

$$P(A|B) = \frac{P(A\cap B)}{P(B)}$$ These formulas are used extensively in [[Probabilities Bayesian Updating|Bayes' Statistics]].

## Subjective and Objective Probability

**Objective**: 
This applies to repeatable events like dice rolls, coin flips etc. 
This is based on facts, measurements or logical reason and is independent to personal belief.

**Subjective:**
This assigns probability to unrepeatable events, it is based on personal belief and judgement about how likely something is, especially when hard data is missing:
- "I feel there is an 90% chance my team will tomorrow"
This type of probability is used in Bayesian data.

| Feature                  | Objective Probability               | Subjective Probability                           |
| ------------------------ | ----------------------------------- | ------------------------------------------------ |
| Based on                 | Facts, experiments, logic           | Personal belief                                  |
| Agreement between people | Generally yes                       | Can differ widely                                |
| Examples                 | Dice roll, coin toss, rainfall data | Belief about winning a match, political outcomes |

## Central Limit Theorem

This is an important idea in probability and statistics.
It says:
***If you take a large number of random samples from any population (no matter what the original shape is) then the distribution will be approximately normal***

So in simple terms, the average of many random samples will behave like a **Normal** or **Gaussian** distribution.

In order to show how this works, you'd have a distribution, let's say a **uniform** distribution. You choose a sample size $n$ and take many samples and calculate the means of the samples. You then plot a histogram, and even though the samples were pulled from a flat distribution, a bell-curve histogram will be produced.

The central limit theorem (CLT) holds that as a sample size gets larger, **its mean will increasingly approximate the mean in a normal distribution**.

![[Pasted image 20250425113642.png#invert]]

CLT does not apply to distributions with **infinite** **means** or **variances**.
This is because the CLT assumes that the random variable we are sampling from has:
- A **finite mean**, μ
- A **finite variance**, $\sigma^2$ 

### What is required for it to apply.

1. **Independent** and **Identically distributed** samples - each observation must be independent of the others, the outcome of one observation should not influence the other. All samples must also be drawn from the same defined population.
2. **Sufficiently Large Sample Size:** a common rule of thumb is to have $n \ge 30$ but there is not "magic" number.
3. **Finite Population Variance:** The population from which you are sampling must have a **finite** variance.


