10-04-2026 18:04

Tags: [[C++]]

In older C++ if you allocated a memory on the heap using `new` , you were responsible for calling `delete` to free it. If you forgot or the program crashed before reaching the `delete` statement, the memory was lost forever (aka a memory leak).

A smart pointer is a template class that wraps around a raw pointer. 
It acts exactly like a normal pointer (you can use `*` and `->`) but it automatically deletes the memory it points to when it goes out of scope.

C++ has three main types of smart pointers.

## Loner `std::unique_ptr<T>`

This is most common and fastest smart pointer. It works on the principle of **exclusive ownership**.
Rule: **Only one** unique pointer can point to a specific block of memory at a time.

```C++
#include <memory>

void processPlayer() {

	std::unique_ptr<Player> p1 = std::make_unique<Player>("Alice"); // Created a unique player
	
	std::unique_ptr<Player> p2 = p1; // This will cause an error.
	
	std::unique_ptr<Player> p2 = std::move<p1>; // This will work.

}

```
## Commuter `std::shared_ptr<T>`

Sometimes multiple parts need to share access to the same data.
Rule: Multiple `shared_ptr`s can point to the exact same block of memory. 

The way it works is that it has a counter and every time you copy the counter, the counter goes up by 1 and every time one is destroyed, the counter goes down by 1.
When the counter hits exactly `0`, the memory is deleted.

Because it has to maintain this counter, it is slightly slower and uses slightly more memory than a [[Smart Pointer#Loner `std unique_ptr<T>`|unique pointer]].

### Observer `std::weak_ptr<T>`

This is a specialised 'sidekick' to `shared_ptr`.
The problem with `shared_ptr`s is the fact that **Cyclic Dependencies** can occur. The reason this happens is because




