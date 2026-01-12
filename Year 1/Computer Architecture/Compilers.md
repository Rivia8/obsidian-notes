16-12-2024 14:21

Status: #new 

Tags: [[Architecture]]

# Compilers

**History with Languages:**
![[Pasted image 20241216142324.png#invert]]
Compilers promote the use of high-level languages by minimising the execution overhead of the programs written in these languages.
Compilers are also critical in making high-performance computer architecture.

"A Compiler is a program that can read a program in one language - the source language - and translate it into an equivalent program in another language - the target language."

![[Pasted image 20241216143658.png#invert]]

In addition to a compiler, several other programs may be required to create an executable target program.
![[Pasted image 20241216143809.png#invert]]
**The purpose of a compiler:**

Primary:
- To comply with the specifications of the input language
- To generate correct code for the target machine

Secondary:
- To generate a fast output code with low memory footprint (reliable optimisations)
- To have a low compilation time (must be linearly proportional to the size of input code)
- To provide good diagnostics (debugging/ error reporting)

In many software development workflows, compilers and assemblers work together to transform high-level source code into executable machine code. 

**Structure of a Basic Compiler**:
![[Pasted image 20241216144931.png#invert]]
Looking at the picture above, we can see that the compiler is divided into two main parts:

1. ***Analysis (Front-end)***

	**Lexical Analyser**:
	**Input**: Character Stream (the raw source code)
	**Output**: Token Stream (a sequence of tokens)
	**Function**: the lexical analyser, also known as the lexer, scans the source code character by character and groups them into tokens. Tokens are the smallest units of meaning, such as keywords (`int`, `return`), identifies (`main`, `x`), operators (`+`, `-`), and symbols (`;`, `{}`). This phase removes whitespaces and comments.

	**Syntax Analyser**:
	**Input:** Token Stream
	**Output:** Syntax Tree (or parse tree)
	**Function:** The syntax analyser, or parser, takes the tokens produced by the lexical analyser and checks their sequence against the grammar rules of the programming language. It constructs a syntax tree, which represents the hierarchal structure of the source code, showing how tokens are combined to form statements and expressions.

	**Semantic Analyser**:
	**Input**: Syntax Tree
	**Output**: Annotated Syntax Tree
	**Function:** The semantic analyser checks the syntax tree for semantic errors, ensuring that the meaning of the code, is correct. This includes type checking, ensuring variables are declared before use, and that functions are called with the correct arguments. It may also add type information and other attributes to the syntax tree.

# 

2. ***Synthesis (Back-end)***

	**Intermediate Code Generator**:
	**Input**: Annotated Syntax Tree
	**Output**: Intermediate Representation (IR)
	**Function**: This phase translates the annotated syntax tree into an intermediate code. The intermediate representation is a lower level code that is easier to optimise and can be translated into machine code. Common forms of IR include three-address code (TAC) and intermediate languages specific to the compiler.

	**Machine-Independent Code Optimiser**:
	**Input:** Intermediate Representation
	**Output:** Optimised Intermediate Representation
	**Function:** The code optimiser performs various optimisations on the intermediate code to improve efficiency and performance. The optimisations do not depend on the target machine architecture and include removing redundant code, optimising loops, and improving data flow.

 features and constraints of the target machine architecture such as instruction set characteristics and memory hierarchy. It ensures the generated code runs efficiently on the target hardware.

We also have the **symbol table**.
The symbol table is a critical data structure used throughout the compilation process. It stores information about variables, functions, objects, and other entities in the source code. The symbol table helps in semantic analysis and code generation by keeping track of names and their associated attributes, such as types, scopes and memory locations.

## Compiler VS Assemblers

![[Pasted image 20241217162833.png#invert]]

