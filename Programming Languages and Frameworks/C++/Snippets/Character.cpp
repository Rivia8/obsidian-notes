#include <string>
#include <iostream>

class Character{

    private:
        std::string name;
        int health;

    public:
        Character(std::string name, int health):
            name{name}, health{health} {};
        
};