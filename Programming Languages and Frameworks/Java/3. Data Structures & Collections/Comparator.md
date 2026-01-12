17-08-2025 13:12

Tags: [[Java]]

# Comparator

The `Comparator` is used when you want to define multiple, different ways to sort objects, or when you can't (or don't want to) modify the class itself.

You create a class that implements `Comparator` for each different sort order and you provide a `compare()` method in each of the implementations.
You can use `java.util.Collections` to do the actual sorting.

```Java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

// A simple Player class that does NOT implement Comparable.
class Player {
    private String name;
    private int score;
    public Player(String name, int score) { this.name = name; this.score = score; }
    public String getName() { return name; }
    public int getScore() { return score; }
    @Override
    public String toString() { return name + " (" + score + ")"; }
}

// Comparator #1: Sorts players by name alphabetically.
class SortPlayerByName implements Comparator<Player> {
    @Override
    public int compare(Player p1, Player p2) {
        return p1.getName().compareTo(p2.getName());
    }
}

// Comparator #2: Sorts players by score from highest to lowest.
class SortPlayerByScoreDesc implements Comparator<Player> {
    @Override
    public int compare(Player p1, Player p2) {
        // Reversed order (p2 vs p1) for descending sort.
        return Integer.compare(p2.getScore(), p1.getScore());
    }
}

public class Game {
    public static void main(String[] args) {
        List<Player> players = new ArrayList<>();
        players.add(new Player("Charlie", 120));
        players.add(new Player("Alice", 100));
        players.add(new Player("Bob", 100));

        // Sort using the "by name" rulebook.
        players.sort(new SortPlayerByName());
        System.out.println("Sorted by name:    " + players);

        // Sort the same list using the "by score" rulebook.
        players.sort(new SortPlayerByScoreDesc());
        System.out.println("Sorted by score:   " + players);
    }
}
```
