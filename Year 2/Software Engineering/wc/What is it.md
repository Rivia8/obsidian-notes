12-11-2025 17:01

Tags: [[Software Engineering]]

# What is it

`wc` (short for **word count**) is a command in `Unix`, `Plan 9`, `Infernoo` and Unix-like operating systems.

The program takes as input a list of computer files or standard input and generates things like the newline count, word count and byte count.

In Ubuntu, Linux, The description states:

	Print  newline,  word,  and byte counts for each FILE, and a total line if more
       than one FILE is specified.  A word is a non-zero-length sequence of  printable
       characters delimited by white space.

       With no FILE, or when FILE is -, read standard input.

       The options below may be used to select which counts are printed, always in the
       following order: newline, word, character, byte, maximum line length.


When we produce our [[Our WC|own version]] of `WC` there are going to be strict conditions, this is going to limit the libraries that we can use and we're going to implement a *limited* set of functionalities.

