06-01-2026 15:19

Tags: [[Processor Microarchitecture]]

# Floating Point Representation

Many processors support Floating Point Arithmetic. A floating point value is represented by a word-load of bits. The word is split into fields which represent different components of the value.


![[Pasted image 20260106154435.png#invert]]

If you look we can see that we need to find a balance between resolution and how large of a number we want to represent given a number of bits. We can move the "floating point" left to increase the resolution but this reduces the largest number we can represent.

So the same word can be represented in multiple ways, so we need a way to formalise this and create a standard...


## The IEEE 754 Standard

To represent a huge range of numbers using a fixed number of bits, we can split the 32-bit word into 3 distinct fields:

1. **Sign** ($S$, 1 bit): This indicates if the number is positive or negative. 0 = positive, 1 = negative.
2. **Exponent** ($E$, 8 Bits): Represents the "scale" or magnitude of the number as a power of 2. It uses a **bias** of 127. An exponent field value of 127 represents $2^0$, a value of 128 represents $2^1$. 
3. **Mantissa** ($M$, 23 bits): Represents the precision (the actual digits) of the number.

For a standard "normalised" number the value is calculated as:
$$\text{Value} = (-1)^S \times 2^{E-127} \times {1.M}$$

|**Exponent (E)**|**Mantissa (M)**|**Meaning**|
|---|---|---|
|**0**|**0**|**Zero** (Signed +0 or -0) 44|
|**0**|**Non-Zero**|**Denormalised Number** (Very tiny numbers close to zero where we remove the implicit '1' to represent values smaller than $2^{-126}$) 5|
|**255 (Max)**|**0**|**Infinity** ($\pm \infty$) 66|
|**255 (Max)**|**Non-Zero**|**NaN (Not a Number)** (e.g., result of $\sqrt{-1}$ or $0/0$) 7777|

## Floating Point Arithmetic

When it comes to floating-point math, it is much harder for hardware than integer math because of **Alignment** and **Renormalisation**.

**Multiplication:** This is easier since you multiply the mantissa (unsigned) and add the exponents. The result might need renormalising (shifting the decimal point) if the product is too large.

**Addition/Subtraction:** This is harder as you cannot add two numbers with different exponents, 
1. You must **shift** the mantissa of the smaller number to the right until the exponents match, 
2. You perform the **addition**,
3. Then shift again to restore the hidden '1' to check for overflow/underflow for it to be **renormalised**


> [!NOTE] Accuracy vs Precision
> **Accuracy vs. Precision** The handout explicitly warns against the misconception that floating-point is "more accurate" than integer math.
> - It has a wider **range**, not necessarily better accuracy.
> - Large floating-point numbers have large gaps between them (large errors). * For fractals (like the Mandelbrot Set) or finance, **Fixed Point** (Integer) math is often preferred because the precision is uniform across the entire range

