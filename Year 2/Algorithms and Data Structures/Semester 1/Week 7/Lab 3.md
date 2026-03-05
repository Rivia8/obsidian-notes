08-12-2025 23:09

Tags: [[Algorithms and Data Structures]]

# Lab 3

## Part A 

**Collision strategy**: Going to implement **Double Hashing** as the default mode, 0. 
**Hash Function:** Will use polynomial rolling hash, it is superior to ASCII summation as 'bat' will not be equal to 'tab' - takes position of letters into consideration.
**Stats:** Accurately track collisions, rehashes, and the average collisions per insert.


```Python
def hash_function(self, value):
	...

def load_factor(sellf):
	...

def insert(self, value):
	...

def rehash(self):
	...
```

***What did you implement as your hash function (this should include a formal description of the hash function – this might be a formula or some pseudo-code. It should not be an actual snippet of your code, you should be able to describe the hash function in a more abstract way)? How “good” is it (justify your answer)? If you have implemented more than one hash function then this should describe the hash function used in mode 0 and the one that is used first, if you are using double hashing as your collision resolution strategy. (No more than 200 words)***

I have implemented a Polynomial Hash instead of interpreting the numbers to its ASCII values alone which would cause collisions with anagrams. A Polynomial Rolling Hash allows us to do this by my multiplying each value with a constant value, x, raised to a power that depends on its position (positional weighting).
H_i = H_i-1 * 31 + ASCII(k\[i]) mod m. This function is considered 'good' because it achieves uniform distribution of keys and the choice of having the multiplier, x, as 31 is important as stated in Introduction to Algorithms: using a prime number near the number of characters in the alphabet helps minimise clustering. Also taking the modulo of a prime table size will further reduce the likelihood of collisions due to the patterns in the data distributions. This efficiency was confirmed in the experimental results: when running the large dictionary test the print_stats() method showed an average collision rate of 1.567 per insert, demonstrating the effective distiribution of the hash.

--- 
***What is your collision resolution strategy? What are the advantages and disadvantages of this strategy (this should include any factors that should be considered in the implementation for it to be correct (e.g., limitations on the choices for hash table size or hash function))? How do find and insert for hash sets work using this strategy? How have you implemented them? Illustrate your explanation with samples of your code - this may be tided up a bit for presentation but should clearly be the same as the code you have submitted and should cover the the operation of collision resolution, and how it is used by both find and insert (No more than 300 words, not counting the code snippets)***

The collision strategy that I had implemented was the Double Hashing Open Addressing method. This uses two distinct hash functions to determine the probe sequence. If a collision occurs at the primary index h1 the algorithm uses a second hash function h2 to determine the step size for probing. One of the rules outlined in "Algorithm Design" was that the secondary hash function could never equate to 0, if it did it would cause an infinite loop and so to prevent this, I implemented h2 as: h2(k) = 1 + (hash(k) mod(m-1)).

Double hashing is considered one of the best methods for open addressing because it minimises primary clustering, a flaw prominent in linear probing and secondary clustering.
Disadvantages of Double Hashing are that the implementation is computationally more expensive than linear (and quadratic) probing due to the second hash calculation. Also, it depends on the table size, m, being prime to ensure that the step size calculated by the second hash isn't a factor of m so that it ensures it visits all slots.

Both insert and find compute h1 and h2 identically in the sense that Insert probes until an empty slot is found: 
```Python
while self.table[index] is not None:
        if self.table[index] == value:
            return # Duplicate found
        
        # Double Hashing Step
        index = (index + h2) % self.hash_table_size
        
        if index == start_index: return # Table full safety check
```
and Find probes using the same sequence, and if it encounters None the element does not exist:
```Python
while self.table[index] is not None:
        if self.table[index] == value:
            return True # Found
        
        # Must match insert probe sequence exactly
        index = (index + h2) % self.hash_table_size
        
        if index == start_index: return False
```

--- 

***Did you implement rehashing? If so briefly explain your implementation including explaining*** ***when you choose to rehash. (No more than 200 words, not counting any code snippet included)***

I implemented rehashing to maintain the performance of a Hashset. In Open Addressing performance degrades very fast as the Load Factor approaches 1. In fact, when the Load Factor is greater than or equal to one, Open Addressing actually becomes the inferior option to Separate Chaining, especially with Double Hashing where it would actually stop working correctly. According to Algorithm Design and Applications, keeping the Load Factor less than 0.75 is critical for maintaining the O(1) expected search time. With this information, I had a helper function to determine the load factor of the program:
`return (self.n_entries/self.hash_table_size)` and then had an `if` statement within the Insert function to determine whether it was larger than the threshold of 0.75 as mentioned before: `if self.load_factor() > 0.75`. The way rehashing occurred in my implementation is that I calculate a new table size by doubling the current table size and then finding the next prime number from there: `new_size = self.nextPrime(self.hash_table_size * 2)`. I iterate through the old table's entries and call insert for all the non-None values. 

```Python
def rehash(self):
        self.n_rehashes += 1
        old_table = self.table

        # Resizing by doubling the current prime size and finding the next prime after
        new_size = self.nextPrime(self.hash_table_size * 2)
        if self.verbose > 0:
            print("Rehahsing from " + str(self.hash_table_size) + 'to ' + str(new_size))

        self.hash_table_size = new_size
        self.table = [None] * new_size
        # the number of entries needs resetting, insert will reincrement this value
        self.n_entries = 0
        # reinsertion process
        for item in old_table:
            if item is not None:
                self.insert(item)

        if self.verbose > 2:
            self.print_set()
```


This ensures that even though rehashing has a cost of O(n) the amortised cost of insertion remains O(1).


## Part B

***Question: How do find and insert for binary trees work? How have you implemented them? Include your code for insert and find and relate your explanation to this code. The code may be tidied up a bit for presentation reasons, but should include all important details mentioned in your explanation. (No more than 200 words, not including the code snippet(s))***

I had implemented find and insert using recursion, where I adhered to the properties of Binary Search Tree where the values in the left subtree are smaller than the node, and the values in the right subtree are larger.
For insertion, the algorithm checks if the current node is populated using self.tree(). If populatd, it compares the target self.value. It then recursively calls insert on self.left or self.right and if the values are equal, the operation terminates to prevent duplicates. If the base case is fulfilled (the node is empty), the algorithm initialises self.value and instantiates two new empty bstree objects as children.
Find operates using identical traversal logic, it recursively compares the target value against the current node to decide whether to search the left or right subtree. If value matches self.value, it returns True. If the recursion reaches an empty node it returns false, confirming the value is not in the set. 

# Backup:


1. I used Google's LLM - Gemini 3 Pro  
2. I used the tool specifically for debugging a section of code initially written by me where I was getting incorrect results: I encountered a logic error where my hash set was failing to find existing items in the simple tests. The prompt I used was: "My double hashing implementation is failing to find words of this (provided test file), heres the insert and find code.".   
3. The LLM had correctly identified the logic error within my `insert` function: I had put the h_2 calculation **within** the while loop **and** _without_ the `1 +` offset whereas my `find` function calculated it _outside_ with the offset. The difference meant that the probe sequences for insertion and lookup were different, the AI was able to spot and address this.  
4. For the modification (if you need to, take a look at the commit with the hash 'c06df9c35a29d8168e225fb2c9508ed5a78c0b3c' or with the commit message 'fixed bugs in related to the insert function and find function...') I didn't copy and paste the Ai's response blindly but understood what the logical error was and used its explanation to correct my own code. I moved the h_2 calculation outside loop in insert() and added the missing `1 +` to ensure the step size calculation was correct. I also corrected a type error in some of the print statemetns that the AI flagged.  
5. I fully believe that I have still achieved and met the learning outcomes because the AI did not write any of the core logic or the data structure for me, I had written the majority of the code and strategies myself but once I had hit a problem (as described above) the AI assisted me identifying a logical inconsistency that was preventing the correct design from running. Also, debugging the issue actually _improved_ my understanding of why consitent probe sequences are critical for Open Addressing.

---

I have implemented a hash function known as a Polynomial rolling Hash. I did this instead of the interpreting a string by their ASCII values and summing them. I did this as the latter method would cause strings containing the same letters (anagrams) to have the same value (tabs and bats would equate to the same value with that method). A Polynomial Rolling Hash allows us to prevent this by multiplying each value with a constant value, a, raised to a power that depends on its position:  
 Hi = (Hi-1* 31 + ASCII(k[i]) mod m  
This is equivalent to the polynomial evaluation described in "Algorithm Design and Applications":  
P(z) = a0 + a1z + a2z2 + ... + an-zzn-1 (mod m)  
This function is considered 'good' because it achieves a uniform distribution of keys and the choice of having the multiplier, a, as 31 is important as mentioned in 'Introduction to Algorithms', using a prime number that is close to the number of characters (in the alphabet) helps minimise clustering. Also, distinguishing the order of characters avoids the symmetry issue mentioned above of simple summation hash functions.

--- 

The collision strategy that I have implemented is the Double Hashing Open Addressing method. This uses two distinct hash functions to determine the probe sequence. If a collision occurs at the primary index h1 the algorithm uses a second hash function h2 to determine 'the step size' for probing.

Double Hashing is considered one of the best methods for Open Addressing becuse it minimises primary clustering (a flaw prominent in linear probing) and secondary clustering (where keys that hash to the same slot follow the same path after). Primary clustering is essentially where long 'chains' of keys are produced from reoccuring collisions, Double Hashing essentially prevents from this being an issue.   
Disadvantages of Double Hashing are that the implementation is computationally _more_ expensive than linear (and quadratic) probing due to the second hash calculation. Furthemore, this implementation depends on the table size, m, being prime to ensure that the step size calculated by the second hash isn't a factor of m to ensure that it visits all slots.  
  
For the implementation, both insert() and find() compute h1 and h2 identically in the sense that insert() probes until an empty slot is found:  

# This is the hashing for the primary position

        h_1 = self.hash_function(value) % self.hash_table_size

        index = h_1

        h_2 = 1 + (self.hash_function(value) % (self.hash_table_size - 1))

        start_index = index # for infinite loops

  

        # This part starts the index procedure IF the index is not None - collision

        while self.table[index] is not None:

            # sets dont store duplicates, duplicate detection:

            if self.table[index] == value:

                return

  

            # if not duplicate, collision has occurred:

            self.n_collisions +=1

            # This is for calculating the step size - 1 + (hash % (Size - 1))

            index = (index + h_2) % self.hash_table_size

  

            # safety break but shouldnt happen

            if index == start_index:

                return

To ensure correctness, I addressed the critical constraints mentioned in 'Algorthm Design' that the secondary hash function could never equate to 0, if it did it would cause an infinite loop and to prevent this I implemented h2 as:

h_2 = 1 + (self.hash_function(value) % (self.hash_table_size - 1))

which guarantees a non-zero jump.  
  
For find() it probes using the same sequence, if it encounters None (empty slot) the element doesn't exist and returns false.

h_1 = self.hash_function(value) % self.hash_table_size

        h_2 = 1 + (self.hash_function(value) % (self.hash_table_size - 1))

  

        index = h_1

        start_index = index

  

        while self.table[index] is not None:

            if self.table[index] == value:

                return True

            index = (index + h_2) % self.hash_table_size # usinmg the same logic as insert

            if index == start_index:

                return False

        return False

This works because if the item is present, insert() would have placed it in the exact same empty slot (or an earlier one), this is why ensuring that the step size is non-zero and consistent between both functions is crucial.

---

I implemented rehashing to maintain the performance of a Hashset. In Open Addressing performance degrades very fast as the Load Factor, _a_, approaches 1. In fact, when _a_ is greater than or equal to 1, Open Addressing becomes the inferior option to Separate Chaining, especially with Double Hashing where it would actually _stop_ working correctly. According to "Algorithm Design",  keeping the _a_ less than 0.75 is critical for maintaining the O(1)  expected search time.  
With this information, I had a helper function to determine _a_ of the set:

def load_factor(self):

        return (self.n_entries/self.hash_table_size)

and then had an `if` statement within the `insert()` function to determine whether it was larger than the threshold of 0.75:

def insert(self, value):

        # Rehashes if the load factor exceeds 0.75

        if self.load_factor() > 0.75:

            self.rehash()

Next, the way rehashing was implemented is that I calculated a new table size by doubling the current table size and finding the next prime number (using the `nextPrime()` helper method). This provides the increased headroom needed and keeps the table size, m, a prime number:

def rehash(self):

        self.n_rehashes += 1

        old_table = self.table

  

        # Resizing by doubling the current prime size and finding the next prime after

        new_size = self.nextPrime(self.hash_table_size * 2)

        if self.verbose > 0:

            print("Rehahsing from " + str(self.hash_table_size) + 'to ' + str(new_size))

...

I then iterate through the old table's entries and call insert for all the non-None values:

self.hash_table_size = new_size

      self.table = [None] * new_size

      # the number of entries needs resetting, insert will reincrement this value

      self.n_entries = 0

      # reinsertion process

      for item in old_table:

          if item is not None:

              self.insert(item)

Even though rehashing costs O(n) the _amortised_ cost of insertion remains O(1), ensuring the speed of a HashSet.

--- 

I had implemented find and insert using recursion, where I adhered to the properties of Binary Search Tree where the values in the left subtree are smaller than the node, and the values in the right subtree are larger.  
For insertion, the algorithm checks if the current node is populated using self.tree(). If populated, it compares the target self.value. It then recursively calls insert on self.left or self.right and if the values are equal, the operation terminates to prevent duplicates.

def insert(self, value):

        if (self.tree()):

            if value == self.value:

                return # its a duplicate

            elif value < self.value:

                self.left.insert(value)

            else:

                self.right.insert(value)

If the base case is fulfilled (the node is empty), the algorithm initialises self.value and instantiates two new empty bstree objects as children:

        else:

            # creating a node

            self.value = value

            self.left = bstree()

            self.right = bstree()

Find operates using identical traversal logic, it recursively compares the target value against the current node to decide whether to search the left or right subtree. If value matches self.value, it returns True. If the recursion reaches an empty node it returns false, confirming the value is not in the set:

def find(self, value):

        # recursive search

        if self.tree():

            if value == self.value:

                return True

            elif value < self.value:

                return self.left.find(value)

            else:

                return self.right.find(value)

        return False