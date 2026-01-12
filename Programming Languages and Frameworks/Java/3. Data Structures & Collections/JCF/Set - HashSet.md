26-05-2025 22:05

Tags: [[Java]]

# Set
**No** guaranteed ordered, with **no** **duplicate** elements. To access elements you usually use `contains()` in the set or iterate through elements.

# HashSet

**ArrayLists** are like ordered sequence of items in numbered slots, a `Hashset` is like a bag of unique items where order does not matter and you can quickly check if something is in the bag.

Like `List` the `Set` interface is a specialised version of the general `Collection` interface. The `Set` interface defines the methods required to process a collection of object in which there is **no** duplicated items and ordering is **unimportant**.

There are three implementations of the `Set` interface: 
1. `HashSet`
2. `Tree-Set`
3. `LinkedHashSet`

To instantiate a `HashSet` we do:

```Java
Set<String> myHashSet = new Hashset<>();
```

It allows `null` values but just **one**. 
Like `ArrayList`, `HashSet` is **not synchronised** so it **not** thread safe, so if you want multiple threads to access `HashSet` concurrently, you would need to handle synchronisation externally.

## Set Methods

1. `.add()` method - to add items to the set,
2. `.remove()` method - to remove items from the set, it removes the item that is that is specified if it is in the set, e.g.
```Java
myHashSet.remove("DISHWASHER");
```


## Iterator Object

An `Iterator` object allows the items in a collection to be retrieved by providing three methods defined in the `Iterator` interface.
To obtain an `Iterator` method for a specific set, we do this:

```Java
Iterator<String> elements = myHashSet.iterator();
```

In the generics syntax (<>) we denote that the iterator will iterate over strings.

### Iterator Methods

1. `hasNext` - returns true if there are more elements in the collection to retrieve and **false** otherwise
2. `next` - retrieves one element from the collection,
3. `remove` - removes from the collection
4. `forEachRemaining` - performs the given action for each remaining element until all elements have been processed or the action throws an exception.

Example of usage:

```Java
// First creating an iterator object
Iterator<String> elements = myHashSet.iterator();

while (myHashSet.hasNext()){
	String item = myHashSet.next() // retrieves next element from the set
	if (item.charAt(0) <= 'T'){ // checks first letter  
		myHashSet.remove(); 
	}
}
```