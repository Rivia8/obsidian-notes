16-02-2025 18:02

Tags: [[Maths]]

# Syntax

Formal languages are recursively defined. Examples are computer languages, or language of logical propositions or the language of [[Regular Expressions]].

## Strings

You can have strings over a set $S$ (words over the alphabet $S$) using recursion.

**Base Case** string. The empty string (word) $\epsilon$ is a string.

**Step Case** string. If $s \,\, \in \,\, S$ and $w$ is a string then $w\,s$ is a string.

Here $w\,s$ means taking an existing string $w$ and adding an element $s$ from the set $s$ to the end of it, forming a new string. This allows us to create any string from the alphabet $S$ using the recursive definition.

## Logical Propositions

We have seen logical propositions in [[Logic]].

**Base Case** prop. For every propositional variable $Z,Z$ is a proposition.

**Step Case** prop. Assume that $A$ and $B$ are propositions. Then the following propositions.

**Step Case $\neg$**    ($¬A$)
**Step Case $\land$**    ($A\land B$)
**Step Case** $\lor$    ($A \lor B$)
**Step Case** $\rightarrow$   ($A \rightarrow B$)

![[Pasted image 20250216185313.png#invert]]

## Formal Languages

We know what formal languages are from looking at them in computation, [[Defining New Languages from Old Ones]].

![[Pasted image 20250216192424.png#invert]]

The example above provides a recursive definition to determine when a string made up of symbols from a set $\Sigma$ matches a given regular expression $p$. 

- Recursion is a very useful way of defining syntactic expressions,
- You can then also use recursion to help give meaning to such expressions, 
- You can then use induction to prove properties of such expressions/operations or properties for these.

The following example is given in Computation but not proved:
![[Pasted image 20250216200011.png#invert]]