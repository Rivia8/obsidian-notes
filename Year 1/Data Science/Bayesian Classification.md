22-05-2025 21:10

Tags: [[Data Science]]

# Bayesian Classification

**Bayesian classification** is a powerful approach that leverages the principles of probability to classify data points into different categories.

Instead of simply outputting a class label, e.g. this is cat, a Bayesian classifier aims to calculate the probability that a data point belongs to each possible class.

For Bayesian classification, we find the posterior probability of each class given the observed data point.
$$ P(C = c_k|X) = \frac{P(X|C=c_k) \cdot P(C=c_k))}{P(X)} $$
Here in this case the **prior** is the initial belief about the probability of different classes before seeing the data.
This is often estimated from the overall frequency of each class in the training data.

There are two common ways to set the prior:

1. If all classes are equally likely (**balanced**), you use $P(c_k) = 1/K$ which is **uniform prior**.
2. If the classes are **imbalanced**, $P(C = C_k = {N_k}/{N}$. This is called **class size prior,** where $N_k$ is the number of training examples of class $c_k$. $N$ is the total number of training examples across all classes.

$P(X|C=c_k)$
This is the likelihood of the data given the class.
This is where the model learns the patterns associated with each class from the training data. Estimating this can be complex, especially if $X$ has many features so we have different Bayesian classification algorithms like [[Naive Bayes]]
