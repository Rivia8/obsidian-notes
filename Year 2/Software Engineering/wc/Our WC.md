12-11-2025 17:40

Tags: [[Software Engineering]]

# Our WC

## Week 3

The specification for our version of `WC` is as follows:.

1. There are no flag options.
2. The output is `linecount wordcount bytecount filepath` (each separated by `tab` characters)
3. There is exactly one filepath passed as an argument.
4. That path argument is not `stdin` (i.e., “-”)
5. It should handle errors as `wc` for things inside the spec. I.e., if `wc` would give an error for a one argument invocation, you should give the same error.

The user interface will be as follows:

`wc \<some file name which isn't '-'\>`

## Week 4

Next step in building a `wc` clone is to expand the functionality, we break the functionality into three basic chunks:
- Options,
- Input handling,
- Additional "Standard" counting (and extending the current functionality)
- Created one that has the basic `-Lwcl` handling

## Week 5

