11-11-2025 10:00

Tags: [[Processor Microarchitecture]]

# Transaction Level Modelling

**Transaction Level Modelling (TLM)** is a high-level approach to designing and simulating complex digital systems, like a full system-on-a-chip (SoC).

TLM is quite different to [[Register Transfer Level|Register Transfer Level Modelling (RTL Modelling)]] in the sense that the engineer doesn't have to deal with all the nitty gritty components - <mark class="hltr-purple">instead of modelling every wire and clock tick, TLM models the system's behaviour as a series of **data transfers**, which are called **transactions.**</mark>

	A transaction could be the sending ofa  reques tto read a memory at some addressl; another may be returend which is the desired data.

The core problem TLM solves is **simulation speed.**
If we only utilised RTL for simulating the ***STUMP*** processor, plus a graphics processor, a USB controller, a NIC, and 8 GB of memory; simulating every single clock tick for every component would take days or weeks on a fast computer to simulate.

With TLM we just model the data packets: the CPU sends a transaction and then the memory controller receives it and responds. In RTL this transaction might take 50 clock cycles, but in TLM it takes *zero time*.

## Transactions

A "transaction" is simply a bundle of information that represents a complete data transfer. It's a high-level concept, usually implemented as a function call in a language like SystemC.

A transaction contains the essential information:
- **Command:** Is this a `READ` or a `WRITE`?
- **Address:** Where is the data going or coming from?
- **Data:** The actual data payload.
- **Length:** How much data?
- **Status:** Was the transfer `OK` or did it `ERROR`?


