22-05-2025 18:55

Tags: [[Data Science]]

# Machine Learning

**Machine learning** is considered a different approach to collecting an output from a computer.
You give an algorithm lots of data and it 'learns' from it - it looks at the data and finds patterns in within it. It then makes predictions and decisions once you give it a prompt to go off.

## Learning Paradigms

There are three dominant learning paradigms:

- Supervised Learning,
- Reinforcement learning,
- Unsupervised learning.

### Supervised Learning

This is learning from labelled examples, a ground truth the machine works with.
There is a dataset where each piece of input data comes with the correct output or "label". The algorithm's goal is to learn a mapping from the input data to correct output label. It then tries to predict the label for new, unseen data based on the patterns it learned from the labelled examples.

### Reinforcement learning

An **agent** learns how to behave in an environment by performing actions and receiving rewards or penalties (classical conditioning).
The agent's goal is to learn a policy (the actions it must take) to maximise the *total cumulative reward* it can receive. The agent learns purely through exploration, there is no labelled data.

### Unsupervised

Algorithms learn patterns from unlabelled data. It works with input data only and identifies hidden structures or clusters.
The goal for the algorithm is to explore the data and find hidden patterns, structures, relationships, or groupings on its own.


## Problem Types

There are two main problem types that the algorithm tries to overcome:

1. Classification, 
2. Regression.

### Classification

The goal is to assign the input data to a specific category or label. It predicts discrete values i.e. whether an image contains a cat or a dog.

### Regression

This predicts a continuous value based on input data, such as estimating house prices, temperature, or sensor value. The output is a numerical value, not a fixed category.

## Train and Test sets

The model requires data in order to **learn**.
It has a **training set** that is data used to **train** the model.
It also has the **testing set** which is data set aside to evaluate the model's performance. 

## Measures of performance

For **classification** in order to measure performance we have:

**Classification accuracy**: number or the percent of examples correctly classified,
**Miscalculation error:** number or percent of examples incorrectly classified.

For **regression** we have:
The **Mean Squared Error (MSE)** which measures the average squared difference between the predicted and actual values,



