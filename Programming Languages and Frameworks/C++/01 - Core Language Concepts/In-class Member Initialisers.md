04-02-2026 12:56

Tags: [[C++]]

# Member Initialisers

This was introduced in C++11, this allows you to give a member variable a default value directly inside the class definition.

They are like **Factory Default Settings** for your variables. They provide a safety net so that variables are never uninitialised even if you forget to mention them in your constructor,

```C++
class Player {
    // In-Class Initializers
    int health = 100;       // Default health is 100
    std::string name = "Unknown"; // Default name
    float speed = 5.5f;     // Default speed
    
public:
    // ... constructors ...
};
```



