18-07-2025 15:10

Tags: [[Java]]

# Event Handling

Event handling is what the program does when a user interacts with the program's interface.

Not all objects can be handlers of an event. Two requirements must be met:
- It must be an instance of the `EventHandler<T extends Event>`
- The `EventHandler` object handler must be registered with the event source object,

The way to think of event handling is there is a source (like a UI element) that detects an event, in JavaFX this would be a `Button`, a `TextField` or a `Silder`.
The **Event Object** is the signal that is sent when something happens. In JavaFX this would be an object like `ActionEvent` (for a button click) or `KeyEvent` (for a key press).
The **Event Handler** is the the thing that responds to the signal. In JavaFX it is the block of code you write to define what happens when the event occurs.

![[Pasted image 20250718153004.png#invert|700]]

## Legacy Event Handling

This is what was used before we had [[Programming Languages and Frameworks/Java/7. Advanced Concepts/Lambda Expressions]] and JavaFX to help us with event handling.

There were two ways could do this.

### Anonymous Inner Class

This was the most common way, how this worked is that you create an unnamed, on-off class directly inside the method call that adds the listener.

```Java
import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LegacyEventHandling {
    public static void main(String[] args) {
        Frame frame = new Frame("Legacy Events");
        Button button = new Button("Click Me");

        // --- Anonymous Inner Class ---
        // Create a new instance of the ActionListener interface directly.
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // This is the handler code
                System.out.println("Button was clicked! (Anonymous Class)");
            }
        });

        frame.add(button);
        frame.setSize(300, 150);
        frame.setVisible(true);
    }
}
```

### Separate Listener Class

This is where you create a completely separate named class that implements the listener interface.

```Java
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// A separate class that defines the event handling logic.
public class MyButtonListener implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("Button was clicked! (Separate Class)");
    }
}
```

Then you create an instance of this class and add it to the button:

```Java
// In your main method...
Button button2 = new Button("Click Me Too");

// Create an instance of your listener class
MyButtonListener listener = new MyButtonListener();

// Add the listener object to the button
button2.addActionListener(listener);
```