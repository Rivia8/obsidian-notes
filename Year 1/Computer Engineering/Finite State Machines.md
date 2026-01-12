05-11-2024 13:57

Status: #new 

Tags: [[Computer Engineering]]

# Finite State Machines

A Finite State Machine (FSM) is a sequential machine that moves from one 'state' to another according to some well defined rules.
	Extra information in [[COMP12111 P3.pdf]]

![[Pasted image 20241105135934.png#invert]]
- The next state is determined from the current state and any inputs defined in combinatorial logic,
- The current state is held in a register,
- Inputs may influence the behaviour (possibly according to the current state),
- Move from current state to next state at a rising clock edge,
- Outputs are derived from state bits (that represent the state),

## State Transition Diagrams and Tables
It is often useful to have a diagrammatic notation for indicating the states and transitions between state in the FSM:

![[Pasted image 20241105140346.png#invert]]
- Each state is represented by a circle
- Each state has a unique label
- Transitions between states are illustrated using arrows (to indicate the direction of the transition)
- There can be multiple transitions from a state, but a condition is required to determine which path is taken

![[Pasted image 20241105140847.png#invert]]
![[Pasted image 20241105140957.png#invert]]
### Using External Inputs:
A typical state machine will allow some external inputs, these input signals determine how and when the machine transitions between different states.
Some or all state transitions are dependent on specific input conditions, the transitions only occur when particular input signals meet the required condition.

For an Example:
A Modulo-7 counter which cycles through 7 states (0 to 6) which includes a synchronous reset input (`reset`), which controls its transitions.

![[Pasted image 20241105153533.png#invert]]
- If `reset = 1`, the counter returns to state 0 on the next clock cycle.
- if `reset = 0`, the counter progresses through the states in sequence,

It contains a 'Synchronous' reset, meaning the reset takes effect in sync with the clock signal: when `reset = 1`, regardless of the current state, the counter will move to state 0 on the next active clock transition.

## Implementation of the FSM:
Producing a Finite State machine is straightforward in Verilog,
The FSM will be module, or contained within a module.

The Module will need a clock input:
```
module FSM (input clock);
endmodule
```

The transition between state always occurs at a rising edge of the clock, this implies an always with `posedge` clock in the sensitivity list:
```
module FSM (input clock);
always @ (posedge clk)
endmodule
```

Within the always block we need to produce the code that gives the desired behaviour

![[Pasted image 20241105154412.png#invert]]

### Next State Logic
We can also create an `always` block to produce the next state logic:
the next state logic is a combinatorial logic block that determines the next state knowing the current state, and the current state of any input signals.
The sensitivity list contains a list of input signals that can cause a state change to occur along with the current state variable.

```
always @ (*)
case(currrent_state)
	0: next_state = 1;

1:
	begin
	if (input1 == 1)
		next_state = 2;
	else
		next_state = 1;
	end

	default: next_state = 0;
endcase

```


![[Pasted image 20241105160619.png#invert]]
### State Change Logic
We can also have an `always` block to implement the state change which happens on a clock edge.
```
always @ (posedge clock)
current state <= next_state; // assigns current_state to next_state
```

with a reset:
```
always @ (posedge reset, posedge clock)

begin
if (reset == 1) // A reset condition is inlcuded
	current_state <= 1 //
else
	current_state <= next_state
end
```

### Output Logic
The output signals are generally derived from the current state and (possibly) inputs.

This should be a combinatorial logic block, so we can use `assign` to set pulses.

```
// output1 is high when in states 0 or 2
assing output1 = ( (crruent_state == 0) || (current_state == 2) ):

// output2 is high when in state 1
assign output2 = (current_state == 1) ? 1:0

```

We can look at a car-part barrier example here:  [[COMP12111 P3.pdf]] page: 71