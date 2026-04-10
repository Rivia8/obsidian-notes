09-04-2026 09:51

Tags: [[C++]]

A view is a specific type of [[Ranges|Range]]. 

Views have three properties:

- Non-owning
- Non-mutating
- Cheap to copy (creating, copying, or passing a view takes $O(1)$ time

 Views use lazy evaluation. So when you attach a view to a container, no calculation happens. The view simply remembers the instruction and the Maths only executes at the exact moment you ask for the data.

Here is an example:

```C++
#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto pipeline = numbers 
        | std::views::filter([](int n) { return n % 2 == 0; }) // Keep evens
        | std::views::transform([](int n) { return n * n; })   // Square them
        | std::views::take(3);                                 // Just grab the first 3

    // The calculation ONLY happens here!
    for (int result : pipeline) {
        std::cout << result << " "; 
    }
    // Output: 4 16 36
}
```

