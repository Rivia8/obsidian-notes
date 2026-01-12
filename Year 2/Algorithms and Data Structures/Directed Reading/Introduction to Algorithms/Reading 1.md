07-10-2025 13:01

Tags: [[Algorithms and Data Structures]]

# Reading 1

Reading for Week 1
Sections 1.1.1 1.1.3

## Introduction

When designing algorithms you need to be able to describe how they operate and how to design them.
Mathematical tools are also needed to show that your algorithms do the right thing ad do it eficiently.

# 1 The Roles of Algorithms in Computing

This explains what algorithms are, why is the study of algorithms worthwhile, what is the role of algorithms relative to other technologies used in computers.

## 1.1 Algorithms

**Informally:** "An algorithm is any well-defined computational procedure that takes some value, or set of values, as input and produces some value, or set of values, as output in a finite amount of time. An algorithm is thus a sequence of computational steps that transform the input to the output."

An **instance of a problem** consists of the input (satisfying whatever constraints there are imposed in the problem statement) needed to compute a solution to the problem.
An example could be sorting some numbers into ascending order: `31, 41, 59, 26, 41, 58` into `26, 31, 41, 41 , 58, 59`, the first set of numbers would be considered the ***instance***.
Many programs use sorting as an intermediate step, sorting is a fundamental operation in computer science,. As a result, you have a large number of good sorting algorithms at your disposal - the 'best' algorithm will depend on a number of factors.

An algorithm for a computational problem is **correct**, if:
- for every problem instance provided it **halts**, 
- finishes computing in finite time,
- outputs a correct solution.

A correct algorithm is one that solves the given computational problem (incorrect algorithms can be useful if you can control their error rate).

There are so many other algorithms that do so many cool things within projects you may or may not have heard before:
- The human genome project,
- The internet,
- Electronic commerce,
- Manufacturing, and other commercial enterprises,

With algorithmic techniques specific problems will need to be solved.
When it comes to algorithms that solve specific problems, they exhibit **two characteristics** that are common to many interesting algorithmic problems:
- **They have many candidate solutions**:  only a few will actually solve the problem at hand and some will be better than others, this process is the difficult part.
- **They have practical applications.**

**Data Structures:** the book represents several data structures, where a ***data structure*** is a way to store and organise data in order to facilitate access and modifications. Using the appropriate data structure is important since not all data structures are appropriate in every design, each has strengths and limitations.

Some problems, hard problems, have no algorithm that runs in a reasonable amount of time, there is a subset of these problems known as NP-complete.
NP-complete algorithms have the remarkable property that if an efficient algorithm exists for any one of them, then efficient algorithms exist for all of them. These problems actually occur in application quite often, it is wise to know about them so you don't end up end in a fruitless search.

### Alternative Computing Models

Before we used to rely on CPU's on increasing the clock speed to become faster at compute, now we have CPUs that also posses multiple cores that can run in parallel.
We need to be able to produce algorithms that take parallelism in mind.

Much of the work in algorithm design takes the assumption that all of the input data is available at algorithm run time, however, most the the input actually arrives at over time, and the algorithm must decide what to do with the data that arrives in the future.
Algorithms that receive their input over time, rather than having all the input present at the start are ***online algorithms***.

## 1.2 Algorithms as a Technology

Even if computers were infinitely fast and computer memory were free, you would still need to study and develop algorithms since you would still need to be certain that the your solution method would terminate and does so with the correct answer. You would want the implementation of the to be within the bounds of good software engineering practice.

In terms of **efficiency** different algorithms devised to solve the same problem will often differ dramatically in their efficiency. These differences can be much more significant than differences due to hardware and software.
This can be seen through the example of **merge sort** and **insertion sort.** Insertion sort takes $c_1 \cdot n^2$ and merge sort takes $c_2n \cdot log(n)$. We have already learnt looking at [[Computation]] that the factors $c_1$ and $c_2$ don't matter in the grand scheme of things.
With this example it is incredibly clear that for a large $n$ (input) that merge sort will a lot more faster (takes less steps to find a solution) than insertion sort just by looking at the difference between the function of $n$ vs $log(n)$ (since we cancel the other $n$ for insertion sort).

Algorithms should be considered like technology. System performance depends on choosing efficient algorithms as much as on choosing fast hardware. Algorithms are at the core of most technologies used in contemporary computers.

Machine learning, is itself a collection of algorithms, just under a different name.






