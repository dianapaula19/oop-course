# Object-Oriented Programming

> **Original version:** this README and some fixes were added in 2026. To see the project exactly as it was first built, browse commit [`8aab2bb`](https://github.com/dianapaula19/oop-course/tree/8aab2bb3dc11de88c86b4819b21ec57943ccb731) (2020-01-10).

C++ projects for the *Object-Oriented Programming* course at the University of Bucharest (first
year, 2019–2020). Descriptions of the assignments (in Romanian) are in [teme/README.md](teme/README.md).

| Folder | Project | OOP concepts |
|---|---|---|
| `teme/tema_1` | **Sparse polynomial** stored as a linked list of (coefficient, exponent) pairs: addition, subtraction, multiplication | operator overloading, dynamic memory, copy constructor and assignment |
| `teme/tema_2` | **Grocery shop**: stock of products sold by piece, weight or volume (flour, wine, beer, toys...), a customer's shopping list matched to the most profitable items, end-of-day totals | inheritance hierarchy of products, virtual functions, STL containers |
| `teme/tema_3` | **Real-estate agency**: apartments and houses with different rent formulas, managed by a class template `Gestiune<T>` (a `set<pair<T, int>>`, specialised for houses) | abstract base class, pure virtual functions, templates and template specialisation, headers in `include/` and sources in `src/` |
| `simulare_colocviu` | Practice exam: case files (*dosare*) of two kinds and a manager class | inheritance, virtual methods |
| `extra_LP2` | Lab: pharmacies (online and offline) with revenue calculation | abstract classes, pure virtual functions |

## Building

```bash
g++ -std=c++17 teme/tema_1/*.cpp -o polynomial
g++ -std=c++17 teme/tema_3/main.cpp teme/tema_3/src/*.cpp -Iteme/tema_3/include -o agency
```
