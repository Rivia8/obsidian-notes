29-03-2025 23:39

Tags: [[Java]]

# JavaFX Model:

**JavaFX** is a package in Java.

A JavaFX program is referred to as an **application**.
The JavaFX class extends the `Application` class for which you need to use the import statement: 

```Java
import javafx.application.Application
```

When you create a a JavaFX application, you first have to extend the `Application` class, which the`Application` class requires you to code the `start` method:

```Java

public class HelloWorld extends Application {
	
	public void start (Stage stage) {
		...
	}
}

```

This can be confusing but this uses something called the **Inversion of Control (IoC)** pattern, whereby the framework (JavaFX) does most the heavy-lifting. What we focus on is providing the logic and content of the application.

We pass on a `Stage` type object for us called `stage` this holds

The top level window in which the application runs is called a **stage**.
The contents of the stage (the graphics itself) is called a **scene**.
The items that make up the scene are what is called **nodes** (and containers)

A container is a special type of node whose job is to arrange other `Nodes` within it. It's like a folder. It holds files and other folders and controls how they are positioned (so a list or grid), examples are `VBox`, `HBox`, `GridPane` and `BorderPane`.

The order that the elements appear in the application depends on the order the sequence they are added to the scene.
## Nodes

Nodes are very commonly things that the user interacts with such as buttons, text fields, labels, and check boxes - there are often called **controls**.
Nodes can also be **containers**, these are things that hold other nodes and are used to arrange nodes in particular ways.

The root node isn't a special type of node, its just the node that is the **single** container, (the top level one) that you hand to the `Scene` to be the starting point of the entire layout.

We normally place a single top level node in our scene, and this is referred to as a **root** node.
We use the terms **parent** and **children** for the containing and contained nodes respectively.


![[Pasted image 20250403121024.png#invert|500]]

This is a hierarchal structure of the figure above:

![[Pasted image 20250403121037.png#invert|500]]

## Containers and Layouts

There are four main types of containers:
1. `Pane`,
2. `Group`,
3. `HBox`, 
4. `VBox`


**Group (Corkboard📌)**: 
with group you essentially 'pin' items like a corkboard, anywhere you want using specific x/y coordinates. The board holds them all together.

**HBOX and VBOX (Bookshelves📚):**
These two have automatic arranging, where **HBOX** will place a node right to the previous one in a neat horizontal row and **VBOX** will stack nodes on top of each other in a vertical column. Here you don't decide the exact x/y coordinates but rather the order.

| Features          | <mark class="hltr-orange">Group</mark>                                    | <mark class="hltr-orange">HBox / VBox</mark>                                  |
| ----------------- | ------------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| Layout Management | None (Manual). It respects the layoutX and layoutY you set on each child. | Automatic. It arranges children in a single row (HBox) or column (VBox).      |
| Positioning       | You control the exact position of every child node.                       | The container controls the position. You just add children to it.             |
| Key Properties    | Very few properties for layout.                                           | spacing (gap between children), alignment (e.g., center, top-right), padding. |
| Best Use Case     | Composite shapes, drawings, layers where absolute positioning is key.     | Toolbars, forms, menus, lists of buttons—any structured, ordered layout.      |

There is also `Pane` which is like `Group` where you can put a node anywhere on the screen, but its ***more*** powerful than group, pane can be styled with CSS and has its own resizable properties but `Group` does not as it is just a collector.

The issues with `Pane` and `Group` containers is that they are **non-responsive** so nodes won't dynamically adjust their positions to match the screen or window size.

### Pane

Following the issue described above is the fact that `Pane` actually have types to combat this like `Gridpane`, `FlowPane` and `BorderPane`.

![[Pasted image 20250718141337.png#invert|1000]]

This might be confusing but `Pane` is actually the parent class where `HBox` and `VBox` inherit all the features:

**Hierarchy:**

`Parent`
- `Group` (A simple collector)
- `Region` (A base class for anything with its own background/border/shape)    
    - **`Pane`** (The generic "blank canvas" layout container)
        - `HBox`, `VBox`, `GridPane`, `BorderPane`, etc. (Specialized panes with automatic layout logic)

`FlowPane` - Similar to `HBox` but will dynamically rearrange the rows to match the window size.
`BorderPane` - This has the elements at the borders of the window and will also dynamically readjust whilst still sticking to the border.