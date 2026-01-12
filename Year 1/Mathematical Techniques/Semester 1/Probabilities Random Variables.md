04-01-2025 14:59

Tags: [[Maths]]

# Random Variables

Random variables are functions that translate the elements of a sample space, that is possible outcomes from a random experiment, to real numbers. But this translation has to happen in such a way that we know what the probabilities for the resulting numbers are, and that requires a technical definition.

![[Pasted image 20250104150344.png#invert]]

The general idea is that we are translating outcomes into numbers: is a function that maps from the sample space of an experiment to real numbers.

Random variables come in two flavours, they can be ***discrete*** or ***continuous***.

![[Pasted image 20250104150924.png#invert]]

A random variable is discrete if its range is finite/countable and a random variable is continuous is everything but.

To describe how probabilities are distributed over the values of the random variable, we have probability distributions, for discrete random variables this is represented by ***PMF* = Probability Mass Function**, and for continuous random variables it is represented by ***PDF* = Probability Density Function**.


PMF, Denoted as $P(X = x)$, gives the probability that the random variable $X$ takes the value $x$. The some of all probabilities in a PMF is 1, ensuring that at least one of the possible values of the random variable occurs.

PDF, denoted as $f(x)$, gives the relative likelihood of the random variable $X$ taking on a value $x$. However, the value of the PDF at a specific point is not a probability; but rather the area under the curve over an interval represents the probability. The total area under the curve is 1.


## Discrete Random Variable 

This is one that can take on a countable number of possible values.

A **PMF** (Probability Mass Function) is a function that assigns a probability to each possible value of discrete random variable.
For a Discrete Random Variable $X$, the PMF function $P(X = x)$ such that:


1. $P(X = x) \ge 0$ for all $x$
2. ${\Sigma}_x ~P(X = x) = 1$   



## Continuous Random Variable

So this is for dealing with **uncountably infinite** outcomes.

We have something called the **PDF** - (probability density function). Which is used to describe the relative likelihood of a **continuous random variable** to take a specific value.

For a probability of a single value, the relative likelihood of any single value is 0: we don't look at single values rather we use the PDF to calculate values over intervals.

Imagine a smooth curve over the number line.

- The **area under the curve** between two points gives the **probability** that the random variable falls in that interval.
- The **total area** under the entire curve = **1** (since something has to happen).


Let $f(x)$ be a PDF for some random variable $x$:

1. $f(x)≥0$ for all xxx

2. The total area under the curve is 1:
    $\int_{-\infty}^{\infty} ~ f(x) \,~ dx = 1$

3. To find the probability that $X$ is in some range $a$ to $b$:
    $P(a \leq X \leq b) = \int_{a}^{b} f(x)~ dx$



## Cumulative Distribution Function

The **CDF** gives you the probability that a random variable is less than or equal a certain value.

Formally for a random variable $X$: $$f(X) = P(X \le x)$$
So the CDF tells you the accumulated probability from the left up to $x$.

Best way to think of the CDF is like a running total of the probability up to a certain point.


---

![[Pasted image 20250425110852.png#invert]]


## Expected Values and Comparing Functions

Expected values provides a measure of the centre or average of a random variable's possible outcomes, weighted by their probabilities.

![[Pasted image 20250111150710.png#invert]]

**Properties**:
![[Pasted image 20250111155300.png#invert]]
![[Pasted image 20250111161727.png#invert]]
The variance is a simple measure of how much the outcomes may differ from the expected value. 
![[Pasted image 20250111161737.png#invert]]
This is a variation of how we may measure the difference between outcomes and the expected value.

### Avoiding Infinite Sums
We can avoid infinite sums by using conditioning. The approach leverages the concept of conditional expectations.