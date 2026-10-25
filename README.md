# Linked List Management System

> **DSA Mini Project — 2nd Year College Level**  
> A menu-driven console application implementing Singly and Doubly Linked Lists with comprehensive operations, edge-case validation, memory management, and comparative analysis.

---

## Objective

The objective of this project is to implement and demonstrate a complete, modular, and robust **Linked List Management System** in **C++**. The application provides practical implementations of:
- **Singly Linked List (SLL)**
- **Doubly Linked List (DLL)**
- **Comparative Analysis Tool (Singly vs. Doubly Linked List)**

The project emphasizes core Data Structures and Algorithms (DSA) concepts, including manual dynamic memory management (`new` and `delete`), pointer rewiring, two-pointer algorithms (Slow and Fast pointer / Tortoise and Hare), in-place pointer reversal, sorting, and duplicate removal without auxiliary storage.

---

## Language Used: C++

- **Standard:** C++11 (or newer)
- **Compilers Supported:** MinGW GCC / Clang / MSVC
- **Memory Management:** Pure pointer-based heap allocation via `new` / explicit deallocation via `delete` in RAII destructors.
- **I/O:** `std::cin` / `std::cout` with comprehensive stream error recovery.

---

## Project Structure

```
Linked-List-Management-System/
├── .gitignore                      # Git ignore patterns for build artifacts
├── README.md                       # Main project documentation & run guide
├── docs/
│   └── project-report.md           # Comprehensive technical report & viva guide
├── sample-output/
│   └── output.txt                  # Complete execution transcript with all test cases
└── src/
    ├── SinglyLinkedList.h          # Singly Linked List declarations & Node structure
    ├── SinglyLinkedList.cpp        # Singly Linked List operation definitions
    ├── DoublyLinkedList.h          # Doubly Linked List declarations & Node structure
    ├── DoublyLinkedList.cpp        # Doubly Linked List operation definitions
    └── main.cpp                    # Interactive menu loop & comparison tool
```

---

## Features

- **Interactive Menu Driven Architecture:** Easy navigation through clean, styled console menus.
- **Robust Input Validation:** Re-prompts safely on invalid non-integer inputs without stream corruption or infinite loops.
- **Zero Memory Leaks:** Destructors clean up all dynamically allocated heap nodes upon exit or list clearing.
- **100% Native Implementation:** Built without standard container libraries (`std::vector`, `std::list`).
- **Comprehensive Edge-Case Testing:** Handled empty lists, single-node lists, out-of-bounds positions, negative values, and non-existent targets.

---

## Singly Linked List

A linear dynamic list where each node contains:
- `int data`: The value stored in the node.
- `SinglyNode* next`: Pointer to the next node in the sequence (terminating in `nullptr`).

### Operations Implemented (1 to 20):
1. **Insert at Beginning:** Prepend node before `head`. $O(1)$.
2. **Insert at End:** Traverse to tail and link new node. $O(n)$ without tail pointer.
3. **Insert at Position:** Insert at 1-based index; validates bounds $[1, N+1]$. $O(n)$.
4. **Insert After a Node:** Locate target value and insert immediately after it. $O(n)$.
5. **Insert Before a Node:** Locate target value and insert immediately before it. $O(n)$.
6. **Delete from Beginning:** Remove head and advance `head` to `head->next`. $O(1)$.
7. **Delete from End:** Traverse to second-to-last node and deallocate tail. $O(n)$.
8. **Delete from Position:** Delete node at 1-based index $[1, N]$. $O(n)$.
9. **Delete by Value:** Find first occurrence of value and decouple it. $O(n)$.
10. **Search:** Sequential search returning 1-based position or $-1$. $O(n)$.
11. **Update:** Find matching node and overwrite its data. $O(n)$.
12. **Display:** Print list in format `val -> val -> NULL`. $O(n)$.
13. **Count Nodes:** Count all active nodes from `head`. $O(n)$.
14. **Find Maximum:** Traverse and identify largest numerical value. $O(n)$.
15. **Find Minimum:** Traverse and identify smallest numerical value. $O(n)$.
16. **Find Middle Element:** Uses slow and fast pointers. Defines the rule for even-length lists: displays second middle ($N/2 + 1$) as primary and first middle ($N/2$). $O(n)$.
17. **Reverse:** In-place pointer reversal using `prev`, `curr`, and `next` in $O(n)$ time and $O(1)$ space.
18. **Sort:** Bubble sort on node values in ascending order. $O(n^2)$ time, $O(1)$ space.
19. **Remove Duplicates:** In-place nested runner loop removing repeated nodes without extra space. $O(n^2)$ time, $O(1)$ space.
20. **Exit:** Return to Main Application Menu.

---

## Doubly Linked List

A bidirectional list where each node contains:
- `int data`: The value stored in the node.
- `DoublyNode* prev`: Pointer to antecedent node.
- `DoublyNode* next`: Pointer to successor node.
- Maintained pointers: Both `head` and `tail` pointers.

### Operations Implemented (1 to 21):
1. **Insert at Beginning:** Prepend before head, update backlinks. $O(1)$.
2. **Insert at End:** Attach after tail using cached `tail` pointer. $O(1)$.
3. **Insert at Position:** Insert at 1-based index maintaining both directions. $O(n)$.
4. **Insert After a Node:** Reconnect neighboring links after first matching node. $O(n)$.
5. **Insert Before a Node:** Reconnect neighboring links before first matching node. $O(n)$.
6. **Delete from Beginning:** Remove head and update `head->prev = nullptr`. $O(1)$.
7. **Delete from End:** Remove tail using `tail->prev`. $O(1)$.
8. **Delete from Position:** Decouple node at given index and stitch neighbors. $O(n)$.
9. **Delete by Value:** Delete first matching node and update neighbor links. $O(n)$.
10. **Search:** Return 1-based position of target. $O(n)$.
11. **Update:** Replace data of first matching node. $O(n)$.
12. **Display Forward:** Traverse using `next` links: `NULL <- 10 <-> 20 -> NULL`. $O(n)$.
13. **Display Backward:** Traverse from `tail` using `prev` links: `NULL <- 20 <-> 10 -> NULL`. $O(n)$.
14. **Count Nodes:** Traverse and count elements. $O(n)$.
15. **Find Maximum:** Identify largest value in the list. $O(n)$.
16. **Find Minimum:** Identify smallest value in the list. $O(n)$.
17. **Find Middle Element:** Slow and fast pointer technique with even-length rule handling. $O(n)$.
18. **Reverse:** Swap `prev` and `next` pointers for every node and swap `head` and `tail`. $O(n)$ time, $O(1)$ space.
19. **Sort:** Ascending order Bubble sort while preserving link integrity. $O(n^2)$ time, $O(1)$ space.
20. **Remove Duplicates:** In-place duplicate elimination updating both directions and `tail`. $O(n^2)$ time, $O(1)$ space.
21. **Exit:** Return to Main Application Menu.

---

## Comparative Analysis: Singly vs. Doubly Linked List

| Feature / Metric | Singly Linked List | Doubly Linked List |
|---|---|---|
| **Pointers per Node** | 1 pointer (`next`) | 2 pointers (`prev`, `next`) |
| **Memory Overhead** | Lower ($\text{Data} + 1 \text{ ptr}$) | Higher ($\text{Data} + 2 \text{ ptrs}$) |
| **Traversal Direction** | Forward only | Bidirectional (Forward & Backward) |
| **Insert at Beginning** | $O(1)$ | $O(1)$ |
| **Insert at End** | $O(n)$ without tail | $O(1)$ with cached tail |
| **Delete from Beginning** | $O(1)$ | $O(1)$ |
| **Delete from End** | $O(n)$ (must traverse to $n-1$) | $O(1)$ (direct via `tail->prev`) |
| **Delete Given Node Pointer**| $O(n)$ (must find predecessor) | $O(1)$ (`node->prev` directly known) |
| **Implementation Complexity**| Simpler | Moderate (synchronizing two links) |
| **Common Use Cases** | Simple queues, hash chaining | LRU Cache, text editors, playlists |

---

## How to Run

### Prerequisites
- GCC / MinGW C++ compiler (`g++`) or Clang / MSVC.

### Compilation
From the project root directory:

```bash
# Windows / Linux / macOS using g++
g++ -std=c++11 -Wall -Wextra src/main.cpp src/SinglyLinkedList.cpp src/DoublyLinkedList.cpp -o LinkedListApp.exe
```

### Execution
```bash
# On Windows PowerShell or Command Prompt:
.\LinkedListApp.exe

# On Linux / macOS:
./LinkedListApp.exe
```

---

## Sample Output

### 1. Singly Linked List (Sort & Reverse Example from PDF)
```text
Before:
40 -> 10 -> 30 -> 20 -> 50 -> NULL

After Sort:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

After Reverse:
50 -> 40 -> 30 -> 20 -> 10 -> NULL
```

### 2. Doubly Linked List (Forward & Backward Example from PDF)
```text
Forward:
NULL <- 10 <-> 20 <-> 30 <-> 40 -> NULL

Backward:
NULL <- 40 <-> 30 <-> 20 <-> 10 -> NULL
```

> **Note:** A complete terminal session covering all 20+ operations and boundary test runs is documented in [`sample-output/output.txt`](file:///sample-output/output.txt).

---

## Time & Space Complexity Summary

| Operation | Best Case Time | Worst Case Time | Space Complexity |
|---|:---:|:---:|:---:|
| **Insert at Beginning** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Insert at End** | $O(1)$ (DLL) / $O(n)$ (SLL) | $O(1)$ (DLL) / $O(n)$ (SLL) | $O(1)$ |
| **Insert at Position** | $O(1)$ | $O(n)$ | $O(1)$ |
| **Delete from Beginning** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Delete from End** | $O(1)$ (DLL) / $O(n)$ (SLL) | $O(1)$ (DLL) / $O(n)$ (SLL) | $O(1)$ |
| **Search / Display / Count** | $O(1)$ | $O(n)$ | $O(1)$ |
| **Find Min / Max** | $O(n)$ | $O(n)$ | $O(1)$ |
| **Find Middle Element** | $O(n)$ | $O(n)$ | $O(1)$ |
| **Reverse** | $O(n)$ | $O(n)$ | $O(1)$ |
| **Bubble Sort** | $O(n)$ (if sorted check) | $O(n^2)$ | $O(1)$ |
| **Simple Remove Duplicates** | $O(n^2)$ | $O(n^2)$ | $O(1)$ |

---

## Edge Cases Handled

- [x] **Empty linked list:** All deletions, searches, extrema, and displays safely alert the user.
- [x] **One-node list:** Deletions reset head/tail to `nullptr`; reverse and sort exit cleanly.
- [x] **Insert/delete at position 1:** Safely handled as head operations.
- [x] **Insert at last valid position ($N+1$):** Safely handles appending.
- [x] **Invalid/out-of-range position ($pos < 1$ or $pos > N+1$):** User alerted with clear error message.
- [x] **Delete non-existent value:** Traverses list safely and reports missing target.
- [x] **Duplicate values:** Handled and removed in-place.
- [x] **Zero and negative values:** Supported natively across all mathematical and relational operations.
- [x] **Reverse/Sort on empty or single-node list:** Safe no-ops without null pointer exceptions.

---

## Viva Voce / Evaluation Questions

Detailed answers to all 15 university evaluation questions are provided in [`docs/project-report.md`](file:///docs/project-report.md#6-viva-voce--evaluation-questions-guide).

---

## Author
- **Project:** DSA Mini Project (2nd Year College Level)
- **Course:** Data Structures & Algorithms
