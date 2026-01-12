15-02-2025 18:27

Tags: [[Data Science]]

# Measures of Spread

Glossary of Notation:
![[Pasted image 20250215182903.png#invert]]

When looking at measures of spread, you look at the degree of:

- Scatter
- Dispersion
- Variability

This helps us understand whether the data points are clustered together or widely dispersed.

**Robustness:** A measure is considered robust if it less affected by outliers, extreme values, and other anomalies.

**Definition of 'Measures of Spread':** Quantifies how much the data points in a dataset vary or are distributed around a central value (such as the mean, media or mode),

![[Pasted image 20250215183142.png#invert]]

## Measures of Spread:

1. Range,
2. Variance, 
3. Standard Deviation,
4. Mean Absolute Deviation,
5. Standard Error in the Mean,
6. Inter Quartile Range,

### Range
This is the difference between the maximum and minimum values in the data.

$$ Range = Max \,\, value \,\, - \,\, Min \,\, Value $$
![[Pasted image 20250215183509.png#invert]]

### Variance
This is the average of the squared differences from the mean, it indicates how spread out the data points are around the mean.

**Population Variance:**


![[Pasted image 20250215183755.png#invert]]
- $N$ is the total number of data points in the population
- $x_i$ is the $i$-th data point
- $\mu$ is the mean of the population


**Sample Variance:**


![[Pasted image 20250215184001.png#invert]]

- $n$ is the number of data points in the sample.
- $x_i$ is the $i$-th data point.
- $\bar{x}$ is the mean of the sample.

These two types of variance are essentially the same thing, but the latter is used in the instance where you only have the data for a *sample* of the population rather the entire population, if you did have data for the entire population, you'd use the former.

### Standard Deviation
This tells us how far in average the individual data points are from the mean in original units, giving a more interpretable measure of spread.
It is the square root of the variance, representing the average distance from the mean.

$$STD(\sigma) \,\, = \,\, \sqrt{\sigma^2}$$
### Mean Absolute Deviation
This is a measure of the **average distance** between each data point in a dataset and the **mean** of the dataset.

![[Pasted image 20250215184852.png#invert]]

Where $|x_i - \mu|$ is the absolute difference between each data point and the mean.

**MAD** is less sensitive to outliers than other measures like variance or standard deviation, which are influenced heavily by large deviations.
It is also easier to interpret because as it works directly with the differences in absolute terms, rather than squared differences (as in variance).

Look at this **example**:

![[Pasted image 20250215190330.png#invert]]
**MAD** is often preferred when you need a **more robust** measure of spread that isn't affected by extreme outliers.

**Standard Deviation** uses squared differences, which can disproportionately weigh large deviations, making it more sensitive to outliers.


### Standard Error in the Mean

This is also known as the 'standard error', it is used to estimate the uncertainty associated with the mean. 	$$ SEM = \frac{\sigma}{\sqrt{n}}$$
*where $n$= sample size*

- It measures the variability of the sample mean across repeated studies,
- Reflects precision of the sample mean as an estimate of the population mean,
- SEM is preferred for error bars.

### Inter-Quartile Range

This is a robust measure associated with the median, also known as the Interquartile Distance (IQD).

The **IQR** is the difference between the $75^{th}$ percentile, and the $25^{th}$
$$ IQR = Q3 - Q1$$ The IQR is less sensitive to outliers.

## Summary:

![[Pasted image 20250217133348.png#invert]]
