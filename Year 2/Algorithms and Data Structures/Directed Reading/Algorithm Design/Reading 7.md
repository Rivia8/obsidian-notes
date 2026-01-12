03-12-2025 12:44

Tags: [[Algorithms and Data Structures]]

# Reading 7

Reading for week 7 includes:
Pages 188-205, skipping 196-197

# Part I Data Structures

## Chapter 6 Hash Tables

If you were to create a router that requires the packets to be modelled as a pair $(k,x)$, where $k$ is a key that indicates its destination and $x$ is the data contained in this packet. A system needs to be created in order to maintain these packets a system meaning a collection so you know what to do, the system will need two operations, `put` and `get`. We *could* use a LinkedList but that would mean that the `get()` function would be $O(n)$ since it would require you to go through the entire number of items. So instead we use a **hash table**. 
The data structure is able to achieve $O(1)$ expected time for both `get` and `put` operations.

### 6.1 Maps

The main idea of the hash table that it allows users to assign keys to elements and then use those keys later to look up or remove elements. This functionality is what we know as a **dictionary** or **map**. The structure supports methods for the insertion, removal and searching of values.

**Definition of Map:** a map stores a collection of key-value pairs $(k,v)$, which we call *items*, where $k$ is a key and $v$ is a value that is associated with that key.
In most cases we want unique key-value pairs in the sense that a key can only have one value and there are no two same keys.

**Fundamental Methods of the Map Structure, $M$:**
$get(k)$: if $M$ contains an item with key equal to $k$, then return the value of such an item; else return NULL.
$put(k,v)$: Insert an item with key $k$ and value $v$; if there is already an item with key $k$, then replaces its value with $v$.
$remove(k)$: Remove from $M$ an item with key equal to $k$, and return this item. If $M$ has no such item, then return the special element NULL.

The special element of NULL is known as a sentinel.

Map can support other methods like `size()` and `isEmpty()` for containers. 

#### Lookup Tables:

In some cases, the universe of keys that will be used for the map is the set of Integers in the range $[0, N-1]$ for a reasonably small value of $N$. In this case there is a simple way to implement a map, namely we can allocate an array, $A$, of size $N$ where each cell of $A$ is though of as a "bucket" that can hold a single-key element pair.

This way of implementing a map is called a *lookup* table since the key $k$ allows us to simply "look up" the item for $k$ by a single array-indexing operation.

The analysis of the performance of a lookup table simple, each of the essential map methods runs in $O(1)$ time in worst case. There are some drawbacks, in terms of space usage for a lookup table it is: $\Theta(N)$. If $N$ is is large relative to $n$, then one drawback of this implementation is that it is wasteful of space.
What is $N$ and $n$ in this instance:
- $n$ is the number of items, this is how many actual key-value pairs there are,
- $N$ is the maximum possible value of a key, because this a "look-up" table if an employee has an ID number of 999, you **must** allocate an array slot at index 999 to store them.
What its basically saying is that if you want a certain value as a key, you need to have that stored but this can be wasteful in the sense that if you have 3 employees with the IDs 3, 99 and 500, even though $n$ is only three you will need 500 buckets if you want the key of 500. So it would be nice to have ***mechanisms*** to overcome these drawbacks while still achieving simple and fast methods for implementing the essential operations for map.

## 6.2 Hash Functions

If we cannot assume that keys are unique integers, we need something like a lookup table, for storing key-value pairs. We need a function that allows us to convert things like Strings into integers, a, $h$, hash function. The main idea is to use the hash value, $h(k)$ rather than the key, $k$, itself as the index. This allows us to manipulate the size of the array to our liking.

One complication that doing things like this causes is that we will have collisions but we say that a hash function is good if it maps keys to prevent these collisions.

The standard convention for hash functions is to view keys in one of two ways:
1. Each key, $k$, is a tuple of integers,
2. Each key, $k$, is a nonnegative integer.
The way this idea is utilised is like if our keys are character strings, then its most natural to view such keys as tuples and if our  keys are fixed-length IP-addresses of destination domains on the Internet, then it is probably most natural to view them as single integers.

### Summing Components

This is for the first convention mentioned above. We could sum up the different components in each key, for example if we have an IP address of 192.168.0.1 we could have $192+168+0+1=361$ and then do **modulo** $p$ where $p$ is the table size to fit it into the array. The drawback of this though is that it is symmetric, meaning the order doesn't matter in the sense that you could have the IP address (even though not legit) of 168.192.1.0 it would result in the same bucket.
We *could* use **XOR** method where we **XOR** all the value together, however this can cause some **bit deletion** since the XOR of a number and itself is always 0.

A better hash code would be one that somehow takes the position of characters into consideration.

### Polynomial-Evaluation Functions

This is an alternative hash code which takes position into consideration. We choose a non-zero constant $a$ and use as a hash function the following:
![[Pasted image 20251207154124.png#invert|700]]
There has been experimental studies that suggest that 33, 37, 39 and 41 are good choices for $a$ when working with character strings that are English words. Using said numbers produced less than 7 collisions in each case.

## 6.3 Handling Collisions and Rehashing

The main idea of a hash table is to take a lookup table, $A$, and a hash function $h$, and use them to implement a map by storing each item $(k,v)$ in the bucket $A[h(k)]$, however if we have two keys such that $h(k_1) = h(k_2)$ we have collisions that prevents us from just inserting a new item directly into the bucket.

### Separate Chaining

A simple and efficient way for dealing with collisions is to have each bucket store a reference to a set that stores all the items that the hash function has mapped to the bucket in a linked list. So we have each bucket $A[i]$ store a reference to a set, $S_i$.  

![[Pasted image 20251208132851.png#invert|200]]
Above is a simple representation of this, this has hash table of size 13 storing 10 integer keys with collisions resolved via the chaining method. The hash function in this case is $h(k) = k \mod 13$. 

An insertion will put the item at the beginning of said linked list in $O(1)$ time, and find will be $O(n)$, the reason we get away with this is that the hash function will usually spread said items around to the point that most buckets will have a few items. 

If we want to analyse Separate Chaining if we let $X$ be a random variable representing the number of items that map to a bucket, $i$, in the array $A$, then the expected value of $X$: $$E(X) = \frac{n}{N}$$ 
where $n$ is the number of items in the map and since each of the $N$ locations in $A$ is equally likely for each item to be placed. What this is saying is on average, how long is the list in any given bucket. If you have $n$ items and $N$ buckets, and assign the items randomly to the buckets, the average number of items in buckets is $\frac{n}{N}$, this is known as the Load Factor. So if you keep $\frac{n}{N} \approx 1$ then  $O(n)$ will be $O(1)$ since there is roughly one item in each bucket.

### Open Addressing

Separate chaining is nice since it is simple but it requires the use of auxiliary data structures - the Linked List. We can just make it so that each item is always stored in its own bucket, but how we resolve what to do when there is collision can be a bit challenging.

#### Linear Probing

One of the simplest ways of dealing with open addressing is **linear strategy**. In this strategy what we do is try to insert an item into a bucket and if that bucket is already occupied then we try the next and then if that's occupied we try the next and so on.

![[Pasted image 20251208143519.png#invert]]

This also means we need to change how perform $get(k)$ since the key will map to a number that isn't $k$ so we need to examine the following keys until a match is found.
The problem with Open Addressing is that you can't just delete items, if you look at the example above, if you were to delete 37 in slot 6 and set it to NULL it would break the chain for you to retrieve 16. This is why you need to shift everything back. However, you cannot blinding shift it back since it may cause problems.

An alternative is to have a 'Tombstone'. Instead of physically shifting elements which is complex and slow, you just replace the items you have deleted with a special flag `DELETED` and so if you see the said marker you can just carry on going (for a $get(k)$ operation) and for an insert operation treat it as empty and overwrite it.

We can use one of the **Chernoff bounds** to analyse linear probing:
![[Pasted image 20251208145155.png#invert|400]]
The Chernoff Bound is a statistical tool that is a "Tail Bound": *what he says is that the probability of a sum of random variables deviating far from the average drops exponentially fast.*
So we expect items to spread out evenly and in the extreme event a huge number of items will all decide to land in the same small chunk of the array. Chernoff proves that the extreme event is so unlikely that we can assume it basically never happens for large inputs.

Linear probing saves space, but it complicates removals also if the load factor of the hash table goes too high, then the linear-probing collision-handling strategy tends to cluster the items of the map into contiguous runs.

#### Quadratic Probing

This is another open-addressing strategy, it involves iteratively trying the buckets $A[i +f(j)] \mod N]$, for $j = 0, 1, 2, ...,$ where $f(j) = j^2$ until finding an empty bucket. Its similar to linear probing in the sense that overcomplicates the removal operation but has the main difference of it avoids clustering patterns that occurs with linear probing.

When the load factor approaches 1, it creates its own kind of clustering, called secondary clustering, where the set of filled array cells "bounces" around the array in a fixed pattern. This is because if $N$ is a prime, then the quadratic probing may not find an empty bucket even if one exists. 

#### Double Hashing

This is another method of open-addressing that does not suffer from the same clustering issues that **quadratic** and **linear** probing have to deal with. 
In this approach we choose a **second** hash function $h'$, and if $h$ maps some key $k$ to a bucket $A[i]$ with $i = h(k)$ that is already occupied, then we iteratively try the buckets $A[(i+f(j))] \mod N$ for $j = 1, 2, 3, ...,$ where $f(j) = j \cdot h'(k)$. In this scheme, the secondary hash function is not allowed to evaluate to zero.

This is kind of complex but pretty much "Every key has its own unique starting spot AND its own unique jump size".
The logic is simply:
the logic is simply:
1. **Attempt 0:** Go to $h(k)$. (Is it full?)
2. **Attempt 1:** Go to $h(k)+1×h'(k)$. (Is it full?)
3. **Attempt 2:** Go to $h(k)+2×h'(k)$. (Is it full?)

The reason why $h'(k)$ cannot evaluate to zero is that if it did it would cause an infinite loop.
Another thing is that $N$ should be a prime number. This is because if your step size and table size share a common factor, you will only visit a fraction of the slots. (e.g. if table size = 10 and step size = 2, you will only visit half - 0, 2, 4, 6, 8, 10). By making $N$ a prime number, it ensures that any step size (other than 0 and $N$ itself) will result in an eventual visit to **every** slot in the table before repeating.

### Chaining vs Open Addressing

If the Load Factor < 1/2 Open Addressing wins. Since the table is half-empty collisions are rare. Open Addressing is faster because it stays inside the array (better "cache locality") and doesn't need to chase pointers or allocate new memory for list nodes.

If Load Factor $\approx$ 1 Chaining wins. As the table gets full, Open Addressing gets exponentially worse whereas chaining degrades gracefully - you just add another node to the list. Double Hashing will simply just stop working entirely if the table is %100 full.

### Rehashing

The **load factor**, $\frac{n}{N}$ which is the ratio of the number of items in a hash table $n$ and the size of the table $N$. The load factor directly correlates to the probability that a newly inserted table will collide with an existing item. We should always keep the load factor bounded and below a small constant that is less than 1.
The way we can do this if the load factor *were* to exceed the constant is by additional work of course but it would normally ensue the process of increasing the size of the array and having a new hash function - rehashing.
![[Pasted image 20251208161652.png#invert|400]]
