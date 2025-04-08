<h1 align="center">🧠 Design and Analysis of Algorithms</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++%2FJava%2FPython-blue.svg" alt="Languages">
  <img src="https://img.shields.io/github/repo-size/TechSpectra-Org/Design-and-Analysis-of-Algorithms" alt="Repo Size">
  <img src="https://img.shields.io/github/last-commit/TechSpectra-Org/Design-and-Analysis-of-Algorithms" alt="Last Commit">
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License">
</p>

---

## 🎯 About the Project

> This repository contains a structured and visualized collection of core algorithms from the **Design and Analysis of Algorithms (DAA)** curriculum. All implementations are backed with **time & space complexity analysis**, real-world applications, and detailed explanations.

---

## 🧩 Core Concepts Covered

| Category             | Algorithms Included                                                                 |
|----------------------|-------------------------------------------------------------------------------------|
| 🪓 **Divide & Conquer**   | Merge Sort, Quick Sort, Binary Search, Closest Pair of Points                     |
| 💰 **Greedy**             | Fractional Knapsack, Activity Selection, Huffman Coding, Job Scheduling          |
| 🧠 **Dynamic Programming**| 0/1 Knapsack, Matrix Chain Multiplication, LCS, LIS, Egg Dropping Problem        |
| 🔁 **Backtracking**       | N-Queens, Sudoku Solver, Subset Sum, Rat in a Maze                               |
| 🧭 **Graph Algorithms**   | Dijkstra’s, Prim’s, Kruskal’s, Bellman-Ford, Floyd-Warshall, Topological Sorting |

---

## 🧠 Time & Space Complexity Chart

```mermaid
graph TD
  A[Binary Search] -->|Time: O(log n)| B
  B[Quick Sort] -->|Avg: O(n log n)| C
  C[Knapsack DP] -->|Time: O(nW)| D
  D[Dijkstra] -->|Time: O(E + V log V)| E
```

## 🚀 Getting Started

### ✅ Step-by-step Instructions

#### 💻 Clone the Repository

```bash
git clone https://github.com/hlukare/Design-and-Analysis-of-Algorithms.git
cd Design-and-Analysis-of-Algorithms
```

---

### 📁 Folder Structure

```plaintext
📦 Design-and-Analysis-of-Algorithms
 ┣ 📂 DivideAndConquer
 ┣ 📂 Greedy
 ┣ 📂 DynamicProgramming
 ┣ 📂 Backtracking
 ┣ 📂 Graphs
 ┗ 📜 README.md
```

---

## 🧪 Sample Problem: 0/1 Knapsack

```cpp
int knapsack(int W, int wt[], int val[], int n) {
  if (n == 0 || W == 0) return 0;
  if (wt[n-1] > W)
    return knapsack(W, wt, val, n-1);
  return max(val[n-1] + knapsack(W - wt[n-1], wt, val, n-1), 
             knapsack(W, wt, val, n-1));
}
```

⏱️ Time Complexity: `O(2^n)`  
✅ Optimized DP Version: `O(n*W)`

---

## 📚 Applications

- 📱 App development and backend optimization
- 🏆 Competitive programming & coding contests
- 🎓 Academic research and algorithm analysis
- 🧠 Interview prep (Google, Meta, Amazon)

---

## 🔧 Tools & Tech Used

| Tech/Language | Usage                   |
|---------------|-------------------------|
| 🐍 Python      | Algorithm Prototyping   |
| 💻 C++/Java     | Competitive Coding      |
| 🧠 Graphviz    | Graph Visualizations    |
| 📊 Mermaid.js | Flowcharts & Diagrams   |
| 🔍 VSCode      | Development Environment |

---

## 🧑‍💻 Author

```yaml
👨‍💻 Developer: Harish Lukare
🎓 Background: Computer Science Engineering
🎯 Interests: Algorithms | AI | Full-Stack Dev
🏆 Hackathon Wins: SIH 2024, Hack-a-Sol
```

---

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first  
to discuss what you would like to change.

---

## 📌 Disclaimer

This repository is maintained for educational purposes.  
All algorithms follow standard structures as per academic guidelines.
