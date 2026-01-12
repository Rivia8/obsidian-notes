26-05-2025 19:20

Tags: [[Java]]

# JCF

Java developers produced a group of [[Generics|generic]] collection classes that are incredibly useful.
The collections are organised around several collection interfaces that define types of collections that we might be interested in using, the three most important are:

- [[List - ArrayList|List]],
- [[Set - HashSet|Set]], 
- Queue,

![[Pasted image 20250815124228.png#invert]]



## Iterable

You can see at the top of the tree that we have the `Iterable` interface, its primary purpose is to provide a universal, standard way to loop through any collection.

It has only one required method: `Iterator()` so any class that implements `Iterable` is basically saying that "I am a container of items, and I can give you a special helper object (an `Iterator`) that will let you visit each of my items one by one"

We then also have an `Iterator` helper where the `iterator()` method returns an `Iterator` object, which has two main methods:
- `hasNext()`: Returns `true` if there are more items to visit.
- `next()`: Returns the next item in the sequence.

(This is the reason that the [[Control Structures#Enhanced For loop|enhanced for loops]] works on every collection in JCF)


