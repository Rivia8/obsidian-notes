02-01-2026 20:15

Tags: [[Processor Microarchitecture]]

# Issues with CMOS Circuits

We previously treated the transistor as a simple control input. However, in reality the physical construction of a MOFSET creates a capacitor.
The **structure** has the transistor built in layers, where the metal "gate" is separated from the silicon "channel" by a thin insulating oxide layer. This results in a Conductor-Insulator-Conductor sandwich which forms a parallel plate capacitor.
This results in every time you try to switch the capacitor on, you aren't just sending a signal, you have to **charge up** the capacitor $C_g$, this takes time and energy.

![[Pasted image 20260102201909.png#invert]]

The size of the capacitor depends on the physical dimensions of the transistor gate:
- **Gate Length (L):** The distance electrons must travel. We want this as small as possible (e.g., 5nm, 3nm process nodes) to make the transistor faster and the capacitance smaller.
- **Gate Width (W):** How wide the channel is.
    - **Wider (W↑):** Lowers resistance (allows more current, charging the _next_ gate faster) BUT increases the input capacitance (harder for the _previous_ gate to drive) .
- **Trade-off:** Designers must balance W to optimize speed without overloading the previous stage

## Power Dissipation and Capacitive Load

When a gate like an inverter tries to drive an output from $0 \to 1$, it has to charge a total "Load Capacitance", $C_L$:
- **Intrinsic Capacitance ($C_{do}$​):** The capacitance of the driving gate itself.
- **Wiring Capacitance ($C_w$​):** The metal wires connecting the gates also hold charge. Long wires = slow chips.
- **Input Capacitance ($C_{gn}$​):** The sum of all the gate capacitances of the _next_ transistors being driven.

$$C_L= C_{do}+C_w+C_{gn}$$

There is a Power Dissipation law:
$$ P_D \propto C_L \cdot~{V_{DD}}^2 $$
or
$$P = C \times V^2 \times f$$

This describes **Dynamic Power**, the energy burned just by switching 1s and 0s.


> [!NOTE] Silicon changes that affected Capacitive Load
> The shrinking of devices of devices has led to wiring capacitance dominating and whilst the length of wires has got shorter (which is a good thing) they have also shrunk in cross sectional area, which is a bad thing. In addition, the shrinking of the spacing between wires also leads to an increase in the capacitance. So overall, the shrinking of geometries hasn’t been helpful in this respect.


## Signal Rise Time

Since there is an element of capacitance, when the output changes from a 0 to a 1, we have to charge the capacitance at the output, so it takes a finite amount of time for the output to change. Conversely, if we go from a 1 to a 0 then it takes finite time to discharge, so the switch is not instantaneous.

![[Pasted image 20260102203449.png#invert]]

There are three ways of improving this:

1. Reducing the capacitive load,
2. Increasing the drive strength,
3. Buffering the signal - inserting additional gates can help improve speed and CAD

## Total Power Dissipation

During the "transition time", the input is somewhere between 0 and 1, undefined. This means that for a brief nanosecond, **both** the pMOS and nMOS transistors are partially open. This creates a direct short circuit from Power to Ground, wasting current just because the switch was too slow. 

![[Pasted image 20260102214315.png#invert]]