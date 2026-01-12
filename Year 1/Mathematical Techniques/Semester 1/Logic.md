20-10-2024 19:12

Status: #new

Tags:  [[Maths]] [[Logic Notes.pdf]]

# Natural Deductions
## Basic Concepts and the Idea of Natural Deduction
We take a logical argument to be a list of assumption or premises that is derived to produce a conclusion through a set of inference rules.
	It is a method that closely mirrors human reasoning, making it intuitive.

In our natural deduction system, an arrangement is represented by a judgement of the general form: $$𝐴_1, ..., 𝐴𝑛 ⊢ 𝐴$$Where $𝐴_1, ..., 𝐴𝑛$ and $A$  are propositional formulas. On the left hand side (before the turnstile symbol, ⊢) there is a list of propositional formulas and one propositional formulas on the right.
	The turnstile symbol indicates that a proposition can be derived from a set of premises using a formal system.

We think of this as saying: 
'$A$ is derivable from the list of from the list of formulas $𝐴_1, ..., 𝐴𝑛$'
 
The formulas on the left-hand side of the turnstile are known as the *antecedents* and the formula on the right-hand side as the consequent of the given judgement.

It makes sense to think that the formulas on the left-hand side, $A_i$ , as assumptions from which $A$ follows - writing lists of propositional formulas can be a bit tedious so it is customary to use $Γ$ to represent a set of premises or judgements.

Natural deduction is used to try prove that some reasoning is correct, ('to check the validity of a sequent', says theory).

### Let's Look at an Example:
*"If it is raining then I have my umbrella. It is raining. Therefore I have my umbrella"*

From this statement we can have the following propositions:
$P$  represents it is raining
$Q$  represents I have my umbrella
$P → Q$  represents raining implies I have my umbrella

We can make an expression for the original statement:
$$ P → Q, P ⊢ Q$$
Which would be a valid judgement.
## Natural Deduction System
Now we will look at formally modelling what the connectives mean, by giving rules which allow us to derive new judgements from given ones.

We present a system called **natural deduction** to infer that a propositional formula $A$ is a logical consequence of $A_1, ..., A_N$. 
The natural deduction system consists of a set of inference rules for construction a proof that:
$𝐴_1, ..., 𝐴𝑛 ⊢ 𝐴$ is a valid judgement.

The inference rules are basically instructions for creating new judgements in a deduction. In our natural deduction system the inference rules operate on judgements because the basic elements of a natural deduction proof is a judgement.

General form of an inference rule:
$$ \frac{Γ_1 ⊢ 𝐴_1, Γ_2 ⊢ 𝐴_2 ... Γ_n ⊢ 𝐴𝑛}{Γ ⊢ 𝐴}$$

- Premises are above the line
- Conclusion is above the line
	- This can kind of be thought as an 'if-then' statement in a program: if the premises are true, then the conclusion is true.

## Inference Rules:
- Introduction rules can be thought of as introducing a new formula on the right-hand side, whereas
- We can think of elimination rules as breaking down the formula on the right-hand side of the turnstile of a judgement.
### Axiom:
![[Pasted image 20250101163803.png#invert]]
This is a rule with no premises and is therefore always applicable. The rule can be used to assume any formula, like here we have it say that $A$ can always be inferred from $A$ and a set of formulas.

### Weakening:
![[Pasted image 20250101163830.png#invert]]
### Conjunction:
![[Pasted image 20250101163323.png#invert]]
![[Pasted image 20250101163407.png#invert]]
### Disjunction:
![[Pasted image 20250101163443.png#invert]]

### Implication:
![[Pasted image 20250101163534.png#invert]]
### Negation:
![[Pasted image 20250101163628.png#invert]]

![[Pasted image 20250101163654.png#invert]]

### Double Negation:
![[Pasted image 20250101163719.png#invert]]

## Deductions
In our natural deductions system, a deduction is a sequence of judgements, where each judgement has been derived rom preceding judgements by the application of one of the inference rules. 

The judgement we aim to prove should always be in the last line of a deduction. In that 
case the deduction is a proof of this judgement:

For an example:
![[Pasted image 20250101170242.png#invert]]




![[Pasted image 20241020191857.png#invert]]

## Tautologies and Equivalent Formulas
A tautology:
![[Pasted image 20250108133442.png#invert]]

Equivalent Formulas:
![[Pasted image 20250108133559.png#invert]]
If both the judgements $A$ and $B$ are derivable from each other, both the two formulas can play the same processes as each other. If we wanted to use one, we could use the other.

## Semantic Equivalence
Semantic equivalence means that two statements or formulas have the same meaning or truth value under all possible interpretations. Basically, if one statement is true, the other is also true, and if one is false, the other is false. 
	*It's like saying, "It's raining outside" and "Water is falling from the sky"—different words, but the same situation.*

![[Pasted image 20241027181656.png#invert]]
![[Pasted image 20241027200212.png#invert]]
![[Pasted image 20241027191621.png#invert]]

## Semantics:
Everything previously understood and defined is purely syntactic: we have been working with symbols and rules to derive conclusions in logic. This tells us how to structure arguments, but it doesn't always help us understand the deeper meaning or connect it to real-world concepts. Using only these rules makes it tricky to reason about some properties of logic and see its practical relevance in other areas.
We need semantics in order to produce a clear and precise way to assign meaning to these logical formulas. Semantics offers this by connecting formulas to mathematical concepts that are less about symbols and more about meaning.
*So moving from purely symbolic manipulation to a deeper understanding helps us see how logic applies to broader fields and ensures our arguments are sound and meaningful*.

![[Pasted image 20241026194839.png#invert]]

![[Pasted image 20241026194848.png#invert]]
![[Pasted image 20241026200418.png#invert]]
![[Pasted image 20241026200514.png#invert]]
## Power Set Semantics
We understand traditional semantics in which logical formulas are evaluated to be either 1 (true) or 0 (false) - this can be limiting.
With **Power Set Semantics** instead of just 1 or 0, values are now subsets of as set X. The power set of X is the set of all possible subsets of X. So, valuations (assigning values to variables) now work with these subsets.

![[Pasted image 20241027174516.png#invert]]
In Boolean semantics, a propositional formula A is called a contradiction if it always evaluates to false, no matter what values you give to its variables.
So to be a contradiction, A must be false for everything for every possible members of values for its for its variables.

**Unsatisfiable Formula:** Cannot be true no matter what values you assign to its variables.
**Tautology**: It is always true no matter what values you assign to its variables.

