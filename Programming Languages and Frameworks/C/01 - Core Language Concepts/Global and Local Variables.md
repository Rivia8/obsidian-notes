17-10-2025 15:06

Tags: [[C]]

# Global and Local Variables

Local variables are visible **only** from within the context the are declared in, so that could be a function, a loop body etc.

Global variables are declared outside functions, they can be read or written from everywhere in the sources.

```C
int global_var;
void add_to_global_var(int value) {
    global_var = global_var + value;
}
int main() {
    global_var = 100;
    add_to_global_var(50);
    printf("global_var is %d\n", global_var);
    return 0;
}
```

Global variables can be problematic when it comes to reasoning with the program and can cause issues so they must be used wisely.

## Scope and Lifetime

Local variables are visibly within the enclosing block of code and delimited with braces.


```C
int x = 12;
if(x) {
    int y = 14;
    printf("inner block, x: %d\n", x);
    printf("inner block, y: %d\n", y);
}
printf("outer block, x: %d\n", x);  // working: x is in scope
printf("outer block, y: %d\n", y);  // error: y only visible in the if body

for(int i=0; i<10; i++) {
    printf("In loop body, i is %d\n", i); // working, i is in scope
}
printf("Out of loop body, i is %d\n", i); // error, i only visible in loop body

int j;
for(j=0; j<10; j++) {
    printf("In loop body, j is %d\n", j); // working
}
printf("Out of loop body, j is %d\n", j); // working, j in scope

```
