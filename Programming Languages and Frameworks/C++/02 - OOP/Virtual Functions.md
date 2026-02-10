10-02-2026 17:03

Tags: [[C++#]]

# Virtual Functions

In C++, if you point to an object using a pointer that is for the parent object, e.g. `Shape*` and you have `Circle` and `Square` objects. The compiler will get confused, since it looks at the **pointer's** type and not the actual object type.

Here's a look at an example but with the structure of `Enemy` and `Dragon':

```C++
class Enemy {
public:
    void attack() { std::cout << "Enemy attacks!"; }
};

class Dragon : public Enemy {
public:
    void attack() { std::cout << "Dragon breathes fire!"; }
};

int main() {
    Enemy* e = new Dragon(); // We create a Dragon, but hold it as an Enemy
    
    e->attack(); 
    // OUTPUT: "Enemy attacks!"
    // WAIT... Why? It's a dragon!
}
```

The reason this failed is because the compiler decided that before the *program even* ran (at compile time) which function call, it just saw that `e` is an `Enemy*`, so it hard coded a call to `Enemy::attack()`. It ignored the fact that it was actually pointing to a dragon.

To fix this problem we utilise **virtual functions**, you label the parent class with `virtual` which gives the compiler a specific instruction:
"Do **not** hard-code this function call. When the program runs, check what the object **actually** **is** first, and *then* call *that* object's version of the function".

To fix the above code you would have the following:

```C++
class Enemy {
public:
    // 'virtual' tells C++ to check the real object type at runtime
    virtual void attack() { std::cout << "Enemy attacks!"; }
};

class Dragon : public Enemy {
public:
    // 'override' confirms we are replacing the parent's version
    void attack() override { std::cout << "Dragon breathes fire!"; }
};

int main() {
    Enemy* e = new Dragon(); 
    
    e->attack(); 
    // OUTPUT: "Dragon breathes fire!" 
    // SUCCESS!
}
```


