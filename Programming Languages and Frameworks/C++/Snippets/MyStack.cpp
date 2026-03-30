// Generic data Structure: Stack
// LIFO container

#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T>

class MyStack{

    private:
        std::vector<T> stack; // Standard vector to focus on logic and not the sizing.

    void push(T item) {

    }

    bool isEmpty(){
        // .empty() returns 1 if the vector is empty and 0 otherwise
        return this->stack.empty();
    }

    T peek(){
        // Returns the item at the top of the stack WITHOUT REMOVING it from the internal vector.
        
        try {
            return this->stack[0];
            throw std::out_of_range("The stack is empty"); 
        }
        catch (int errorCode) {
            std::cout << "Error has Occurred: " << errorCode;
        }
    }

    T pop(){
        // Returns hte item at the top of the stack and REMOVES it from the internal vecotr.
        try {
            T element = this->stack[this->stack.size() - 1];
            return element;
            throw std::out_of_range("The stack is empty"); 
        }
        catch (int errorCode) {
            std::cout << "Error has Occurred: " << errorCode;
        }
    }

}