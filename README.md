# C++ Path Planner with A* Algorithm

This repository contains a C++ project developed for a Advanced Programming course Department of Computer Engineering and Automation (**DCA**) at the **Federal University of Rio Grande do Norte (UFRN)**.

The ideia of this project was develop by Dr Adelardo Adelino Dantas de Medeiros to apply the concepts learned in class.

The objective is to find the **shortest path** between two points on a map of Rio Grande do Norte using the **A\*** search algorithm. The project emphasizes the use of the **C++ Standard Template Library (STL)**, **file input/output**, and **exception handling** for robust error management.

<img width="1212" height="747" alt="mapa_rn" src="https://github.com/user-attachments/assets/23b04bf9-4cec-4bc5-b499-6320ea637534" />

source: Adelardo Adelino Dantas de Medeiros

---

## 🧠 The A* Algorithm

The A\* algorithm finds the lowest-cost path in a graph by maintaining two sets of nodes: an **Open set** (`Aberto`) for nodes yet to be analyzed and a **Closed set** (`Fechado`) for nodes already visited. At each step, it evaluates the node from the Open set with the lowest total cost.

### Cost Function
The algorithm determines the best path by calculating the total cost $f(n)$ for each node $n$:

$$f(n) = g(n) + h(n)$$

Where:
* **$g(n)$ (Past Cost)**: The actual known cost of the path from the starting point to the current node $n$.
* **$h(n)$ (Future Cost)**: A heuristic estimate of the cost to get from node $n$ to the destination. If $h(n)$ is zero, the algorithm behaves like Dijkstra's algorithm.

### Heuristic
This project uses the **haversine formula** to calculate the Euclidean distance between two points (given their latitude and longitude) as the heuristic. This is an "**optimistic**" heuristic, as the straight-line distance is always less than or equal to the actual route distance, which is a requirement for A\* to find the optimal path.

---

## 📁 Input Data Format

The application reads map data from two separate text files: one defining the **points (nodes)** and another defining the **routes (edges)**.

### Points File
The points file must have a specific header on the first line, followed by the data for each point.

* **Header:** `ID;Nome;Latitude;Longitude`
* **Data Fields:**
    1.  `ID`: A string starting with `#`.
    2.  `Nome`: The name of the point.
    3.  `Latitude`: A floating-point number.
    4.  `Longitude`: A floating-point number.

### Routes File
The routes file connects the points and defines the travel distance between them.

* **Header:** `ID;Nome;Extremidade 1;Extremidade 2;Comprimento`
* **Data Fields:**
    1.  `ID`: A string starting with `&`.
    2.  `Nome`: The name of the route.
    3.  `Extremidade 1`: The ID of the first point connected by the route.
    4.  `Extremidade 2`: The ID of the second point connected by the route.
    5.  `Comprimento`: A floating-point number representing the length of the route.

---

## 🛠️ Implementation Constraints

This project was developed under a strict set of implementation rules to ensure a focus on specific C++ features:

* **Exception Handling**: Errors during file reading or other operations must be managed using C++ exceptions (`try`, `catch`, `throw`).
* **STL Containers**: Only **sequential containers** (`std::vector`, `std::deque`, `std::list`) or their adapters (`std::stack`, `std::queue`) are permitted. **The use of containers like `std::priority_queue`, `std::set`, or `std::map` is strictly forbidden**.
    * This means the **Open set** (`Aberto`) must be kept **sorted manually** by inserting new nodes into the correct position rather than using a self-sorting container.
* **STL Algorithms**: Generic STL algorithms (e.g., `std::find`, `std::find_if`) must be used in place of manual loops (`for`, `while`) whenever possible.
* **No Code Modification**: The provided declarations and partial implementations of classes like `Ponto`, `Rota`, and `Planejador` cannot be altered.

---

## 🚀 Getting Started

![demonstration](https://github.com/user-attachments/assets/74947641-4238-4985-8eeb-667ece6c22e6)

To compile and run this project, you'll need a C++ compiler that supports C++11 or newer.

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/Nicholas-Wallace/planejador.git](https://github.com/Nicholas-Wallace/planejador.git)
    cd planejador
    ```

2.  **Compile the source code:**
    ```sh
    g++ -std=c++17 -o planejador *.cpp
    ```

3.  **Run the application:**
    ```sh
    ./planejador 
    ```
