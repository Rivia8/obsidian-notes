25-03-2025 20:43

Tags: [[Java]]

# Method Overriding

Another way of achieving [[Programming Languages and Frameworks/Java/2. OOP/Methods#Method Overloading|polymorphism]] is by something called **method overriding.** 

The way this work is that we may have a subclass of a class, and this subclass may have different properties that we may want it to have, for example, a `BankAccount` class may have different account types as their subclasses. So if we want the subclass to have the same method name but have different actions occurring in that method we do something called **overriding**.

For example, let's say we have the regular `BankAccount` class that has the regular depositing and withdrawing functionality but now we want a separate bank account, like a gold account - let's call it the `GoldAccount` class.

We would want the same depositing method but with different functionality, like an overdraft, meaning instead of prevent withdrawals at $0 it could stop at $-100.

`BankAccount`:

```Java
public void withdraw(double amount){
	if (balance > 0) {
		balance -= amount;
    } else {
    System.out.println("Insufficient Funds");
    }
}
```


`GoldAccount`:

```Java
@Override
public void withdraw(double amount) {
	if (balance > -100) {
	balance -= amount;
	} else {
	System.out.printlb("Overdraft limit Reached")
	} 
}
```

We have introduced the `@Override` which is an example of Java annotations, expressed the by the '@' symbol. This tells the compiler that we are overriding a method from the superclass, this is actually not mandatory but it is good practice.

The methods have the same name and parameter list, the thing that distinguishes them is the object that they belong to:

```Java
// The parameters are regular examples (account num, name and balance)
BankAccount account = new Bankaccount("1234", "Regular Acc Holder", "$1000");
GoldenAccount goldAccount = new GoldenAccount("1234", "Gold Acc Holder", "1000");

account.withdraw(1000);
goldAccount.withdraw(1000);
```

Above you can see the difference as one calls the `withdraw()` method from the `account` object and the other with the `goldAccount` object.

