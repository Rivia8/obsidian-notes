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
    void push(T item){
        this->vec.push_back(item);
    };

    bool isEmpty() const{
        // .empty() returns 1 if the vector is empty and 0 otherwise
        return this->vec.empty();
    };

    T peek() const{
        // Returns the item at the top of the vector WITHOUT REMOVING it from the internal vector.
        
        try {
            if (this->isEmpty()) throw std::out_of_range("This vector is empty");
            return this->vec[((this->vec.size()) - 1)];
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error has Occurred: " << e.what();
            throw;
        }
    };

    T pop(){
        // Returns the item at the top of the vector and REMOVES it from the internal vecotr.
        try {
            if (this->isEmpty()) throw std::out_of_range("This vector is empty");
            
            int pos = (int)(this->vec.size()) - 1;
            T element = this->vec[pos];
            this->vec.erase(vec.begin() + pos); // Erase resizes.
            return element; 
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error has Occurred: " << e.what();
            throw;
        }
    }
};

int main(){
    MyStack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    while (!myStack.isEmpty()){
        std::cout << "item: " << myStack.pop() << "\n";
    }
    
    return 0;
};