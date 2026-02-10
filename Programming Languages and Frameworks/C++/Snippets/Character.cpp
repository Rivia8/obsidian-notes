#include <string>
#include <iostream>

class Character{

    private:
        std::string name;
        int health;

    public:
        Character(std::string name, int health):
            name{name}, health{health} {};
        bool isAlive(){
            if (health > 0) {
                return true;
            } else {
                return false;
            }
        }
        void virtual attack() {
            std::cout  << "ATTACKING";
        }
        
};