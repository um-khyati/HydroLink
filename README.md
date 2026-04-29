# 💧 HydroLink – Water Distribution Network Optimization

HydroLink is a simulation-based project that models a water distribution network using graph data structures and algorithms. It helps analyze and optimize pipeline connections, detect efficient routes, and ensure cost-effective water supply.

---

## 🚀 Features

* 🌐 Graph-based representation of a water network (nodes & pipelines)
* 🔗 Minimum Spanning Tree using:

  * Kruskal’s Algorithm
  * Prim’s Algorithm
* 🛣️ Shortest Path calculation using Dijkstra’s Algorithm
* ⚙️ Ability to disable specific pipelines (edges) dynamically
* 📊 Outputs results in JSON format for easy integration with frontend/API

---

## 🧠 Algorithms Used

### 1. Kruskal’s Algorithm

* Finds Minimum Spanning Tree (MST)
* Minimizes total pipeline cost

### 2. Prim’s Algorithm

* Alternative MST approach using priority queue

### 3. Dijkstra’s Algorithm

* Finds shortest path between two nodes
* Useful for efficient water routing

---

## 🏗️ Project Structure

```
HydroLink/
│── hydrolink_api.cpp     # Core C++ implementation
│── hydrolink_api.exe     # Compiled executable
│── package.json          # Node.js backend config
│── package-lock.json
```

---

## ⚙️ Tech Stack

* **C++** – Core logic and algorithms
* **Node.js + Express** – Backend (API integration) 
* **Graph Algorithms** – MST & Shortest Path

---

## ▶️ How to Run

### 1. Compile the C++ Code (if not using .exe)

```bash
g++ hydrolink_api.cpp -o hydrolink_api
```

### 2. Run Algorithms

#### 🔹 Kruskal

```bash
./hydrolink_api kruskal ""
```

#### 🔹 Prim

```bash
./hydrolink_api prim "" 0
```

#### 🔹 Dijkstra

```bash
./hydrolink_api dijkstra "" 0 10
```

---

## 🔧 Parameters

* `""` → Comma-separated edge IDs to disable
* `0` → Source node
* `10` → Destination node

---

## 📍 Sample Network

The system models a real-world inspired water network including:

* Sources (e.g., ONGC Chowk)
* Hubs (distribution centers)
* Areas (supply regions)
* Sinks (end points)

---

## 📈 Output Format

Example (Kruskal):

```json
{
  "success": true,
  "cost": 42,
  "edges": [0, 2, 5, 7]
}
```

Example (Dijkstra):

```json
{
  "found": true,
  "dist": 15,
  "nodes": [0, 1, 4, 10],
  "edges": [0, 4, 16]
}
```

---

## 💡 Use Cases

* Smart city water management
* Infrastructure planning
* Network optimization problems
* Academic learning for graph algorithms

---

## 🔮 Future Improvements

* Add frontend visualization (React / D3.js)
* Real-time simulation dashboard
* Integration with GIS/map data
* API endpoints for dynamic queries

---

## 👩‍💻 Author

**Khyati Uttam**
Computer Science Undergraduate

---

## ⭐ Contribute

Feel free to fork the repo and improve it!

---

## 📜 License

This project is open-source and available under the MIT License.
