22-05-2025 22:06

Tags: [[Data Science]]

# Naive Bayes

This is the most widely known and simplest **Bayesian classifier**.
The **"Naive"** assumption is that the features of the data point are **conditionally independent** given the class.

	example is that the word "free" is independent of the word "money" appearing in an email.

The assumption is rarely true in real life, but it helps simplify the calculations.

## Dimensionality

In [[Machine Learning|machine learning]] features are the individual measurable properties or characteristics of the phenomenon being observed, 
like if you were to have a house you could classify it as "expensive" or "affordable"
or,
if you were to classify emails between "spam" and "not spam".

**Dimensionality** refers to the **number of features** you have for each data point.

For each class we assume the data follows a normal distribution, using the sample mean and the sample standard deviation (**empirical values**).

## Multivariate Gaussian 

Simply remember that (univariate) Gaussian distribution is also just known as a "bell curve", it describes a single variable (like height or temperature) and has two parameters, the mean, $\mu$ and the variance, $\sigma^2$.

If you were to look at multiple together, you would end up with what is known as a **multivariate Gaussian** (or distribution), so instead of just looking at a person's height you might also be looking at their weight.

In order to define said distribution you need two things: 

1. Mean vector ($\mu$)
2. Covariance Matrix ($\Sigma$)

The mean tells you about the centre of the cloud of data and what the average value is.
The covariance matrix is a matrix of numbers that describes the **spread and orientation** of the data cloud.

**Validation sets** are used to choose the best variations of the learning model and optimise parameters.

### Underfitting | Overfitting | Balance

Underfitting happens when a model is too simple to capture the underlying patterns or relationships in the training data.


![[Pasted image 20250522233101.png#invert]]

## Affects of the Naive Assumption

So how does multivariate gaussian link to the assumptions made by naive Bayes? It is the fact that the parameter space is much reduced with naive Bayes, the $n$-dimensional space is turned into $d$ one-dimensional space.

But the problem is that **expressive power** is lost and there is an inability to represent relationships between variables.

