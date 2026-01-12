15-08-2025 18:41

Tags: [[Java]]

# Optional

The `java.util.Optional` is a container object that helps prevent `NullPointerExceptions` by forcing a developer to consciously handle the case where a value might be absent.

Its a box that may or may not contains something. Instead of a method returning a raw value (which could be a null), it returns the box.

```Java
import java.util.Optional;

// NEW WAY
public Optional<User> findUser(String username) {
    // ... logic to find a user ...
    if (userFound) {
        return Optional.of(user); // Put the user in the box
    } else {
        return Optional.empty(); // Return an empty box
    }
}

// The caller is forced to handle the empty case.
Optional<User> userOptional = findUser("bob");
userOptional.ifPresent(user -> {
    // This code only runs IF the box is not empty.
    System.out.println(user.getName()); 
});
```


