# 🧭 Pathfinding Visualizer (C++)

## 📌 Description

This project is a simple **Pathfinding Visualizer** built using C++.
It demonstrates how pathfinding algorithms work on a 2D grid.

The program finds a path from a **start point (S)** to an **end point (E)** while avoiding obstacles.

---

## 🚀 Features

* Grid-based pathfinding system
* Start (`S`) and End (`E`) positions
* Obstacles (`#`) support
* Path visualization (`*`)
* Displays final grid with path

---

## 🧠 Algorithms Used

* Breadth-First Search (BFS)

> BFS guarantees the shortest path in an unweighted grid.

---

## 🧱 Data Structures Used

* **Queue** → for BFS traversal
* **2D Array / Vector** → for grid representation
* **Pair / Struct** → to store coordinates
* **Visited Array** → to track visited cells

---

## 🖥️ How It Works

1. The grid is initialized with start, end, and obstacles
2. BFS is applied to explore all possible paths
3. The shortest path is found
4. The path is marked and printed

---

## 📂 Project Structure

```
Pathfinding-Visualizer/
│── main.cpp
```

---

## ▶️ How to Run

### Compile:

```
g++ main.cpp -o main
```

### Run:

```
./main
```

---

## 📸 Sample Output

```
S . . #
. # . .
. # . E

Path Found!

S * * #
. # * *
. # . E
```

---

## 🔮 Future Improvements

* Add DFS, Dijkstra, A* algorithms
* Add step-by-step visualization
* Add GUI (using SFML or graphics library)
* User input for grid

---

## 💡 Learning Outcome

* Understanding BFS in depth
* Working with grids and traversal
* Practical use of data structures

---

## 👩‍💻 Author

Samvedita

---
