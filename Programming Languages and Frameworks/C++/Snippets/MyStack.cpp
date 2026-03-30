// Generic data Structure: vec
// LIFO container

#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T>

class MyStack{

    private:
        std::vector<T> vec; // Standard vector to focus on logic and not the sizing.

    public:
    void push(T item) {
        this->vec.push_back(item);
    }

    bool isEmpty(){
        // .empty() returns 1 if the vector is empty and 0 otherwise
        return this->vec.empty();
    }

    T peek(){
        // Returns the item at the top of the vector WITHOUT REMOVING it from the internal vector.
        
        try {
            return this->vec[((this->vec.size()) - 1)];
            throw std::out_of_range("The vec is empty"); 
        }
        catch (int errorCode) {
            std::cout << "Error has Occurred: " << errorCode;
        }
    }

    T pop(){
        // Returns hte item at the top of the vector and REMOVES it from the internal vecotr.
        try {
            int pos = (this->vec.size()) - 1;
            T element = this->vec[pos];
            this->vec.erase(pos); // Erase resizes.
            return element;
            throw std::out_of_range("The vec is empty"); 
        }
        catch (int errorCode) {
            std::cout << "Error has Occurred: " << errorCode;
        }
    }
};

int main(){
    MyStack<int> MyStack;
    MyStack.push(10);
    MyStack.push(20);
    MyStack.push(30);

    while (!MyStack.isEmpty()){
        std::cout << "item: " << MyStack.pop();
    }
    
    return 0;
};