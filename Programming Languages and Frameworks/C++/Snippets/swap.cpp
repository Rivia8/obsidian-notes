#include <string>
#include <iostream>


template <typename T>
class Box {
private:
    T contents;
public:
    Box(T item) : contents(item) {} // Constructor using initialization list!
    
    T getContents() {
        return contents;
    }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> stringBox("Treasure");

   std::cout << "hello";
}