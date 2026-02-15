02-01-2026 18:27

Tags: [[Processor Microarchitecture]]

# CMOS Logic Gate Design

We use the [[MOS Transistors]] that we have looked to build logic gates (NOT, NAND, NOR, AND).

## CMOS Structure

CMOS (Complementary Metal-Oxide-Semiconductor) logic always uses two competing networks of transistors of transistors to drive the output.

- **Pull-Up Network (pMOS):** Connected between the Supply Voltage ($V_{DD}​$) and the Output. Its job is to pull the output to **Logic 1**.
    
- **Pull-Down Network (nMOS):** Connected between the Output and Ground ($GND$). Its job is to pull the output to **Logic 0**.

- **Complementary Rule:** For any valid input, **only one** network is ON at a time. If both were ON, you would short-circuit the power supply. If both were OFF, the output would "float" (Z state).

![[Pasted image 20260102183018.png#invert]]

The networks are mutually exclusive in operation.

## Simplest Gate, the Inverter - NOT

![[Pasted image 20260102183410.png#invert]]
![[Pasted image 20260102183552.png#invert]]
## Combinations of pMOS and nMOS transistors

nMOS and pMOS can be put in different combinations of either parallel or series circuits to achieve different outcomes.

1. pMOS Transistors in series:

![[Pasted image 20260102183923.png#invert]]

2.  nMOS Transistors in series:

![[Pasted image 20260102184915.png#invert]]

3. Either in parallel:

![[Pasted image 20260102184947.png#invert]]

## NAND Gate

![[Pasted image 20260102185945.png#invert]]

As you can see above, for a NAND gate we use a Pull-Up network and a Pull-Down network.
**C** is the **Output**.

![[Pasted image 20260102190054.png#invert]]

## NOR Gate


![[Pasted image 20260102191022.png#invert]]

## AND Gate

This is simply a NAND gate following an inverter:
![[Pasted image 20260102191142.png#invert]]

## Summary of Construction Rules

Cheat Sheet for building any logic function in CMOS:

|**Logic Function**|**nMOS Network (Pull-Down)**|**pMOS Network (Pull-Up)**|
|---|---|---|
|**AND** ($\cdot$)|Series Connection|Parallel Connection|
|**OR** (+)|Parallel Connection|Series Connection|

The networks are always "duals" of each other. If nMOS is series, pMOS is parallel.
In CMOS design, **NAND** and **NOR** are the "cheap" and fast gates. **AND** and **OR** are more expensive because they require extra hardware to invert the signal back.
