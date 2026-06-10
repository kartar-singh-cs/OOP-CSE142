# Object-Oriented Programming — CSE142
![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue?style=flat-square)
![IBA](https://img.shields.io/badge/Institute-IBA%20Karachi-yellow?style=flat-square)
![Course](https://img.shields.io/badge/Course-CSE142-lightgrey?style=flat-square)

My lab work, assignments, and game project from Object-Oriented Programming at IBA Karachi. This course picked up right where ITP left off — moving from procedural C++ into the world of classes, inheritance, polymorphism, and eventually algorithms and templates.

The jump from Lab 1 to Lab 12, and then the game project at the end, shows how much the course demanded in terms of design thinking, not just syntax.

---

## 📂 Structure

```
oop-cs142/
├── Labs/
│   ├── Lab01/    → classes and objects, constructors, destructors
│   ├── Lab02/    → encapsulation, access specifiers
│   ├── Lab03/    → operator overloading
│   ├── Lab04/    → inheritance basics
│   ├── Lab05/    → multilevel and multiple inheritance
│   ├── Lab06/    → polymorphism and virtual functions
│   ├── Lab07/    → abstract classes and interfaces
│   ├── Lab08/    → templates (function and class)
│   ├── Lab09/    → STL — vectors, maps, pairs
│   ├── Lab10/    → exception handling
│   ├── Lab11/    → more STL and generic programming
│   ├── Lab12/    → sorting algorithms (selection, insertion, merge, quick)
│
├── Assignments/
│   ├── Assignment01/
│   └── Assignment02/
│
└── OOP_Game_Project_pdf/
    └── SpaceInvaders_Report.pdf   → full project documentation
```

---

## 🧠 Topics Covered

| Topic | What I Practiced |
|:------|:----------------|
| **Classes & Objects** | Constructors, destructors, member functions, access specifiers |
| **Encapsulation & Abstraction** | Data hiding, interface design, abstract classes |
| **Inheritance** | Single, multilevel, and multiple inheritance |
| **Polymorphism** | Virtual functions, function overriding, runtime dispatch |
| **Operator Overloading** | Custom operators for user-defined types |
| **Templates** | Function templates, class templates, generic programming |
| **STL** | `vector`, `map`, iterators, and standard algorithms |
| **Exception Handling** | `try/catch/throw`, custom exception classes |
| **Sorting Algorithms** | Selection, insertion, merge, and quicksort |

---

## 🎮 Game Project — Space Invaders

A fully functional **Space Invaders** clone built in C++ as the course's capstone project. The game applies OOP principles throughout — enemies, bullets, and the player are all modelled as objects with their own state and behaviour.

The full project report and documentation are in the `OOP_Game_Project_pdf/` folder.

The playable game is hosted separately on GitHub:
👉 [Space Invaders – View Repository](https://github.com/kartar-singh-cs/space-invaders)

---

## 📌 A Few Things Worth Noting

The polymorphism and virtual function labs were where OOP started to feel like a different way of thinking about code — designing around behaviour rather than just data. Writing abstract base classes and letting derived classes handle the specifics was a shift that took a few labs to really sink in.

The sorting algorithms at the end were a nice contrast — going back to pure logic and complexity analysis after weeks of class design. Implementing merge sort and quicksort from scratch, and then benchmarking them, made the theory feel a lot more tangible.

---

## ⚙️ How to Run Any Task

All tasks are standard C++ — no external libraries needed.

```bash
g++ -std=c++17 task1.cpp -o task1
./task1
```

---

## 👨‍💻 Developer

**Kartar Singh**
CS Student @ IBA Karachi
[github.com/kartar-singh-cs](https://github.com/kartar-singh-cs)
