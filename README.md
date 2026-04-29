# 💧 HydroLink

### Smart Water Network Optimization System

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Backend-Node.js-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Framework-Express-black?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Algorithms-Graph-orange?style=for-the-badge" />
</p>

---

HydroLink is a **graph-based simulation system** designed to model and optimize water distribution networks. It leverages fundamental algorithms like **Kruskal, Prim, and Dijkstra** to ensure efficient pipeline connectivity, cost optimization, and shortest path routing.

---

## 🚀 Features

* 🌐 Real-world inspired **water distribution network modeling**
* 🔗 **Minimum Spanning Tree (MST)** for cost-efficient pipeline design
* 🛣️ **Shortest path computation** for optimized routing
* ⚙️ Dynamic **edge disabling** to simulate pipeline failures
* 📡 Backend integration using **Node.js & Express**
* 📊 Clean **JSON outputs** for system/API integration

---

## 🧠 Algorithms Implemented

| Algorithm                | Purpose                           |
| ------------------------ | --------------------------------- |
| **Kruskal’s Algorithm**  | Builds minimum cost network       |
| **Prim’s Algorithm**     | Alternative MST approach          |
| **Dijkstra’s Algorithm** | Finds shortest path between nodes |

---

## 🏗️ Project Structure

```id="fw6k2o"
HydroLink/
│── hydrolink_api.cpp     # Core graph algorithms (C++)
│── hydrolink_api         # Compiled executable
│── hydrolink_api.exe     # Windows executable (optional)
│
│── server.js             # Node.js backend server
│── package.json          # Project configuration
│── package-lock.json
│
│── public/               # Frontend/static files
│── node_modules/         # Dependencies
│
│── README.md
│── .DS_Store
```

---

## ⚙️ Tech Stack

* **C++** – Core algorithm implementation
* **Node.js** – Backend runtime
* **Express.js** – API framework
* **JavaScript** – Server-side logic

---

## 🔧 Parameters

| Parameter | Description                         |
| --------- | ----------------------------------- |
| `""`      | Comma-separated edge IDs to disable |
| `0`       | Source node                         |
| `10`      | Destination node                    |

---

## 📈 Output Format

### Kruskal Example

```json id="e98l7c"
{
  "success": true,
  "cost": 42,
  "edges": [0, 2, 5, 7]
}
```

### Dijkstra Example

```json id="6y7d0y"
{
  "found": true,
  "dist": 15,
  "nodes": [0, 1, 4, 10],
  "edges": [0, 4, 16]
}
```

---

## 💡 Use Cases

* 🏙️ Smart city infrastructure planning
* 💧 Water supply optimization
* 📐 Network design & analysis
* 🎓 Academic learning for graph algorithms

---

<p align="center">
  
</p>
