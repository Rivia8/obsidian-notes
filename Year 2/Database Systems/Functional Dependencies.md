20-10-2025 11:48

Tags: [[Database Systems]]

# Functional Dependencies

A **functional dependency** is core concept in [[Relational Model|relational database]] design that acts as a rule or constraint between two sets of attributes (columns) in a table.
In simple terms, if you know the value of attribute A, you can uniquely determine the value of attribute B.

The overall definition:
'A Functional Dependency (FD) is a constraint between two sets of attributes in a relation from a database.'

Given a relation $R$ where $A, B \subseteq R$ 
This relationship is written as: $A \to B$ which reads as "A functionally determines B".
$A$ is the determinant.
$B$ is the dependent.

**Advantages of functional dependencies:**
- Prevents data redundancies,
- Maintains quality of data,
- Helps determine relations and constraints

Lets look at an example:

| **EmployeeID** | **FirstName** | **LastName** | **Email**           | **Department** |
| -------------- | ------------- | ------------ | ------------------- | -------------- |
| 101            | Sarah         | Smith        | s.smith@email.com   | Sales          |
| 102            | Mark          | Johnson      | m.johnson@email.com | Engineering    |
| 103            | Sarah         | Lee          | s.lee@email.com     | Sales          |

1. $\text{EmployeeID} \to \text{FirstName}$: if you know the `EmployeeID` then you also know the `FirstName` but this cannot be said the other way around.
2. $\text{EmployeeID} \to \text{FirstName, LastName, Email, Department)}$: this shows that the `EmployeeID` is indeed the [[Keys#Primary Key|primary key]] for this table since it **determines** *all* other attributes.

## Rules of Functional Dependencies

**Reflexive:**
If $A$ is a subset of $B$, then $A \to B$ 

**Augmentation:**
If $A \to B$ is a valid dependency, then $AC \to BC$ is also valid.

**Transitivity:**
If $A \to B$ and $B \to C$ are both valid dependencies, then $A \to C$ is also valid.

**Union:** if $A \to B$ and $A \to C$, then $A \to BC$ 

**Decomposition:** if $A \to BC$, then $A \to B$ and $A \to C$,

**Pseudo-transitivity:** 

## Types of Functional Dependencies

**Trivial FD:** if $X \to Y$ and $Y$ is a subset of $X$.

**Non-Trivial FD:** if $X \to Y$ and $Y$ is **not a subset** of $X$.

**Multivalued FD:** if $X \to \{Y,Z\}$ and  $Y$ and $Z$ are not dependent one each other.

**Transitive FD:** if $X \to Y$ and $Y \to Z$, then $X \to Z$ (as per transitivity rule).

