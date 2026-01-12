20-05-2025 20:56

Tags: [[Data Science]]

# Introduction to Uncertainty 

Uncertainty refers to how reliable, precise or incomplete data or its interpretation is. 
You can never have perfect data so quantifying **how** imperfect it is is useful.

# Uncertainty
## Types of Uncertainty

- **Predictable Randomness** (Epistemic Uncertainty): Can be reduced by taking more measurements (reducible).
- **Intrinsic Uncertainty** (Aleatoric Uncertainty): Inherent randomness in the system or data (cannot be reduced with data).
- **Unknown Unknowns** (Ontologic Uncertainty): The model is incomplete or incorrect, or when we are unaware of factors affecting the system.

## Standard Deviation

[[Standard Deviation]] is a good measure of variability/spread in the data:
It provides uncertainties for:
- Individual Measurements in a dataset,
- The range of uncertainty over the entire data set.

## Properties to Events

**Deterministic:** This means the process has no randomness - if you know the inputs you know the output.

**Random:** Like the name implies a random variable or event is unpredictable in the short term. Each outcome is governed by chance, often described by a probability distribution.

**Stochastic:** A stochastic behaviour has some random components; but can be largely the same with some variability. It usually is a system that evolves over time with inherent randomness.

|Term|Predictable?|Has randomness?|Used in...|
|---|---|---|---|
|Deterministic|✅ Yes|❌ No|Physics, classical mechanics|
|Random|❌ No|✅ Yes|Dice, coin flips, RNG|
|Stochastic|⛔ Partially|✅ Yes (modeled)|Finance, weather, AI, biology|

### Accuracy and Precision

**Accuracy** is the degree to which values are arranged around the true value.
**Precision** is the degree to which values are close to each other, high repeatability. 

![[Pasted image 20250521102042.png#invert]]

**Bias** is the **lack** of accuracy and is also known as systematic errors.
Systematic errors are reproducible, consistent errors in the same direction. Often due to faulty instruments, bad calibration or flawed assumptions in a model.

**Variability** is the lack of precision.



