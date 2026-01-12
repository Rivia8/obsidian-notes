
29-05-2025 23:00

Tags: [[Java]]

# JavaFX

Early versions used the **Abstract Window Toolkit (AWT) library**. This relied on the operating system's graphic components. It was heavyweight and aesthetically not pleasing.

**SWING** most classes are written in Java, unlike AWT it was lightweight.

JavaFX provides API''s to produces user interfaces and rich GUI's.

Every JavaFX application involves these components:

`Application` Class:

The main JavaFX application class must extend `javafx.applciation.Application`.
This is the entry point for your JavaFX application.
You include `start(Stage primaryStage)` method which builds your UI.
The application is launched using `Application.launch(YourApp.class, args)`.

`Stage`:
This represents the top-level window of a JavaFX application. Think of it as the main frame or window provided by the operating system.
A JavaFX application has a `primaryStage` object that is automatically created and passed to your `start()` method.
You can create additional `Stage` objects for new windows.
You set properties like titles, icon and full-screen mode on the `Stage`.

`Scene`:
Represents the content area of a `Stage`. A `Stage` can hold only one `Scene` at a time.
All the UI elements are placed within a `Scene`.
It contains the scene graph.
You set a `Scene` on a `Stage` using `stage.setScene(scene)`

`Node`:
The abstract base class for all visual objects that can be placed in a `Scene`.
Anything you can see on the screen in a JavaFX application is a `Node`.
Examples: `Button`, `Label`, `TextField`, `Rectange`, `ImageView`, `Group`, `Pane`.
Nodes are organised hierarchically in the Scene Graph.


