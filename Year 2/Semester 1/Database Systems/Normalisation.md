20-10-2025 14:32

Tags: [[Database Systems]]

# Normalisation

**Normalisation** is the process of **organising** the data in the database, with a focus on **minimising redundancy** in relations or set of relations.
This process allows us to prevent data **redundancy**, offers data **consistency**, offers **flexibility** in the design and data management and enforces **relational** (referential) integrity.

The main goal is to ensure that every piece of data is only stored in one place.

There are 6 Normal Forms, we will look at the first 3, 1NF, 2NF, 3NF as these address the 3 data modification anomalies:

1. Insertion Anomaly (Omission of data during insertion due to absence of other data).

2. Deletion Anomaly (Unintended loss of data due to the deletion of other data).

3. Update Anomaly (Data inconsistency that results from redundant data and partial updates).

## First Normal Form (1NF)

A table is in 1NF if it contains no repeating groups and the values in each column are atomic.

Let's use this example as a starting point:

| **StudentID** | **StudentName** | **Courses (ID & Title)**                   |
| ------------- | --------------- | ------------------------------------------ |
| 10            | Alice           | "CS101: Intro to CS", "MTH200: Calculus I" |
| 20            | Bob             | "CS101: Intro to CS"                       |

This would violate the condition of atomicity so we would need to make this:

| **StudentID** | **StudentName** | **CourseID** | **CourseTitle** | **InstructorName** |
| ------------- | --------------- | ------------ | --------------- | ------------------ |
| 10            | Alice           | CS101        | Intro to CS     | Dr. Smith          |
| 10            | Alice           | MTH200       | Calculus I      | Dr. Davis          |
| 20            | Bob             | CS101        | Intro to CS     | Dr. Smith          |

Now the new table follows First Normal Form.

## Second Normal Form (2NF)

A table is in 2NF if it its first in 1NF and there are no partial dependencies (every non-key attribute is functionally dependent on the PK).

In order to make the 1NF table above to 2NF all the non-key columns must depend on the *entire* PK but in order to do this we will need to split the table into 3 since the PK is `{StudentID, CourseID}`, the problem is that `StudentName` only depends on `StudentID` and `CourseTitle` only depends on `CourseID` which is the reason why we would need to split the table:

**Student Table:**

| **StudentID** | **StudentName** |
| ------------- | --------------- |
| 10            | Alice           |
| 20            | Bob             |

**Course Table:**

| **CourseID** | **CourseTitle** | **InstructorName** |
| ------------ | --------------- | ------------------ |
| CS101        | Intro to CS     | Dr. Smith          |
| MTH200       | Calculus I      | Dr. Davis          |

**Enrolment Table:**

|**StudentID**|**CourseID**|
|---|---|
|10|CS101|
|10|MTH200|
|20|CS101|

## Third Normal Form (3NF)

A table is in 3NF if its in 2NF, and there are no transitive dependencies for non-key attributes.

If we were to have the Course Table above with an extra column for departments:

|**CourseID**|**CourseTitle**|**InstructorName**|**InstructorDept**|
|---|---|---|---|
|CS101|Intro to CS|Dr. Smith|Computer Science|
|MTH200|Calculus I|Dr. Davis|Mathematics|
|CS102|Data Structures|Dr. Smith|Computer Science|

This would violate 3NF, since `InstructorDept` depends on `InstructorName` and not on `CourseID`, so we would need to split the table into two:

**Course Table:**

| **CourseID** | **CourseTitle** | **InstructorName** |
| ------------ | --------------- | ------------------ |
| CS101        | Intro to CS     | Dr. Smith          |
| MTH200       | Calculus I      | Dr. Davis          |
| CS102        | Data Structures | Dr. Smith          |

**Instructor Table:**

|**InstructorName**|**InstructorDept**|
|---|---|
|Dr. Smith|Computer Science|
|Dr. Davis|Mathematics|

So in the end we have four tables: `Student`, `Instructor`, `Course`, and `Enrollment`, with all redundancy removed.