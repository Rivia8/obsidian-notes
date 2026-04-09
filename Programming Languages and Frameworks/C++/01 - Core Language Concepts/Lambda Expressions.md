09-04-2026 09:33

Tags: [[C++]]

You use these to pass functions into algorithms easily.

A lambda is a function without a name that you write directly inside the line of code.

Here is the anatomy of the C++ lambda:

```C++
[captures](parameters) -> return_type { body }
```

The capture clause is unique to C++, because lambdas are defined *inside* other functions, they don't automatically know about the local variables around them.
The `{ body }` is the actual code to execute.

Here is an example:

```C++
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 12, 8, 20, 3};
    int threshold = 10;

    // We "capture" the threshold variable so the lambda can see it
    int count = std::count_if(numbers.begin(), numbers.end(), 
        [threshold](int n) { 
            return n > threshold; 
        }
    );
}
```

We can also use Ranges and Views so we no longer have to pass `begin()` and `end()` to every algorithm.





