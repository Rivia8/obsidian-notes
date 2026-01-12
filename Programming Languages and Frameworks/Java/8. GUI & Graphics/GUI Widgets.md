20-07-2025 21:52

Tags: [[Java]] [[JavaFX]]

# GUI Widgets

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

Here is one in use:

```Java

public void start (Stage primaryStage) {

	Label resultLabel = new Label("You have not selected anything yet.");
	ComboBox<String> languageComboBox = new ComboBox<>();

	languageComboBox.getItems().addAll(){
		"Java",
		"Python",
		"JavaScript"
	}

	languageComboBox.getSelectedModel().selectedItemProperty().addListener()(
		(options, oldValue, newValue) -> {
			resultLabel.setText("You selected: " + newValue);
		}
	)

	...

}
```



## ListView

This displays horizontal or vertical list of items from which the user may select/interact with. 
The listview can have its generic type set to represent the type of data in the backing model.

**How it works:**

1. Create an `observableList` for the `ListView` to update automatically when you add or remove devices,
2. A custom `DeviceCell` class will be needed to extend `ListCell<Device>` which its main job to override the `updateItem()` method,
3. Inside `updateItem()` you can create a `HBox` to hold a `Label` for the device info and a `Button` for toggling.