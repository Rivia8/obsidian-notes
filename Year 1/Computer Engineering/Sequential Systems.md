09-10-2024 16:49

Status: #new

Tags: [[Computer Engineering]]

# Sequential Systems and D-Type flip flops

The logic circuits we have looked at so fart are called ***Combinatorial Circuits***, the output signal depends on the values of the input signals to the circuit at any particular instance in time.
Most digital systems are implementing some form of algorithm as a sequence of steps.
Most digital systems are sequential in nature and constructed using flip-flops and gates:
- 'Events' are sequenced to an external clock

## The Clock:

So in the algorithm the steps are sequenced in time. Hence, we use a clock to ensure steps happen at the correct time.
A clock is a signal consisting of an infinite stream of pulses changing between 0 and 1 at a known rate called the frequency.

In a sequential system, we ensure actions are performed with respect to the same timing on the clock, this ensures that the steps in the process are sequenced.
The time between identical points in the clock is the period, which is the inverse of the clock frequency.

![[Pasted image 20241009173514.png#invert|800]]
$$ period = \dfrac{1}{frequency} $$
![[Pasted image 20241009173812.png#invert|800]]

## Sequential Systems:

In a sequential system, the output signal depends on the current value of the input signals and the past history of its inputs - it requires some form of memory in order to store information. 
The memory can be implemented using a logic device called a flip-flop, which is controlled by a clock to ensure that the state of the system is updated when required.

![[Pasted image 20241009174202.png#invert|800]]


![[Pasted image 20241009175133.png#invert|800]]

Here's a look at the [[D-Type Flip-Flop]]

They sometimes have datapaths:

| **Feature**    | **Simple FSM (No Datapath)**               | **System with Datapath**                 |
| -------------- | ------------------------------------------ | ---------------------------------------- |
| **What it is** | A single, integrated FSM.                  | A **Controller (FSM)** + a **Datapath**. |
| **Best for**   | Control-heavy tasks (e.g., traffic light). | Data-heavy tasks (e.g., CPU).            |
| **Complexity** | Low. Logic is all mixed.                   | High. Logic is split (Brain vs. Brawn).  |
| **Example**    | Vending machine, traffic light.            | CPU, digital filter.                     |

### The Design Process

The complete design process for a simple sequential system usually works as follows:
1. From a system specification decide on the inputs and the outputs, 
2. from there draw a state transition diagram
3. Perform state assignment (label each state with a unique number)

In a manual process, proceed as follows:
- Complete a state transition table.
-  Extract (and simplify) all the logic equations – Karnaugh maps may help.
- Draw the logic diagram as gates and connect to the appropriate flip-flops.
- Test!
If using a HDL:
- Usually the FSM can be translated directly into HDL code
- Compile
- Test!
- Download to system (if FPGA based)
