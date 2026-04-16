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

```C++
#include <memory>

void processItems() {
	
	std::shared_ptr<Item> item1 = std::make_shared<Item>("Sword"); // Created a shared pointer
	std::shared<Item> item2 = item1; // item2 now points to item 2

}
```

### Observer `std::weak_ptr<T>`

This is a specialised 'sidekick' to `shared_ptr`.
The problem with `shared_ptr`s is the fact that **Cyclic Dependencies** can occur. Two shared pointers can point to each other and their reference counters will never reach zero. To fix this you can have a `weak_ptr<T>`
Rule: a `weak_ptr` allows you to look at data owned by `shared_ptr` **without** increasing the reference count. It observes, but it does not own. Before you use a `weak_ptr` you have to ask it, "does the data you are pointing to exist or has it been deleted"


```C++
#include <iostream>
#include <memory>
#include <string>

// A simple Item class so we can track when it is created and destroyed
struct Item {
    std::string name;
    
    Item(std::string n) : name(n) {
        std::cout << name << " was created in memory.\n";
    }
    
    ~Item() {
        std::cout << name << " was destroyed and memory was freed.\n";
    }
};

void processItems() {
    // 1. Create the master shared pointer. (Reference Count = 1)
    std::shared_ptr<Item> item1 = std::make_shared<Item>("Sword");

    // 2. Create a second shared pointer. (Reference Count = 2)
    std::shared_ptr<Item> item2 = item1; 

    // 3. Create a weak pointer observing the sword. (Reference Count is STILL 2!)
    std::weak_ptr<Item> weakSword = item1;

    // --- USING THE WEAK POINTER ---
    
    // We try to access the sword by calling .lock()
    // This temporarily creates a shared_ptr named 'tempItem' inside the if-statement
    if (std::shared_ptr<Item> tempItem = weakSword.lock()) {
        std::cout << "Success! The weak pointer sees the: " << tempItem->name << "\n";
    } else {
        std::cout << "Failed. The item no longer exists.\n";
    }

    // --- DESTROYING THE ITEM ---
    
    std::cout << "\nDropping shared pointers...\n";
    item1.reset(); // item1 lets go of the sword
    item2.reset(); // item2 lets go of the sword. The sword is now destroyed!

    // --- USING THE WEAK POINTER AGAIN ---
    
    std::cout << "Trying to look at the sword again...\n";
    if (std::shared_ptr<Item> tempItem = weakSword.lock()) {
        std::cout << "Success! The weak pointer sees the: " << tempItem->name << "\n";
    } else {
        std::cout << "Failed. The item no longer exists.\n";
    }
}

int main() {
    processItems();
    return 0;
}
```
