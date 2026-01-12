05-02-2025 10:57

Status: #new

Tags: [[Data Science]]

# Descriptive Statistics

## What it does
- Summarises data: Makes it manageable, and interpretable
- Extracts insights: Shows underlying trends, correlations or relationships between variables
- Gathers knowledge: Gets actionable insights to make targeted decisions  that drive better outcomes

![[Pasted image 20250205111635.png#invert]]

## Measures of Central Tendency
The three primary measures of central tendency are:
- Mean,
- Median, 
- Mode.

### Mean
This is the sum of all the data points divided by the number of points.
$$Mean(\mu) = \frac{\sum_{i=1}^{n}x_i}{n}$$
This is the best for symmetric distributions without outliers - the mean is sensitive to outliers.
The mean serves as the foundation for more advanced statistical analysis, such as variance, standard deviation, and regression analysis.

#### Squared-Euclidian Distance
The squared Euclidian distance, is just the Euclidian distance (the distance of two points) but squared to eliminate the need for square roots and also gives more weight to larger distances.

#### Weighted Arithmetic Mean
This is useful when not all the observations have the same importance.
It assigns a weight to each observation depending on its importance relative to other observations.
It can provide a more representative measure than an unweighted mean.
$$ \bar{x}_w = \frac{\sum_{i=1}^{n} w_i x_i}{\sum_{i=1}^{n} w_i} $$

where:
- $\bar{x}_w$ is the weighted mean
- $w_i$ is the weight of the $i$-th data point
- $x_i$ is the value of the $i$-th data point
- $n$ is the number of data points

![[Pasted image 20250205152639.png#invert]]
### Median
This is the middle value when data points are ordered - usually in ascending order.
	if there are an even number of observations, you should take the average of the two middle values.

### Mode
This is the most frequently occurring value in the dataset. This is useful for categorical data or to identify the most common occurrence.

## Measure of Shape
The measures of central tendency can let us know the shape of the data.
![[Pasted image 20250205152913.png#invert]]
![[Pasted image 20250205152933.png#invert]]
![[Pasted image 20250205152949.png#invert]]

