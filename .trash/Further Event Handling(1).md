19-07-2025 20:22

Tags: [[Java]] [[Event Handling]]

# Further Event Handling

JavaFX provides many UI controls for developing a comprehensive user interface.

To create a good GUI we need things like:
- Labels
- Text Areas
- Drop down menus
- Check boxes
- Radio buttons


## Mouse Event Handling

In JavaFX we can do mouse events where we have the following:

- `setOnMouseClicked(EventHandler<MouseEvent>)`
- `setOnMouseEntered(EventHandler<MouseEvent>)`
- `setOnMouseMoved(EventHandler<MouseEvent>)`
- `setOnMouseDragged(EventHandler)`;

## Key Event Handling

- `setOnKeyPressed(EventHandler<KeyEvent>)`
- `setOnKeyReleased(EventHandler<KeyEvent>)`

## TextArea / TextFIeld

The `TextArea` is an input component that allows users to enter multiple lines of plaint text.

```Java
import javafx.scene.control.TextArea;
```

In order to get text from `TextArea` you call the method `getText()`

```Java
TextArea textArea = new TextArea();
```


## ComboBox

The ComboBox is a widget part of a GUI that combines a textbox with a list of selectable items.

![[simplecombo.png|400]]

```Java
import javafx.scene.control.ComboBox;
```

In order to get the selection from the `ComboBox` you call the method `getValue()`.

But to instantiate the `ComboBox` with select values and adding a listener is more complicated.