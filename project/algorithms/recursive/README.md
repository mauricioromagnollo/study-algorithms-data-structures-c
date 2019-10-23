# Recursive Algorithms

#### Recursion is the definition of a subroutine (function or method) that can invoke itself. Something is recursive when it is defined in terms of her own. 
- A recursive algorithm must make at least one call to itself, either directly (we can see the algorithm being called within itself) or indirectly (the algorithm calls another algorithm, which in turn invokes a call to the first one);
- A recursive algorithm must have at least one stop condition so that it is not invoked indefinitely. This stopping condition corresponds to sufficiently small or simple instances of the original problem that can be solved directly;
- For every recursive algorithm there is at least one corresponding iterative algorithm. However, it can often be difficult to find such correspondence.

![recursion-icon](https://user-images.githubusercontent.com/38081852/65381540-f5afff00-dcc9-11e9-8f15-c3acc380b89d.png)

> ### Advantages

  - More compact, readable and easy to understand compared to iterative algorithms;
  - They are easy to implement in high level programming languages;

> ### Disadvantages

  - They use the memory stack heavily, which requires memory allocation and deallocation;
  - Iterative implementation tends to be slightly faster in practice than recursive implementation, because a recursive implementation needs to record the current state of processing so that it can continue where it left off after each new subordinate execution of the recursive procedure, however, it may be valid to sacrifice efficiency for the sake of clarity;
  - Recursive algorithms are harder to debug during the development phase.

> ### Aplications

  - They are applied when the iterative form will generate a very long algorithm;
  - Problems involving tree manipulation;
  - Recursive lexical analyzers of compilers;
  - Problems involving trial and error ("Backtracking");
  - Recursiveness is worth it for complex algorithms whose iterative implementation is complex and usually requires the explicit use of a stack:
    - Split to Conquer (Ex. Quicksort);
    - Trees (research, backtracking).

> ### How do algorithms work?

In general, a recursive definition is defined by cases: a limited number of **base cases** and a **recursive case**. Base cases are usually trivial situations and do not involve recursion.

- **One Base Case** (Simple Cases of the item to be defined are data explicitly); => ***Starting Point***
- **A Recursive Step** (Cases of the item to be defined are generated from previous cases); => ***Generate new cases***

![recursive-function](https://user-images.githubusercontent.com/38081852/65381543-0ceeec80-dcca-11e9-90bd-aae838e6a8b4.png)