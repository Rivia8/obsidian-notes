16-10-2025 21:55

Tags: [[C]]

# Command Line Arguments

Command line arguments are [[Programming Languages and Frameworks/C/01 - Core Language Concepts/Strings|strings]] passed on the command line when we invoke a program.

When we code a program we have the main function which is declared with 2 parameters:
- `argc`
- `argv`

Lets look at an example:

```C
int main(int argc, char *argv[]){
	// code goes here
	return 0;
}
```

- `int argc` is the argument count, it holds the count of command-line arguments
- `char *argv` is the argument vector, this is an array of strings where each string is one of the arguments

Lets say we hade a program called 'my_program', and entered the following into a terminal:
```Bash
./my_program hello world 123
```

`argc` will be 4:
- `./my_program`
- `hello`
- `world`
- `123`

`argv` will be an array of 4 strings:
- **`argv[0]`** will be a pointer to the string `"./my_program"` (the program name).
- **`argv[1]`** will be a pointer to the string `"hello"`.
- **`argv[2]`** will be a pointer to the string `"world"`.
- **`argv[3]`** will be a pointer to the string `"123"`.

