21-11-2025 09:14

Tags: [[Database Systems]]

# Web Programming

# Inserting Data
## Getting User Input

One common approach is getting user input is to implement a form:
- HTML, `<form>`, the tag defines the form
- The `POST` method attribute is crucial, it sends the data securely in the HTTP request body, not in the ULR (like `GET`) does, this is essential for sensitive data like passwords.
- The `action` attribute tells the browser *where* to send the data.

Here is a basic HTML form:

```HTML
<form>
	<label for="username">Username</label>
	<input type="text" id="username" name="username">
	<label for="password">Password</label>
	<input type="password" id="password" name="password">
	<input type="submit" value="Register">
</form>
```

If you were to include `<form action='$_SERVER[PHP_SELF] method ='POST>` the data would be sent to the current page.

You can use functions to process the input.
`registerForm()`: the function generates and displays the HTML form.
`registerUser()`: the function handles the logic *after* the form is submitted. It retrieves the input values using the `$_POST$` superglobal array (e.g., `$_POST['username'])` ).

The script can check if the form has been submitted by checking if `$_POST` is not empty.

## Connecting to Databases

To store uses data, PHP needs to talk to the MySQL database..
We can use **PDO (PHP Data Objects)**.

You start by defining variables for the host `$db_host`, database name `$db_name`, username `$db_user` and password `$db_pass`.

You can create a `new PDO(...)` object using these credentials. The object represents the active connection to the database.

## Inserting Data Securely

You **never** insert user input directly into a SQL query string, this leads to SQL **injection attacks**.

You write the SQL query with placeholders, like `:userid` and `:userPassword` instead of the actual data.

```PHP
$sql = "INSERT INTO user (username, password) VALUES (:userId, :userPassword)";
$stmt = $pdo->prepare($sql);
```

You then verify and bind the actual user data to those placeholders when you run the query

```PHP
$stmt->execute([
    'userId' => $username,
    'userPassword' => $hashed_password
]);
```

The database treats the input strictly as data, not as executable code, this neutralises any malicious SQL commands a hacker might try to type into the username box.

## Storing Passwords

Storing plain text passwords is a major security risk, if the database is hacked everyone's account is compromised.
`password_hash()`  is a PHP function, it take's the user's password and transforms it into a scrambled string of characters, a "hash".
- It is a one-way process. you cannot get the original password back,
- When a user logs in later, you hash their input and compare their stored hash.

`PASSWORD_DEFAULT`: this constant tells PHP to use the current strongest hashing algorithm, usually bcrypt.

## Summary

This is a summary of the workflow:

- **User** loads the page → PHP calls `registerForm()` → **Form** is displayed.
- **User** types "Alice" and "secret123" and clicks Register.
- **Browser** sends a `POST` request to the same page.
- **PHP** detects the `POST` data → calls `registerUser()`.
- `registerUser()` gets the inputs, **hashes** the password ("secret123" becomes "2y10$...").
- **PDO** connects to the database.
- **Prepared Statement** inserts "Alice" and the _hashed_ password into the `user` table safely.

# Retrieving Data

Here we look at how to build a login system.

## Basic Structure

The structure is very similar to the registration page, you still have things like:
- `loginForm()`
- `loginUser()`
- Flow control - `if/else` block check `empty($_POST)` to decide whether to show the form or process the login.

## Processing Input

Just like registration, you retrieve, the username `$un` and password `$pw` from `$_POST`.

However the SQL query is different you use `SELECT`:

```SQL
SELECT * FROM user WHERE username = :userId
```

You're using `SELECT` since you are asking the database to *find* a row where teh username matches the user typed.
Using placeholders like `:userId` prevents SQL injection.

## Fetching the Result

When you execute a `SELECT` query, the database returns a result set, which might be empty if the user doesn't exsist.
`$stmt->setFetchMode(PDO::FETCH_ASSOC)`: This tells PHP to return the row as an associative array, which is easier to work with than numbered indices.
`$stmt -> fetch()`: This method grabs the next row from the result set, in a login scenario you expect there to be at most one row (username should be unique).

## Password Verification

This is the most critical part of the login process, you cannot simply compare the plain text to the stored hash. They will look completely different.

You use the built-in PHP function:

```PHP
if (password_verify($pw, $row['password'])) {
    // Success!
}
```

`password_verify()` takes the plain password the user just typed and the *hashed* password from the database. It re-hashes the input using the same algorithm and *salt* found in the stored hash to see if they match.#

## Summary of the Login Workflow:

1. **User** enters "Alice" and "secret123".
2. **PHP** connects to the database.
3. **SQL** query runs: `SELECT * FROM user WHERE username = 'Alice'`.
4. **Database** returns the row for Alice (including her _hashed_ password).
5. **PHP** runs `password_verify("secret123", "$2y$10$...")`.
6. **Success:** If it returns true, the user is logged in.
7. **Failure:** If it returns false (or if no row was found), the login fails