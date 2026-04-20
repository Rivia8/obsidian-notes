11-02-2026 13:24

Tags [[2 - Tags/System Architecture]]

# Memory Hierarchy

Small memories can be made fast.
We want to make frequently accessed memories fast and infrequently accessed memories slow. 
**This relies on the statistical nature of a 'typical' program**.

Almost all software shares characteristics which can be described by the [Pareto Principle](https://en.wikipedia.org/wiki/Pareto_principle). 

*Recall: [[Memory Properties#Caches|types of locality in memory]]*

Here we can see the levels of cache:

![[Pasted image 20260211133209.png#invert]]


Performance:
$$T_{ave} = T_{hit} + (P_{miss} \times T_{mem})$$
If the time to access memory is 10ns, and the percentage to miss is 10% we would have:
$$T_{ave} = 1\text{ns} + (0.1 \times 10\text{ns})$$
$$T_{ave} = 1\text{ns} + 1\text{ns}$$
$$T_{ave} = 2\text{ns}$$
