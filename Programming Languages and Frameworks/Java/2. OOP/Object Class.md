29-03-2025 22:10

Tags: [[Java]]

# Object Class

The `Object` class is the root of the Java hierarchy. This means that every Java class implicitly extends the `Object` class either directly or indirectly. This means that all Java classes automatically inherit methods and behaviour provided by the `Object` class (you do not need to manually extend it).

What this means is that when you create a Java class, you automatically inherit the methods defined in the `object` class:

1. `toString()` : Returns a string representation of the object.
2. `equals(Object obj)` : Compares the current object with another object.
3. `hashCode()` : Returns a hash code value for the object.
4. `getClass()` : Returns the runtime class of the object.
5. `clone()` : Creates and returns a copy of the object (if cloning is supported)
6. `finalize()` : Called before garbage collection to clean up the project.
7. `wait()`, `notify()`, `notifyAll()` : Used for thread synchronisation.


