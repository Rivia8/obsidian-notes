30-09-2024 15:18

Status:  #new

Tags: [[Computer Engineering]] 

# Multiplexer
Another common device is known as a multiplexer, or also known as a MUX. The mux is a switching device, it selects binary information from one of its many input lines an directs it to a single output line. 
![[Pasted image 20241008110455.png#invert]]
Thus, the MUX acts like an electronic switch that selects which source is connected to the output.

Understanding the multiplexer:
**Control/Select Lines**: These lines determine which input to pass to the output. The number of control lines depends on the number of inputs. For example, a 4-input MUX requires 2 control lines because 2 bits can represent 4 states (00, 01, 10, 11).
In simpler terms, a MUX is a data selector.
![[Pasted image 20241008110743.png#invert]]

**The 2:1 MUX**:
Looking at a 2:1 MUX as an example, we will find a collection of basic gates that are connected in order to perform the required switching operation. A schematic of a 2:1 is: 
![[Pasted image 20241008110857.png#invert]]
And a Truth table for a 2:1 MUX is:
![[Pasted image 20241008110918.png#invert|400]]
