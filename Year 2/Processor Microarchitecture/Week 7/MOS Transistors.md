02-01-2026 16:26

Tags: [[Processor Microarchitecture]]

# MOS Transistors

The transistors used in the vast majority of VLSI systems are field effect transistors, or FETs. 
The most common is MOSFET, which stands for **metal-oxide-semiconductor** FET

There are two types of MOS transistors - n type MOS, nMOS transistor and p-type MOS, pMOS transistor. The difference between the two are they way they are fabricated.

## pMOS and nMOS


![[Pasted image 20260102163006.png#invert]]

They have different symbols, pMOS has a circle at the G input, which implies inversion.

On the right we see a function of voltage and the current that goes from D to S. After the threshold voltage it will be on, before it will be off.

| **Type** | **Switch Behavior**                                                                                                                 | **Physics Note**                              |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------- |
| **nMOS** | **Active High:**<br><br>  <br><br>• Gate = '1' $\rightarrow$ ON (Closed) 1<br><br>  <br><br>• Gate = '0' $\rightarrow$ OFF (Open) 2 | Charge carriers are **Electrons** (Negative). |
| **pMOS** | **Active Low:**<br><br>  <br><br>• Gate = '0' $\rightarrow$ ON (Closed) 4<br><br>  <br><br>• Gate = '1' $\rightarrow$ OFF (Open) 5  | Charge carriers are **Holes** (Positive).     |

You can think of these devices as switches, essentially, they are voltage controlled switches.

![[Pasted image 20260102163729.png#invert]]

pMOS works in the opposite way as to nMOS does.

![[Pasted image 20260102163742.png#invert]]

### Drawbacks of nMOS and pMOS

Transistors are **not** perfect switches, they have resistances.

**nMOS** is a good "pull-down", it passes a **Strong 0** (low resistance to ground) **BUT** it is a bad "pull-up", it passes a weak '1', as the voltage rises, the resistance increases and it cannot pull the output all the way up to the full voltage level.
**pMOS** is the opposite, it passes a **Strong 1** but a **Weak 0**.

Think of it as the thing that it does as default it does well but the thing that needs voltage applied to do it does worse.
### Solution: Transmission Gate

To create a "perfect" switch that can pass both 0s and 1s efficiently with low resistance, we combine both of them:
- An nMOS and pMOS transistor connected in parallel.

![[Pasted image 20260102164646.png#invert]]

So here we have a **Control** signal, when control is 0, the device is turned off, this is because the pMOS' signal is 1 (not allowing a current) and the nMOS' signal is 0 (also not allowing a current).

This results in a switch that has low resistance for all signals.

## Usages of the Transmission Gate

The [[MOS Transistors#Solution Transmission Gate|transmission gate]] that we have discussed above, have several uses:

1. The 2-to-1 Multiplexer:

![[Pasted image 20260102165401.png#invert]]

