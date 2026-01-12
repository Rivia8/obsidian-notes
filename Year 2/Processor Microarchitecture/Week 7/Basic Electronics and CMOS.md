02-01-2026 15:24

Tags: [[Processor Microarchitecture]]

# Basic Electronics

When we had something like an 'AND' gate that you see in front of your here, we merely just 'abstracted' the idea and we didn't actually understand what it is actually comprised of.

![[Pasted image 20260102152637.png#invert]]

**Logical Functions** are designed using CMOS (complementary metal-oxide-semiconductor) which in turn relates to the way the devices are fabricated in silicon using 
metal-oxide-semiconductor field effect transistors (MOSFETS).

Example of a simple circuit:

![[Pasted image 20260102153223.png#invert]]

If there is a conductive path, electric charge will flow (which are measured in Coulombs), the continuous movement of this charge is called a current, measured in Amps (A).
1A is when there is a flow of 1 coulomb per second.

## Ohm's Law:

$$ V = I / R$$

- **Voltage** is like "force" or pressure that motivates charge to move, this is measured in Volts ($V$).
- **Current** is the flow of electrical charge, measured in Amps ($A$)
- **Resistance** the opposition to current flow which is measures in Ohms ($\Omega$)

A simple way to visualise this law is that voltage is the circuit is a water system, where the voltage is the pump, the current is the water flow and the resistance is the pipe constriction.

## Resistors 

![[Pasted image 20260102154304.png#invert]]

- If we connect a 1kOhm resistor to a 1V voltage source then all the battery voltage is across the resistor, so according to Ohm’s law, the current flowing through the resistor will be 1mA.

Resistors can either be placed in parallel or series. 

In series the resistances are added together, this is because the current flowing from the 
voltage source will have to go through both.

In parallel:

![[Pasted image 20260102154652.png#invert]]

Here each 'strand' will be given the same voltage, this means that the current will be split between the 2 'routes' the electrons can travel down. This means that the total resistance is a fraction of the sum of the resistances of the resistor.

## Capacitors

Capacitors are used to store charge, the simplest form of capacitor is the parallel plate capacitor.

![[Pasted image 20260102154851.png#invert]]

$$ C = Q/V$$The ratio of the charges stored (Q) to the voltage across the capacitor (V) gives the capacitance (C) measured in Farads, F.  

## Component Configuration

Resistors and Capacitors can be either placed in series or parallel.

| **Configuration** | **Resistors (R)**                       | **Capacitors (C)**                      |
| ----------------- | --------------------------------------- | --------------------------------------- |
| **Series**        | Add values: $R_T = R_1 + R_2$ 11        | Inverse sum: $1/C_T = 1/C_1 + 1/C_2$ 12 |
| **Parallel**      | Inverse sum: $1/R_T = 1/R_1 + 1/R_2$ 13 | Add values: $C_T = C_1 + C_2$ 14        |

For capacitors, it is kind of the opposite to resistors:

![[Pasted image 20260102155227.png#invert]]

## RC Circuit

If we have a voltage source connected to a resistor and a capacitor in series. When you switch the circuit on, the voltage across the capacitor does not jump instantly, to $V$, it rises on a slow exponential curve.

![[Pasted image 20260102155502.png#invert]]

