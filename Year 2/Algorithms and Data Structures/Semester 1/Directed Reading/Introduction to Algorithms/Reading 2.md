28-10-2025 15:46

Tags: [[Algorithms and Data Structures]]

# Reading 2

Reading for week 2:
- Section 2.3 
- Introduction to Chapter 4
- Section 4.3


# 2 Getting Started


## 2.3 Designing Algorithms

There are a wide range of algorithm design techniques. Insertion Sort uses the incremental method. Here we will look at the 'divide-and-conquer' method.

### 2.3.1 The Divide-and-Conquer Method

Many useful algorithms are recursive in structure - to solve a problem they call themselves. They typically follow the divide-and-conquer method: breaking down the problem into several subproblems that are similar to the original problem but smaller in size, solving the subproblems recursively and then combining the solutions to create an overall solution.
If the problem is small enough (the base case you solve it directly without recursing.'
Otherwise the recursive case you perform three characteristic steps:
1. **Divide** the problem into subproblems
2. **Conquer** the subproblems (recursively)
3. **Combine** the subproblems to form a solution to the original problem

