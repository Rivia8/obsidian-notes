19-10-2025 22:31

Tags: [[Verilog]] 

# Sequential Systems without Datapaths

When we have looked at [[Sequential Systems]] we know that a sequential system does in fact **not need a datapath**.
The datapath is a *design* pattern that is used to manage complexity, not a fundamental requirement for all sequential logic.

When we don't have a datapath, the state machine is the entire system, the logic for control and the (very simple) data are all mixed together.

An example of a sequential system without a datapath is a [[Sequence Detector|sequence detector]].