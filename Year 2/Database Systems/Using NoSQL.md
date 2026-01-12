16-12-2025 14:08

Tags: [[Database Systems]] [[MongoDB]]

*This is mainly covering the week 10 material of Database Systems, focusing on learning material for the MongoDB NoSQL exam*
# Using NoSQL

## Arrays

If for a collection there is a field that is holding a array:

![[Pasted image 20251216182717.png#invert]]

We can search within the array, which is identical to what we normally use:

```Python
find({array_name: value})
```

## Embedded Documents

If we have documents that are **embedded** and we want to find a value within the embedded document we *cannot* do the same thing that we did with the array.

We use something called **Dot Notation**

### Dot Notation

We can use dot notation to access members of embedded documents:

```Python
find({parent.child:value})
```

**Parent:** this is the field name from the 'outer' document.
**Child:** is the field name from the **embedded** document.

Here is an example that follows from the one above:

Here is the data:

```JSON
{"_id":1, "type":"cd",
"artist":"Crimson Horizon",
"title":"Cosmic Cadence",
"tracklist":[
{"number":1,"title":"Blazing Ballad","length":2:15},
{"number":2,"title":"Mystic Mirage","length":2:50},
{"number":3,"title":"Temporal Tango","length":3:50}]}
{"_id":2, "type":"cd",
"artist":"Various",
"title":"Best Driving Songs",
"tracklist":[
{"number":1,"title":"Blazing Ballad","length":2:15},
{"number":2,"title":"All I Want","length":2:36},
{"number":3,"title":"Last Serenade","length":4:50}]}
{"_id":3,"type":"cd",
"artist":"Fire Breath",
"title":"The Moonlight",
"tracklist":[
{"number":1,"title":"The Moonlight","length":3:15},
{"number":2,"title":"My Heart Cries","length":1:50},
{"number":3,"title":"Cat's Pyjamaas","length":3:10}]}
```

To find the names of the **titles** of the CD's that contain the track "Blazing Ballad" we would do:

```Python
Db.find(
	{"type":"cd","tracklist.title": "Blazing Ballad"},
	 {"title":1}
)
```

This will return: \["Cosmic Cadence", "Best Driving Songs"]

## Getting Distinct Values

If we had two items that had the same values for all the fields bar one, like the `_id` (or ISBN if it's a book) and we want to find **distinct** **values**.

We can use the `distinct()` function to obtain the list of unique values:

```Python
distinct("title")
```

## Sorting, Limiting, Skipping

**Sorting:**
This allow us to sort by a particular field, in either ascending or descending order:

```Python
# Python :
find().sort("title", 1)

# JavaScript:
find().sort({"title": -1})
```

**Limiting:**
This limits the number of returned documents from query:

```Python
find().limit(10)
```

**Skipping:**
This skips the first X documents returned by the query:

```Python
find().skip(10)
```

Combination of all:

```Python
find().sort({"title":-1}).skip(10).limit(10)
```

## The Natural Order

When we query collections, MongoDB will order them in a default way. This is the "natural order" and so when we obtain a collection of documents, the default behaviour is to sort in the *forward natural order*.
The natural order (for regular collections) is **undefined**.
We can sort but natural order as follows:

```Python
find().sort({$natural:1})
```

## Capped Collections

This is creating a collection that has a fixed maximum capacity, declared at creation. It will have a defined and guaranteed natural order - the order that documents are inserted. When a capped collection is **full**, the oldest data is **deleted** and the newest is **inserted at the top**.
- Documents in a capped collection can be updated but cannot grow in size

```Python
db.createCollecton("audit", {capped:true, size:20480})
```

## Indexing

*This part will use Python, specifically the framework PyMongo which will be emulated within MongoMock*

If we have a very large collection that has many items, we will need to traverse a very large document and will take a long time, this is because normally to find something, you'd have to check every item until that item is found.

An index, MongoDB creates a separate data structure, usually a **B-Tree**, that holds a specific field and a pointer to the actual document. It sorts the list, allowing the database to jump instantly to the right record.

```Python
db.collection.create_index(keys)
```

Here is an example:

```Python
db.collection.create_index("brand")
```

![[Pasted image 20251217132616.png#invert|400]]
And now to use this index:

```Python
db.collection.find({"brand": "DreamDrive"})
```

This is a query on our collection of cars.

### Compound Indexing

A compound index is a single index that is built on multiple fields. 
Here is the generic function call for one:

```Python
db.collection.create_index([(key1. sorting), (key2, sorting)])
```

Following on from the example above:

```Python
db.collect.create_index([("brand",1), ("model", 1)])
```

![[Pasted image 20251217133025.png#invert|500]]

**Read (Queries)** become much faster with indexing.
**Writes (Inserts/Updates)** become a lot **slower.**

This is because every time you insert a new document, MongoDB has to:
1. Write the document to the collection,
2. Update the index list,
3. Re-balance the B-Tree structure.

## Aggregation

Aggregation is a powerful technique that allows u to transform collections of documents, process them, and calculate various results and statistics.
There are different aggregate functions that can be arranged into a **pipeline**.

- Match
- Group
- Project
- Unwind
- Sort
- Limit
- Skip

**Pipeline** is a sequence of set operations, where the preceding operation passes the result to the subsequent operation. The **pipeline** can be tailored to match your needs. 

**Generic Example:**

```Python
collection.aggregate([{expr1}, {expr2}, {expr3}, ...])
```

Returned is a **cursor*** over a set of documents that has been generated by the pipeline.

Example:
If you want to count up the number of cars belonging to different brands of cars in my Car collection:

![[Pasted image 20251218141416.png#invert]]


```Python
collection.aggregate([ {"$group":{"_id":"$brand", "count":{"$sum":1}}},
					{"$sort":{"count":-1}},
					{"$project":{"Car Brand":"$_id", "_id":0, "count":1}}
])
```

### $match

The `$match` operation acts as a filter, it reduces the large collections to much smaller, manageable sizes.
It is good practice to put `$match` operation early in the pipeline (this is for memory preservation considerations)

Normal query operations can also be used like `$gt`, `$lt` etc ...

```Python
{"$match":{field: exression}}
```

```Python
{"$match":{"brand": "DreamDrive"}} #Leaves only the "dreamdrive" cars
```

### $group

This allows the grouping of documents together based on certain fields and allows us to combine the values.
Like grouping by car brand, by engine type etc.

One thing to note is that the grouped field becomes the `_id` of a **new document** (one per grouped item).

```Python
{"$group":{"_id": $field}}
```

```Python
{"$group":{"_id" : $brand}} #creates a grouped document for each car brand
```

#### Arithmetic Operations with $group

We can also perform arithmetic operations concerning the grouped documents.

```Python
Counting:
{"$group":
	{"_id":"$brand",
		"Total":{"$sum":1}
		}
}
```

```Python
Average:
{"$group":
	{"_id":"$brand",
		"Average Price":{"$avg": "$price"}
	}
}
```

```Python
Max:
{"$group":
	{"_id":"$brand",
		"Max price":{"$max":"$price"}
	}
}
```

### $project

The `$project` operator is much more powerful than it is in a regular query:

```Python
{"$project":{field: visibility}}
```

It can also be used for:

```Python
Mathematical Expressions:
{"$project":
	{"netPay":
		{ "$subtract":[ {"$add" : ["$salary", "$bonus"]}, "$pensionContrib"} }
}

Date Expressions:
{"$project":
	{"hiredIn":{"$year": "$hireYear"}
}

String Expressions:
{"$project":
	{"surname":{"$toUpper": "$surname"}}
}
```


### $unwind

Unwinding takes the elements of an array and places them in separate documents. It is quite useful if you want to match particular sub-documents.

```Python
{"$unwind":$field}
```


### $sort, $limit, $skip

These are the same as in a regular query but the syntax is slightly different:

```Python
{"$sort":{field: sorting}}

{"$limit":num}

{"$skip":num}
```
