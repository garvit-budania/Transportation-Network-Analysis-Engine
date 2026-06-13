# Transportation Network Analysis Engine

![Build](https://github.com/garvit-budania/Transportation-Network-Analysis-Engine/actions/workflows/build.yml/badge.svg)

A graph-based transportation network simulator built in C++ to explore routing, network optimization, flow analysis, and resilience analysis using real-world inspired city and route datasets.

This project was developed to gain hands-on experience with graph theory, data structures, and modern C++ by implementing several classical graph algorithms on a transportation network.

---

## About The Project

Transportation systems can naturally be represented as graphs, where cities act as nodes and routes act as weighted edges.

This project simulates such a network and provides tools to:

- Explore network connectivity
- Find optimal routes
- Analyze network robustness
- Compute flow capacity
- Identify critical cities and routes
- Visualize transportation networks

The project was developed incrementally, starting with basic graph traversal and eventually expanding into route optimization, flow analysis, resilience analysis, and visualization.

---

## Features

### Route Planning

- Dijkstra's Shortest Path Algorithm
- A* Search Algorithm
- Route Optimization based on:
  - Distance
  - Travel Time
  - Cost

### Network Traversal

- Breadth First Search (BFS)
- Depth First Search (DFS)

### Network Optimization

- Minimum Spanning Tree (Kruskal's Algorithm)
- Maximum Flow Analysis (Edmonds-Karp Algorithm)

### Network Analytics

- Connected Components Detection
- Average Degree Analysis
- Network Density Analysis
- Most Connected City Identification

### Network Resilience Analysis

- Articulation Point Detection
- Bridge Detection
- Critical City Identification
- Critical Route Identification

### Visualization

- DOT Graph Export
- Graphviz Integration
- PNG Rendering Support

---

## System Architecture

```text
Transportation Dataset
          │
          ▼
      CSV Reader
          │
          ▼
      Graph Model
          │
 ┌────────┼────────┐
 ▼        ▼        ▼
Algorithms Analytics Visualization
          │
          ▼
      Console Output
```

---

## Technologies Used

| Category | Technology |
|-----------|------------|
| Language | C++20 |
| Build System | CMake |
| Data Storage | CSV Files |
| Visualization | Graphviz |
| Containerization | Docker |
| CI/CD | GitHub Actions |
| Version Control | Git & GitHub |

---

## Project Structure

```text
Transportation-Network-Analysis-Engine
│
├── include
│   ├── algorithms
│   ├── core
│   ├── io
│   └── visualization
│
├── src
│   ├── algorithms
│   ├── app
│   ├── core
│   ├── io
│   └── visualization
│
├── data
│   ├── nodes.csv
│   └── routes.csv
│
├── .github
│   └── workflows
│       └── build.yml
│
├── Dockerfile
├── network.dot
├── network.png
└── README.md
```

---

## Algorithms Implemented

| Category | Algorithms |
|-----------|------------|
| Traversal | BFS, DFS |
| Routing | Dijkstra, A* |
| Optimization | Kruskal MST |
| Flow Analysis | Edmonds-Karp |
| Resilience | Articulation Points, Bridges |

---

## Sample Output

### Network Statistics

```text
Nodes: 15
Edges: 20
Connected Components: 1
Average Degree: 2.67
Density: 0.095
Most Connected City: Nagpur
```

### Route Optimization

```text
Shortest Route
Delhi -> Jaipur -> Ahmedabad -> Mumbai -> Pune

Distance: 1610 km
```

```text
Fastest Route
Delhi -> Jaipur -> Indore -> Ahmedabad -> Mumbai -> Pune

Travel Time: 27 hrs
```

```text
Cheapest Route
Delhi -> Jaipur -> Ahmedabad -> Mumbai -> Pune

Cost: 2550
```

### Network Resilience Analysis

```text
Critical Cities

Patna
Hyderabad
Bengaluru
```

```text
Critical Routes

Patna - Kolkata
Bengaluru - Chennai
Hyderabad - Bengaluru
```

---

## Network Visualization

The transportation network can be exported in DOT format and rendered using Graphviz.

![Transportation Network](network.png)

Generate the visualization using:

```bash
dot -Tpng network.dot -o network.png
```

---

## Building The Project

### Clone Repository

```bash
git clone https://github.com/garvit-budania/Transportation-Network-Analysis-Engine.git
cd Transportation-Network-Analysis-Engine
```

### Configure

```bash
cmake -S . -B build
```

### Build

```bash
cmake --build build
```

### Run

```bash
./build/tnae
```

---

## Running With Docker

Build the Docker image:

```bash
docker build -t tnae .
```

Run the container:

```bash
docker run tnae
```

---

## Automated Builds

A GitHub Actions workflow automatically builds the project on every push and pull request to ensure the codebase remains buildable.

Workflow file:

```text
.github/workflows/build.yml
```

---

## Development Journey

The project was developed incrementally:

- Built the graph representation and CSV-based data loader
- Implemented BFS and DFS traversal
- Added shortest path algorithms (Dijkstra and A*)
- Implemented Minimum Spanning Tree generation
- Added Maximum Flow analysis
- Introduced network analytics and resilience analysis
- Added route optimization using multiple metrics
- Integrated Graphviz-based visualization
- Containerized the application using Docker
- Added automated builds using GitHub Actions

---

## Future Improvements

- Larger transportation datasets
- Interactive visualization support
- REST API integration
- Additional routing heuristics

---

## Author

**Garvit Budania**

Developed as a personal project to strengthen my understanding of graph algorithms, data structures, software design, and modern C++ development.
