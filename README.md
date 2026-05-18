# Memory Addressing in C++

This project is a class assignment for the Operating Systems course (300CIG011). It explores memory addressing concepts in C++ through a series of hands-on activities. The main objectives are to understand and demonstrate the use of pointers, references, pointer arithmetic, and dynamic memory management.

## Prerequisites

- `g++` (version 9 or higher)
- `make`
- `valgrind` (for memory leak checking in Activity 4)
- `Docker` (optional, for a consistent build environment)

## Project Structure

```
memory_addressing/
├── src/
│   ├── activity1.cpp     ← Variables, pointers, and basic addresses
│   ├── activity2.cpp     ← Pointers, references, and their addresses
│   ├── activity3.cpp     ← Arrays and pointer arithmetic
│   ├── activity4.cpp     ← Dynamic memory (new/delete) with a 2D matrix
│   └── extra.cpp         ← Visualization of stack, heap, and code segments
├── include/
│   └── MemoryUtils.h     ← Shared utility functions (printAddress, printSeparator)
├── bin/
│   ├── activity1         ← Executable for Activity 1
│   ├── activity2         ← Executable for Activity 2
│   ├── activity3         ← Executable for Activity 3
│   ├── activity4         ← Executable for Activity 4
│   └── extra             ← Executable for Extra
├── Makefile
└── README.md
```

## Build & Run

### Build all activities
```bash
make all
```

### Run all activities
```bash
make run-all
```

### Run individual activities
```bash
make act1
make act2
make act3
make act4
make extra
```

### Clean binaries
```bash
make clean
```

### Manual Compilation (if you don't have `make`)

If you don't have `make`, you can compile and run each activity manually.

**1. Create a directory for the binaries:**
```bash
mkdir bin
```

**2. Compile each activity:**
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -O0 -g -I include -o bin/activity1 src/activity1.cpp
g++ -std=c++17 -Wall -Wextra -Wpedantic -O0 -g -I include -o bin/activity2 src/activity2.cpp
g++ -std=c++17 -Wall -Wextra -Wpedantic -O0 -g -I include -o bin/activity3 src/activity3.cpp
g++ -std=c++17 -Wall -Wextra -Wpedantic -O0 -g -I include -o bin/activity4 src/activity4.cpp
g++ -std=c++17 -Wall -Wextra -Wpedantic -O0 -g -I include -o bin/extra src/extra.cpp
```

**3. Run each activity:**
```bash
# On Linux/macOS/Git Bash
./bin/activity1

# On Windows PowerShell
.\bin\activity1
```

### Using Docker
To build and run in a containerized environment:
```bash
docker run --rm -v $(pwd):/workspace gcc:latest bash -c \
  "cd /workspace && make all && make run-all"
```

### Verify Activity 4 for memory leaks
```bash
valgrind --leak-check=full ./bin/activity4
```

## Activity Outputs

*(Outputs will be populated here after running the code)*

### Activity 1
```
==========================================
 Activity 1 — Variables & Pointers
==========================================
[Step 1] value          = 42
[Step 2] Address        = 0x...
[Step 3] Modified value = 100  (via pointer *ptr = 100)
[Step 4] value          = 100  | Address = 0x...  (unchanged)
==========================================
```

### Activity 2
```
==========================================
 Activity 2 — Pointers & References
==========================================
[Step 1] variable       = 55
[Step 2] via *ptr       = 55  →  *ptr = 200  →  variable = 200
[Step 3] via ref        = 200 →  ref = 300   →  variable = 300
[Step 4] &variable      = 0x...
         ptr (points to)= 0x...  ← same as &variable
         &ptr (ptr addr) = 0x... ← different (ptr is its own variable)
         &ref            = 0x... ← same as &variable (ref is an alias)
==========================================
```

### Activity 3
```
==========================================
 Activity 3 — Arrays & Pointer Arithmetic
==========================================
Original array  : 10  20  30  40  50  
Modified array  : 20  40  60  80  100  
Array base addr : 0x...
Pointer &ptr    : 0x...  ← different from array base
Element details :
  [0] addr=0x... value=20
  [1] addr=0x... value=40
  [2] addr=0x... value=60
  [3] addr=0x... value=80
  [4] addr=0x... value=100
==========================================
```

### Activity 4
```
==========================================
 Activity 4 — Dynamic Memory (new/delete)
==========================================
[Step 1] singleInt = 99  | addr = 0x...
[Step 1] Memory released for singleInt.

[Step 2-3] 3x4 Dynamic Matrix (i+1)*(j+1):
Row 0 [addr=0x...]:   1   2   3   4
Row 1 [addr=0x...]:   2   4   6   8
Row 2 [addr=0x...]:   3   6   9  12

[Step 5] Memory released successfully.
==========================================
```

### Extra
```
┌─────────────────────────────────────┐
│         MEMORY MAP (approx)         │
├─────────────────────────────────────┤
│  [HIGH]  Stack  →  0x7ff...         │
│          stackVar = 111             │
├─────────────────────────────────────┤
│  [MID ]  Heap   →  0x55a...         │
│          heapVar  = 222             │
├─────────────────────────────────────┤
│  [LOW ]  Data   →  0x55a...         │
│          staticVar = 333            │
├─────────────────────────────────────┤
│  [LOW ]  Code   →  0x55a...         │
│          main() address             │
└─────────────────────────────────────┘
```

## Memory Regions — Key Concepts

| Region | Location | Managed by | Content |
|--------|----------|------------|---------|
| Stack  | High addr| OS/CPU     | Local variables, function frames |
| Heap   | Mid addr | Programmer | `new`/`delete` allocations |
| Data   | Low-mid  | OS         | Global and static variables |
| Code   | Low addr | OS         | Compiled instructions (read-only) |

## Design Constraints

- **No `break` or `continue`**: Control flow is managed using standard loop conditions.
- **Standard Library Only**: The project relies exclusively on the C++ standard library.
- **RAII**: Resource Acquisition Is Initialization is applied, especially for dynamic memory in Activity 4, ensuring no memory leaks.

## Author

- **Name**: Your Name
- **Course**: Sistemas Operativos
- **Date**: May 18, 2026

