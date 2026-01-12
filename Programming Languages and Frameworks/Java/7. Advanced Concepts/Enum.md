28-05-2025 18:17

Tags: [[Java]]

# Enumeration Type

The `enum` type is a special type of class that represents a fixed set of name constants.

Before `enum` types, `public static final int` constants were employed to represent fixed set of values:

```Java
public class DayOfWeekLegacy {
    public static final int SUNDAY = 0;
    public static final int MONDAY = 1;
    public static final int TUESDAY = 2;
    // ... and so on
}

// Usage:
int today = DayOfWeekLegacy.MONDAY;
if (today == DayOfWeekLegacy.SUNDAY) {
    // ...
}
```

Whereas we now can use `enum` types to do the job better and more efficient.

The `enum` type in Java is a **class** that represents a group of related, named constants. Each constant in an `enum` is actually an object of the `enum` type.

For an example:

```Java
public enum DayOfWeek {
	SUNDAY, 
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
}
```

We can also have data for the `enum` which is associated with each constant.

```Java
public enum CoffeeSize {
	SMALL(8, "S"),
	MEDIUM(12, "M"),
	LARGE(16, "L"),
	EXTRA_LARGE(20, "XL");

	// Here it declares the value types above in order for the program to know.
	private final int ounces;
	private final String abbereviation;

	CoffeeSize(int ounces, String abbreviation) {
		this.ounces = ounces;
		this.abbreviation = abbreviation;
	}

	public int getOunces(){
		return ounces;
	}

	public String getAbbreviation() {
		return abbreviation;
	}

	public String getDescription() {
		return "This is a " + name().toLowerCase() + " size, which is " + ounces + " ounces (" + abbreviation + ").";
	}
}
```


**Key Point**: For an `enum` the objects are created automatically by Java from the moment the program starts.

## Usage:

Use `enum`s whenever you have a fixed set of constants that:

- **Are related logically.**
- **Will not change frequently.**
- **Need to be type-safe.**
- **Could benefit from having associated data or behaviour.**