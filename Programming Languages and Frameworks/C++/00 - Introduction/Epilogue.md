17-04-2026 16:32

Tags: [[C++]]

C++ has some fundamental flaws, it is shackled by 40-50 years of backwards compatibility that it has to maintain and it has to support design choices made for ancient hardware and compilers.

Unrestricted raw pointers *were* great for writing operating systems in the 1980s but they are a massive liability: they confuse modern compilers, actively preventing advanced automatic optimisations and parallelisation. 

Rust is currently the industry's favourite answer to C++'s flaws. 
Its incredibly fast supports impertavie/generic/functional styles, zero cost abstractions and uses **RAII** without needing a Garbage Collector.
- It does this stopping you from compiling unsafe memory operations, it enforces strict "ownership" and "lifetimes" at  compile-time, completely eliminating data races and memory leaks by default 





