21-05-2025 13:31

Tags: [[Data Science]]

# Data Sampling

**Sampling** or **data sampling** is the process of selecting a subset from a larger population to make inferences about that population (it's faster, cheaper and more practical than collecting data from the entire population).

We have three different perspectives we have to overlook with data sampling:

- Sampling techniques
- Bias in sampling
- Statistical properties

We have some key terms too:

|Term|Meaning|
|---|---|
|**Population**|The entire group you're interested in|
|**Sample**|A subset taken from the population|
|**Sampling**|The process of choosing the sample|
|**Sampling distribution**|Distribution of a statistic (like the mean) across many samples|
## Assumptions

When we take samples we make some assumptions:

1. The population we take the sample from is infinite,
2. The sample is drawn randomly
	a. this makes the sample **representative** of the population,
	b. this makes the sample **independently** and **identically** distributed.
3. The order of drawing the sample does not matter.
	a. the data is "exchangeable".

In reality, the population is never infinite, but a lot larger. 
Getting a truly representative sample may be difficult.
The order the data was collected may matter, events during the survey could affect opinions.

## Viewing the Population

![[Pasted image 20250521134732.png#invert]]
**Empirical** means "based on observed data".

## Data Values

![[Pasted image 20250521140116.png#invert]]

According to the law of large numbers:
In the limit of a large number of samples, empirical mean converges to population mean.


**Variance and STD**
![[Pasted image 20250521140205.png#invert]]

So we have the:
- Regular mean, $\mu$, and the sample mean, $\hat{m}$.
- Regular STD, $\sigma$ and the Sample STD, $\hat{s}$ (or ${\sigma}_{sample}$).

### Incorporating SEM

You can use the [[Measures of Spread#Standard Error in the Mean|Standard Error in the Mean (SEM)]] to tell you the uncertainty in the estimation of the empirical mean. You just swap the use of the regular [[Standard Deviation]] $\sigma$ with the sample standard deviation $\hat{s}$:

![[Pasted image 20250521143323.png#invert]]

## Monte Carlo Method

**Monte Carlo Sampling** is a technique that uses random sampling to approximate mathematical or statistical quantities.

One example of this case is finding the value of $\pi$. 

![[Pasted image 20250521171420.png#invert]]

![[Pasted image 20250521171432.png#invert]]
As you can see increasing the samples give a better determination of $\pi$.


## Systematic Sampling

Systematic sampling involves collecting a sample at a **regular interval** from a list or sequence.

1. You choose a starting point at random, 
2. Then pick every k-th element.

This is good for when the population is ordered randomly, you want a simpler method and want quick and evenly spaced sampling.

## Stratified Sampling

This involves dividing the population into **strata** (distinct groups), then randomly selecting from each group.
This is good when your population has distinct groups that need representing.

![[Pasted image 20250521172853.png#invert]]

## Cluster Sampling

Divide the population into **clusters** and then randomly select some clusters and survey everyone in those clusters.

![[Pasted image 20250521172903.png#invert]]

## Weighted Sampling

Some members of the population are **more likely** to be sampled.
This occurs when the members of a population have different levels of importance.
An example would be assigning probabilities based on trading volume; so stocks with higher trading volume are more likely to be selected.


## Sampling with a **Small** Dataset

Let's say you had the data: $$(A,B,C)$$
### Without Replacement

If you were to apply something like random sampling to the data, and **not** return the data back to the sample. 
The **issue** with this is that it **limits** the number of unique samples.

Let's you had $n=2$, You could only sample:
$AB, AC, BA, BC, CA, CB$
6 Combinations.
### With Replacement

If you had replacements it means that duplicate data could be drawn in a sample.
$AA, AB, AC, BA, BB, BC, CA, CB, CC$

---

| Aspect                     | With Replacement                          | Without Replacement                      |
| -------------------------- | ----------------------------------------- | ---------------------------------------- |
| **Duplicates** allowed?    | ✅ Yes (e.g. A,AA, A)                      | ❌ No                                     |
| **Independence**           | ✅ Yes                                     | ❌ No — depends on previous picks         |
| **Number of combinations** | $N^n$                                     | $\frac{N!}{(N-n)!}$                      |
| **Sample variability**     | More — more randomness, possible repeats  | Less — each pick reduces possibilities   |
| **Bias potential**         | Lower risk of bias if sampling repeatedly | Can be more representative in small data |

## Bootstrapping

Sample with return is also called the **Bootstrap** method.
Its a resampling technique used to estimate the distribution, standard error or confidence intervals of a statistic.

## Bias in Sampling

Some members of the population are more likely to be selected than others, over-representation of certain groups may lead to biased model predictions.

### Selection Bias:

Exists if some potential subjects are more likely than others to be selected for the study sample.

Causes:
1. Excluding part of the population.
2. Non-random sampling method, 
3. Sampling only from easily accessible groups. 


### Volunteer Bias:

Refers to the fact people who volunteer to be in studies are usually not representative of the population as a whole.

Causes:
- People who feel strongly about a topic are more likely to volunteer.

### Nonresponse Bias

This is the opposite of volunteer bias, this is caused when a significant portion of the population is underrepresented due to the fact that they might not want to volunteer.

### Social Desirability Bias:

This is caused by people wanting to be perceived in a certain light by the examiner. This may skew the results.

### Survivorship Bias:

This occurs when you *only* analyse successful cases.

### Scenario Explaining the Bias:

"*A university reports the average annual salary of its graduates as $120,000, based on*
*responses to a survey of contributors to the alumni fund.*"

We could have these following presented in this case:

- **Selection bias:** The reported average annual salary is probably an overestimate of
the true value because subscribers to the alumni magazine were probably among the
more successful graduates.

- **Non-response bias:** People who felt embarrassed about their low salary were less
likely to respond

- **Social desirability bias:** graduates might be tempted to report higher salaries than
they really earn because it is desirable to have a high income. That would result in
calculating an overly high average annual salary.



