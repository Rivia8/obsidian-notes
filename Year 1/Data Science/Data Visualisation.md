
20-04-2025 22:26

Tags: [[Data Science]]

# Data Visualisation

Why do you need data visualisation?:
- Identifying patterns in the data, 
- Communicating important information to an audience.
- To aid decision making.

When it comes to design, it is important to have good principles:

## Principles of Visualisation Design:

### Linear Axes

Human perception research suggests that bar height is a key quantity we perceive when looking at bar charts:

![[Pasted image 20250420223353.png#invert]]


The chart above suggests that Honolulu's median income is magnitudes above that of Hawaii's to someone, however that is not the case -  the use of an appropriate scale is important.

### Logarithmic Axes

When it comes to a log scale, using bars may not be a good idea, since the areas of bars etc are not proportional to the data values, with a log scale, we also cannot start at zero (as this is undefined).

![[Pasted image 20250420223832.png#invert]]
### Direct Area Visualisations

When it comes to these, people are really bad at interpreting them, so usually an aid is given to help.

![[Pasted image 20250420224026.png#invert]]

Both charts are hard for people to understand, so sometimes these are implemented: 
![[Pasted image 20250420224113.png#invert]]
As you can see a translucency effect is incorporated.
### **General Design Choices**

For points that are overlapping, you can add jittering which adds noise but also highlights the true values of how many points there are:

![[Pasted image 20250420224420.png#invert]]

it is important to have the randomisation seed for the jitter added to ensure that the visualisations are reproducible.

When it comes to colour choices (and grouping) it is important to have it set out clearly:

![[Pasted image 20250420224959.png#invert]]

It is also good practice to use colour scales, that work for people that have colour blindness.

The data visualisation is important, but another thing is also the **Titles** and **Captions**, without them some visualisations may be difficult to interpret.

**Animations** help communicate how variables change over time.

## Misleading Visualisations

Bar graphs are limited to what they can convey, they lack the ability to communicate things like the **distribution** of the data.

This can also occur with other visualisation types like box-plots that might not include things like **data shapes**.

This can be understood with this:

![[Pasted image 20250420225809.png#invert]]

This is **Anscombe's Quartet** the data underlying each one are all different, however, they all have the same **mean** and **standard** deviation for their x and y values and the same **regression lines**.
So if you produced visualisations based on those metrics alone you'd produce 4 identical graphics which would be misleading.

In order to prevent misleading data visualisations, **development** and **testing** needs to happen:

![[Pasted image 20250420232258.png#invert]]

The graphs above were presented to 150 participants and found that non-linear decay was the best in terms of reducing error associated participants estimates of the strength of the relationships.


## Correlation is NOT causation

When you put two variables along side each other and **see** a sort of 'line' it might suggest that the correlation is due to the variable **causing** the other - essentially **causation**. 

![[Pasted image 20250420230920.png#invert]]






