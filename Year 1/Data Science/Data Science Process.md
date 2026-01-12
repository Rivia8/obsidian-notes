27-01-2025 10:23

Status: #new

Tags: [[Data Science]]

# Data Science Process

## Scientific Method
Data science will involve the scientific method - it is a hypothesis derived science. 

- Careful observation
- Applying rigorous scepticism
- Formulating hypotheses via induction and creativity
- Experimental and measurement-based testing of deductions drawn from the hypotheses.

## Data Science Process
![[Pasted image 20250130161652.png#invert]]
![[Pasted image 20250130161951.png#invert]]
### Step 1: Frame the problem
So there are two cases that can happen at this point.

1. We have a bunch of data - what can we do with it?
	From this we look at the data and try to figure out if there are any issues. 

2. Here is a problem we want to solve, what do we need to get and how do we use it?
	A good way to understand this case is by looking at an example: 
	Let's say we have the problem that we want to **count the number of people in a space**, so how do we go about solving this problem? We could use Wi-Fi to ping devices in the area, using video to detect the number of people or a sensor beam to count the number of people that cross it.

### Step 2: Getting the Raw Data
When collecting the Raw Data there are some factors to consider:
1. Is the data relevant
2. Are there privacy/security issues
3. Is the data collected in an unbiased manner

This phase is crucial because the insights you derive are only as good as the data you collect. It is vital to clearly define the data requirements before anything is started, mapping it out ensures that you don't waste time collecting irrelevant information. 

Once you have figured out what you need, it's time to find out where to get it:
- Internal Databases
- External Sources
- Web Scraping
- APIs
- Surveys and Experiments

You then need to ensure the appropriate **Data Acquisition Methods** are used to collect the data which will save time and reduce errors.

Figuring out where and how to store the data is next: Selecting appropriate storage solutions, data backup and recovery, security measures and scalability.

### Step 3: Pre-process and Clean the Data
Raw data typically requires additional processing before it can be used.
Due to:
- Inconsistencies in the structure
- Duplicated data
- Errors in the data
- Missing data
- Data that is not relevant to this specific problem

Having missing values is very important since they're quite common in certain areas like psychological, educational, and cancer studies. Missing values may invalidate or cause biases in conclusions of such studies - so we need to have strategies to handle missing data, different strategies that depend on the context.

#### Handling of Missing Data
**Removing data:** Deleting rows that contain missing values
**Imputation**: Filling in missing data with estimated or inferred values based on available data
**Predictive Data**: involves using predictive machine learning models to predict missing values based on other features in the dataset.
**Interpolation:** Using the surrounding values (often based on linear or polynomial functions) to estimate missing values.
**Domain-Specific Rules:** Using domain-specific knowledge to infer missing-values or substitute them with values that make sense within the context of the problem.

**Examples of Techniques in Data Cleaning**
#### Data Wrangling
Data wrangling (or also known as data munging) is the meticulous process of transforming raw data into a polished, insightful form. It's like turning disorganized puzzle pieces into a coherent picture.

#### One-Hot Encoding
This is a technique that is used to convert categorical variables into a numerical format that machine learning models can digest.

---
In Essence these two techniques are intertwined in the data cleaning process where data wrangling refines your dataset and one-hot encoding translates categorical insights into a language machines understand.

### Step 4: Exploring Data Analysis (or EDA)
1. To gain some insight or intuition about the data
2. To explore certain aspects of the data
3. To develop methods or hypotheses for using the data to solve the problem

We also have to compute properties of the data:
- Measures of central tendencies
- Measures of variability
- Correlations between observed quantities

![[Pasted image 20250130163754.png#invert]]
These visualisation methods allow us to be able to understand things about the data.

### Step 5: Analyse and/or Model the Data
To better understand and interpret data we can build a model of the data.

- **Probability Model:** helps you quantify the uncertainty in the data and understand the likelihood of different outcomes. It's useful when you want to predict or assess the chances of events occurring, based on observed patterns.

- **Simulation Model:** focuses on recreating or simulating the underlying process or system that generates the data. It's beneficial when you want to understand the mechanisms or dynamics behind the data and explore how changes in inputs or conditions might affect outcomes.

### Step 6: Determining the Validity of the Results
How can people trust our results?

- Provide evidence that supports the validity of our conclusions

*This is often overlooked in data science discussions, but without it, it's not truly a science.*

- Does the model fit or predict new data?
	Since the model was built using specific data - does it continue to perform well with new data from the same problem and so does it make accurate predictions on unseen data. Reflecting on this question you should separate your data into sets, one for model building and one for testing.

### Step 7: Use and Communicate the Results
1. Present the results or solution to the problem.
2. Create documentation to help others understand and use your methods and findings.
3. Write in a way that non-data scientists can comprehend.
4. Share or embed the code.
5. Share the data, if you generated it.
