22-05-2025 18:28

Tags: [[Data Science]]

# MLE

This is **not** a [[Bayesian Principles|Bayesian]] method and is a **frequentist** method and so uses objective methods and not the subjective approach that the Bayesian method incorporates. 

MLE is a statistical technique for estimating the parameters of a hypothesised statistical model. It selects the parameter value that make the observed data **most probable** under the assumed model.

The process:
1. You **assume a model**, whereby you assume the data comes from a specific distribution model,
2. Then you define the likelihood function, 
3. You then change the parameters to make the likelihood as big as possible between 0 and 1. This is usually done by calculus, finding the derivative of the function and finding the peak).

The likelihood function is often denoted as: $L(\theta|data)$ it represents the probability of observing your particular dataset, given a specific set of model parameters ($\theta$).


