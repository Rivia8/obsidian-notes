13-08-2025 19:14

Tags: [[Java]]

# Error Handling Philosophies

When it comes to handling errors, there are 3 main philosophies:
1. Look before you leap **(LBYL)**,
2. Easier to Ask Forgiveness than Permission **(EAFP)**,
3. Time of Check, Time of Use.

## LBYL

The way this works is self-explanatory, what pretty much happens is that you check **before** you do something, like checking a value isn't a null before using it in a method etc.

```Java
if (lbyl.getX() != null) {
	System.out.println(
	lbyl.getX().toUpperCase()
	);
}
```

## EAFP

With this we kind of allow the error to happen, so the computing goes ahead with the 'invalid data' and we use we kind of deal with it then.

```Java
try {
	System.out.println(
	eafp.getX().toUpperCase()
	);
} catch (NullPointerException e) {}
```


## Typically for Java

Typically for Java we use the LBYL coding style but that isn't always enough, we need error handling too.


