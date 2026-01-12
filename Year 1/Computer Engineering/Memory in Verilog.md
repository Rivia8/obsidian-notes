22-12-2024 22:48

Status: #new 

Tags: [[Computer Engineering]] [[Memory]]

# Memory in Verilog
## Implementing Memory
Looking at the implementation of memory in Verilog.
Memory in Verilog is just an array of memory locations.

To define an n-bit value:
```Verilog
//the append at the end of the variable of my_memory implements an array
reg [n-1:0] my_memory[0:2^k-1]; 

//16 bits wide, with an 8 bit address, giving 256 memory locations
reg [15:0] my_memory[0:255];
```


To read in Verilog:
```Verilog
//this would give whatever is stored at location 3 to the variable data_out
data_out = my_memory[3];
```

To write in Verilog:
```Verilog
//where FE is a memory location
my_memory[FE] = data_in;
```


## Single Port RAM
Single-Port RAM refers to a memory module that has one port for both read and write operations. This means that you can either read from or write to the memory at any one time, but not both simultaneously.

- One port is used for both reading and writing
- Usually simpler and requires fewer resources compared to dual-port RAM
- Typically, read and write operation occur on different clock cycles.
![[Pasted image 20241222225514.png#invert]]

```Verilog
module single_port_ram (
    input wire clk,            // Clock
    input wire en, wr,         // Enable and Write
    input wire [15:0] address, // Address
    input wire [15:0] din,  // Data Input (write data)
    output reg [15:0] dout  // Data Output (read data)
);


reg [15:0] memory [0:65,535]; // Memory array

// Synchronous block
always @(posedge clk) begin
	if (en)                  // If enable
		if (wr)
			memory[address] <= din
		else
			dout <= memory[address];

endmodule

```

## Dual-Port RAM
Single-port memory is restricted to having a single port for reading and writing data. Dual-port memory allows two separate ports to simultaneously access the memory, providing higher flexibility and performance in data handling.

![[Pasted image 20241222230754.png#invert]]
There are 2 address inputs, since with the Dual-Port RAM you can perform two operations at any one time.

The dual port RAM control signals are:
- `en1`: enable signal – set to 1 to enable the memory for a read/write operation using address1 
- `en2`: enable signal – set to 1 to enable the memory for a read operation using address2 
- `wr`: write signal – if 1 perform a write operation, if 0 perform a read operation


```Verilog
module dual_port_RAM(input wire en1, en2
					input wire, wr, clock,
					input wire [7:0] din
					input wire [15:0] address1, address2
					output reg [7:0] dout1, dout2
					);

reg [7:0] data_RAM [0:65, 535];

always @ (posedge clock) //synchronous
	if (en1)
		if (wr)
			data_RAM[address1] <= din
		else
			dout1 <= data_RAM[address1];'

always @ (posedge clock)
	if (en2)
		dout2 <= data_RAM[address2];
endmodule
```

As you can see in the case for dual port RAM, we need two always blocks.
One for the read/write operation using address1.
The second always block can only perform a read operation using address2.

Both these operations can occur at the same time.