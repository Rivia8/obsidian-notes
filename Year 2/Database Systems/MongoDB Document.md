14-12-2025 20:36

Tags: [[Database Systems]]

# MongoDB Document

You can see and find the **BSON** spec [here](https://bsonspec.org/).

They are composed of field-and-value pairs and have the following structure:

```JSON
{
   field1: value1,
   field2: value2,
   field3: value3,
   ...
   fieldN: valueN
}
```

The value of a field can be any of the BSON data types, including other documents, arrays and arrays of documents.

```JavaScript
var mydoc = {
               _id: ObjectId("5099803df3f4948bd2f98391"),
               name: { first: "Alan", last: "Turing" },
               birth: new Date('Jun 23, 1912'),
               death: new Date('Jun 07, 1954'),
               contribs: [ "Turing machine", "Turing test", "Turingery" ],
               views : Long(1250000)
            }
```

The above fields have the following data types:

- `_id` holds an [ObjectId.](https://www.mongodb.com/docs/manual/reference/bson-types/#std-label-objectid)
- `name` holds an _embedded document_ that contains the fields `first` and `last`.
- `birth` and `death` hold values of the _Date_ type.
- `contribs` holds an _array of strings_.
- `views` holds a value of the _NumberLong_ type.

You can also embed documents within documents with arrays. However, nesting **too** much isn't great.

## The `_id` field

Each document in a `Collection` requires a unique `_id` field. The `_id` field acts as a primary key to the collection. If an inserted document omits the `_id` field, an `Objectid` is automatically generated for the `_id` field. The `_id` field is always the first field in the document and it may contain BSON data types **except arrays**.