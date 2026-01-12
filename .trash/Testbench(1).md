16-10-2025 17:57

Tags: [[Verilog]]

# Testbench

This continues the topic of [[Testing|testing]] where we look at testbenches.

Testbenches play an important role in the design process, the goal for a testbench is to provide inputs to the design and evaluate the outputs to ascertain whether the design conforms to the specification.

![[Pasted image 20251016175816.png#invert|800]]

The **Design Under Test (DUT)** can be a Verilog behavioural description of a module, a gate level description or even a schematic (does not always have to be Verilog design).

We provide data stimulus to a DUT:
**deterministic**: you assign specific data to the inputs.
**arithmetic**: using a counter to provide data.
**periodic**: applying data at regular, timed, intervals.
**random**: applying randomly generated data.
**text**: loading stored data from a text file and applying to the design.

This is how the rough layout of a testbench looks like:

![[Pasted image 20251016180338.png#invert|600]]

- We declare input signals as either `wire` or `reg`
- Outputs are mostly `wire`

The testbench has no inputs or outputs as it is a self contained module.


## STUMP_ALU Example

Here is a look at how the testbench for the STUMP ALU looks.

```Verilog
module Stump_ALU_Testbench ();                 // Declare the test module: no I/O
reg  [15:0] operand_A;                    // Declare the variables at this level
reg  [15:0] operand_B;                    // 'reg' for values test assigns to
reg   [2:0] func;                         // (i.e. inputs to device)
reg         c_in;
reg         csh;
wire [15:0] result;                       // 'wire' for device's output values
wire  [3:0] flags_out;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Instantiate module under test                                              */
Stump_ALU ALU (.operand_A(operand_A),     // Instantiate a 'Stump_ALU'
               .operand_B(operand_B),     // called 'ALU'
	           .func(func),               // and connect its buses
	           .c_in(c_in),               // to signals of the same name
               .csh(csh),
	           .result(result),
	           .flags_out(flags_out));
```

1. First the module is defined, only brackets no inputs and outputs defined
2. The signals that will be used to connect to the design's inputs are instantiate
3. The signals that are then connecting to the outputs are instantiated
4. The STUMP ALU is then instantiated using structural Verilog, connecting the inputs and outputs to the signals we have defined within the testbench module

Now here is the logic for how we go through and provide the test data:

```Verilog
// Setup test data here rather than reading from files: easier for small sets
  A_in[0] = 16'h4000; B_in[0] = 16'h3FFF;   // Data for test #0
  A_in[1] = 16'h5000; B_in[1] = 16'h5000;   // etc.
  A_in[2] = 16'h4000; B_in[2] = 16'hBFFF;
  A_in[3] = 16'h4000; B_in[3] = 16'hD000;
  A_in[4] = 16'hC000; B_in[4] = 16'h4000;
  A_in[5] = 16'hD000; B_in[5] = 16'h2FFF;
  A_in[6] = 16'hC000; B_in[6] = 16'h9000;
  A_in[7] = 16'hC000; B_in[7] = 16'hBFFF;
  A_in[8] = 16'h8000; B_in[8] = 16'h8000;
  file_handle = $fopen("ALU_test_out.txt"); // Open a message output file
  $fdisplay(file_handle, "Outcome from Stump ALU tests\n"); // Output title
  for (func = 0; func < 6; func = func + 1) // Iterate over six function types
  begin
    case (func)
      0: $fdisplay(file_handle, "Testing ADD function");
      1: $fdisplay(file_handle, "Testing ADC function");
      2: $fdisplay(file_handle, "Testing SUB function");
      3: $fdisplay(file_handle, "Testing SBC function");
      4: $fdisplay(file_handle, "Testing AND function");
      5: $fdisplay(file_handle, "Testing OR  function");
      default: $fdisplay(file_handle, "Unknown function");
    endcase
    for (tst = 0; tst < 9; tst = tst + 1)   // Iterate over test data
    begin
      operand_A = A_in[tst];                // Set input buses
      operand_B = B_in[tst];
      for (k = 0; k < 2; k = k + 1)         // Iterate over (both) carry states
      begin
        if(func < 4)
        c_in = k;                           // Carry adopts LSB
      else
        csh = k;
      #100                                  // Pause so viewable as waveform
      display_state(result, flags_out);     // Write results to output file
    end
  end
  $fdisplay(file_handle, "");               // Blank line after each test block
  end
  #100;                                     // Extra pause before finishing
  $fclose(file_handle);                     // Close output file
  $stop;                                    // Tell simulator to stop
end
```


There are three `for` loops nested inside each other to generate all the test cases.

1. The outer loop: `func = 0; func < 6; func = func + 1) ...` this goes through each operation type,
2. The middle loop: `for (tst = 0; tst < 9; tst = tst + 1) ...` this loops through 9 times for each function and selects one of the 9 data pairs.
3. The inner loop: `for (k = 0; k < 2; k = k + 1) ...` This loop runs 2 times for each data pair, this sets carry-in to 0 on its first pass and then to 1 on its second.

## Automated Tests:

So instead of the designer having to compare the output results from a simulation with the expected output, we can design the testbench to do this for us with some 'Golden Data'.

![[Pasted image 20251016184242.png#invert|800]]
Here you just do the normal tests and compare the results you have produced with the 'Golden Data'.