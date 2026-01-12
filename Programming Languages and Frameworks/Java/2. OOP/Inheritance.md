24-03-2025 22:25

Tags: [[Java]]

# Inheritance

**Inheritance** is the process of **extending** existing classes by adding attributes and methods to them.

We take a class and then define other classes based on the first one. The new classes *inherit* all the attributes and methods of the first one and also have the attributes and methods of their own.



![[Pasted image 20250324223039.png#invert]]

Looking at figure **9.1** above, we can see that from the UML diagram that an inheritance relationship is hierarchal: 
- The class at the top is referred to as the **superclass**
- And the class below (here would be `PartTimeEmployee`) will be the **subclass**

## Implementing Inheritance

Let's try to implement the UML notation above:

For the `Employee` class we have:

```Java
public class Employee
{ 
	private String number;
	private String name;
	public Employee(String numberIn, String nameIn)
	{ 
		number = numberIn;
		name = nameIn;
	}
	 
	public void setName(String nameIn)
	
	{ 
		name = nameIn;
	}
	 
	public String getNumber()
	{ 
		return number;
	} 
	public String getName()
	{ 
		return name;
	} 
}

```

For the `PartTimeEmployee` class we have:

```Java
public class PartTimeEmployee extends Employee // this class is a subclass of Employee
{
	private double hourlyPay; // this attribute is unique to the subclass
	
	// the constructor
	public PartTimeEmployee(String numberIn, String nameIn, double hourlyPayIn)
	{
		super(numberIn, nameIn); // calls the constructor of the superclass
		hourlyPay = hourlyPayIn;
	}
	// these methods are also unique to the subclass
	public double getHourlyPay()
	{
	return hourlyPay;
	}
	public void setHourlyPay(double hourlyPayIn)
	{
	hourlyPay = hourlyPayIn;
	}
	public double calculateWeeklyPay(int noOfHoursIn)
	{
	return noOfHoursIn * hourlyPay;
	}
} 
```

The point of interest in the `PartTimeEmployee` class is the first line:

```Java
public class PartTimeEmployee extends Employee
```

The keyword `extends` means that the class (in this case now would be the subclass) will inherit all the attributes and methods of the `Employee` class, (the superclass).

The new **problem** that arises with this is the fact that the attributes in the superclass are declared as **private**, this means that no other classes' methods can access them directly.
A solution could be to make the attributes public but that would negate the idea of encapsulation.
We could however, use the **protected** modifier, this makes the attributes accessible to the methods of any subclass. It however weakens the encapsulation since the attributes can also be accessible to any other class in the same **package**.

```Java
public class SuperClass {
    protected int value; // Accessible in subclass
}

public class SubClass extends SuperClass {
    public void display() {
        System.out.println("Value: " + value);
    }
}
```


**Another** way to deal with this is what was actually implemented in the `PartTimeEmployee` subclass above:

```Java
public PartTimeEmployee(String numberIn, String nameIn, double hourlyPayIn)
	{
		super(numberIn, nameIn); // call the constructor of the superclass
		hourlyPay = hourlyPayIn;
	}
```

Here the superclass' constructor was called using the keyword `super` - this ***MUST*** be the the very first line of code and its a strict rule by the Java compiler.