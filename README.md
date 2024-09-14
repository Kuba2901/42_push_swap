# 42PushSwap

## Description

The **42PushSwap** project is designed to sort a stack of integers using a minimal number of operations. Developed as part of the 42 curriculum, this project focuses on implementing efficient sorting algorithms to achieve optimal results with a limited set of operations. The goal is to understand and apply algorithmic techniques for sorting and optimize the number of moves required to sort the stack.

## Features

- **Sorting Algorithms**: Implements various sorting techniques tailored for stack-based sorting.
- **Operation Optimization**: Uses a minimal number of operations to sort the stack.
- **Stack Representation**: Handles integer stacks with push and swap operations.
- **Performance Analysis**: Analyzes and optimizes sorting performance.

## Getting Started

### Prerequisites

- C/C++ compiler (e.g., GCC)
- Make utility
- Basic understanding of sorting algorithms and stack operations

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/kuba2901/42_push_swap.git
   ```

2. Navigate to the project directory:

   ```bash
   cd 42_push_swap
   ```

3. Compile the project:

   ```bash
   make
   ```

4. Run the program:

   ```bash
   ./push_swap <numbers>
   ```

   Replace `<numbers>` with a sequence of integers separated by spaces.

### Usage

1. **Sorting the Stack**

   To sort a stack of integers, provide the sequence of numbers as command-line arguments:

   ```bash
   ./push_swap 3 1 4 2 5
   ```

   This command will output the sequence of operations needed to sort the stack.

2. **Visualizing the Solution**

   If you want to visualize the operations, you can use the provided script (if applicable):

   ```bash
   ./visualize.sh <numbers>
   ```

   This script will display the steps taken to sort the stack visually.

### Example

To sort the stack with the numbers 5, 2, 9, 1, and 7:

```bash
./push_swap 5 2 9 1 7
```

The program will output the sequence of operations required to sort these numbers in ascending order.

## Project Structure

- `push_swap.c`: Entry point of the program and main sorting logic.
- `stack.c`: Contains stack operations and management functions.
- `utils.c`: Utility functions used in the sorting process.
- `Makefile`: Build script for compiling the project.