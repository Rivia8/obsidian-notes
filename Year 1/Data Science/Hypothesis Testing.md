21-05-2025 20:33

Tags: [[Data Science]]

# Hypothesis Testing

Hypothesis testing is fundamental to inferential statistics (allows us to use statistical methods to make decisions about real-life problems).

With hypothesis testing, if we have an alternative hypothesis, $H_1$ we also need $H_0$ - our null hypothesis.

## Null hypothesis, $H_0$ 

The hypothesis that states there is **no** difference between the two variables.
The two datasets come from the same distribution.

We don't **accept** the null hypothesis, we **"fail to reject"** it when the p-value collected is greater than the **significance level:**
$$p > \alpha$$
When we say the same distribution it means that the samples are from the same underlying probability distribution and so have the same mean, variance or shape (depends on the test).
## Alternative Hypothesis, $H_1$

The difference is real.
The two datasets come from different distributions.

We **reject** the null hypothesis when the p-value collected is less than that of the **significance level**: 
$$p<\alpha$$
this makes the result **significant**.

## Test Types

Different tests will discover different things when it comes to hypothesis tests:

|Test|Null Hypothesis (H₀)|Alternative (H₁)|
|---|---|---|
|t-test|Same mean (→ same distribution mean)|Different mean|
|ANOVA|All group means are equal|At least one differs|
|KS test|Same overall distribution|Distributions differ in shape/position|
|Chi-squared|Observed ≈ expected frequencies|Significant difference in frequencies|
## Critical Value and Significance Value

The critical value is the result that has the value of it occurring equal to the significance value, $\alpha$. 

The significance value is the **threshold** we set on a hypothesis to decide how much evidence is needed to reject the null hypothesis. 
It is set before, usual values being 0.05, 0.1, 0.15...

## P-Value

The p-value is the probability of observing your data, assuming the null hypothesis is true.

*Difficult concept to understand*

If the p-value is very small, the observed data is **very unlikely** under the null hypothesis - it does not match what we'd expect.
If the p-value is large, it is quite **likely** to be under the null.


## Z-Test

The z-test is a statistical test using the normal distribution and where the null distribution is a normal distribution.
It is used to determine whether a sample mean is significantly different from a known population mean when the population standard deviation is known.

$$ Z = \frac{\bar{x}-\mu}{\sigma}$$
We use the test when:
- The population standard deviation is known, $\sigma$.
- The data is normally distributed ($n$ is large).

If a pattern follows the binomial distribution we must use the **normal approximation** to convert it to the normal distribution.

The problems with Z-tests are that they rely on normal approximations which are not valid for small sample sizes.
If n<30, the sampling distribution may not be normal and you'll need to use a t-test. 

### Normal Approximation

Mean: $$\mu = np$$
Standard deviation: $$\sigma = \sqrt{np(1-p)}$$
If you are doing a z-test, you then calculate the **z-score** with the function:
$$ Z = \frac{\bar{x}-\mu}{\frac{\sigma}{\sqrt{n}}}$$
*(We use the SEM for sample means).*
And then find the probability.

This formula allows the data we have to be standardised so that we can compare it on a common scale: $Z\sim N(0,1^2)$

## T-Test

- For this type of test we have a parameter called the **degree of freedom** or **df / DOF**
- DOF can be seen as: (number of data points) - (number of means):
Which is usually:
$$ df = n - 1$$
- A t-test is used to compare means when the population standard deviation $\sigma$ is unknown


--- 

### T-test vs Z-test

| Feature                  | **t-test**               | **z-test**                   |
| ------------------------ | ------------------------ | ---------------------------- |
| Population SD known?     | ❌ No                     | ✅ Yes                        |
| Sample size small (<30)? | ✅ Yes — preferred        | 🚫 Not reliable              |
| Distribution assumption  | Approx. normal           | Normal or large n (CLT)      |
| Uses which distribution? | Student’s t-distribution | Standard normal distribution |
