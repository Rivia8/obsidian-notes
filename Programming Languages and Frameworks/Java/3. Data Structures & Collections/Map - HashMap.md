27-05-2025 10:45
	
Tags: [[Java]]

# Map

The `Map` interface does **NOT** inherit from the general `Collections` interface. 
The `Map` interface is separate from this group and defines the methods required to process a collection consisting ***pairs*** of objects.

So it contains **key-value** pairs.

If `List` is an ordered sequence and `Set` is a bag of unique items, then a `Map` is like a dictionary or a **phonebook:** it stores data as key-value pairs, where each unique **key** maps to a single value.

Each key in a `Map` is unique. If you try to put a value with an existing key, the old value associated with that key is replaced. So each key maps at most **one value**.

# HashMap

A `HashMap` is the most common and widely used implementation of the `Map` interface that uses a hash table for storage.

It stores key-value Pairs:
- The primary function. You `put(key, value)` pairs into it, and you get `get(key)` to retrieve the associated value.
- Example: A map of student IDs to student names: `myStudents.put(101, "Alice");`

Unique keys but duplicate values allowed:
- You cannot have duplicate keys, but you can have different keys that are mapped to different values.
- If you were to `put()` a new value with a key that already exists, the old value associated will be replaced by the new one.

Unordered collection of entries
- `HashMap` does not guarantee any specific order of its key-value pairs. The order can change over time. If you need order, `LinkedHashMap` (for insertion order) or `TreeMap` (for sorted key order) are alternatives.

Allows `null` keys and `null` values
- A `HashMap` allows one `null` key and multiple `null` values.


## Usage

In order to declare a `HashMap` you put the key type and the value type within the generic brackets:

```Java
Map<String, Double> productPrices = new HashMap<>();
```
Here we have defined a `HashMap` with the key  of type string and the values of type double.

To add element we use the `put()` method:

```Java
productPrices.put("Laptop Pro", 1200.00);
productPrices.put("Java Book", 45.50);
productPrices.put("Wireless Mouse", 25.00);
productPrices.put("Gaming Headset", 99.99);
```

To get the value of a key:

```Java
double laptopPrice = productPrices.get("Laptop Pro");
System.out.println("Price of Laptop Pro: " + laptopPrice); // Output: 120.00
```

### When to use HashMaps:

- You need to store data as key-value pairs,
- You need very fast average-time performance for adding, retrieving and removing entries based on their key,
- The order of entries does not matter, 
