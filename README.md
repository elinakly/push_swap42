# Push_swap

Push_swap is a School 42 project designed to sort a stack of integers using a limited set of operations. The goal is to implement an efficient algorithm and achieve the minimum number of moves.

## Project Details
- **Score**: 84/100
- **Sorting Algorithm**: Radix Sort
- **Language**: C

This repository includes both the implementation of the sorting logic and a tester to validate the correctness of the solution.

## Features
- Efficient Radix Sort implementation for stack sorting.
- Error handling for invalid input.
- Tester included to verify correctness and performance.

## Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   ```
2. Navigate to the project directory:
   ```bash
   cd push_swap42
   ```
3. Initialize the submodule for the tester:
   ```bash
   git submodule update --init
   ```

## Usage
To compile the project, run:
```bash
make
```

Then, execute the program with a list of integers to sort:
```bash
./push_swap 4 2 3 1
./push_swap "4 2 3 1"
```

To test your solution using the included tester, follow the instructions provided in the tester directory.

## Resources
- [Push_swap_tester](https://github.com/gemartin99/Push-Swap-Tester) (for instraction to tester)
- Submodule: Included tester to validate your program.

Feel free to contribute or provide feedback on this repository!

