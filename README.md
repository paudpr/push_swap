# push_swap

42 Cursus - push_swap: this project is a sorting algorithm with a set of given rules. 

## Table of contents 📑
- [Status](#status)
- [About the project](#about-the-project)
    * [The Rules](#rules)
    * [Project boundaries](#project-boundaries)
- [How to use](#how-to-use)

## Status ✔️
- Status: finished
- Score: 84%
- Observations: learned about different algorithms and bitwise operations

## About the project 👩‍💻

This project aims to define an efective sorting algorithm for given data on a stack, with a  limited set of instructions and the smallest number of moves possible. 

### The Rules 📏

Sort stack `a`. You can use an auxiliary empty stack `b`. 
You will recieve a randon number of whole numbers that must be stacked in `a`. You must handle wrong input (duplicates, letters, etc).
Once sorted the numbers in stack `a` will follow ascending order.
You can only use the following operations to move the numbers arround:

### Movement boundaries 🔧

- `sa` - `swap a`: swap the first two elements at the top of stack a.
- `sb` - `swap b`: swap the first two elements at the top of stack b.
- `ss`: do  both `sa` and `sb` at the same time.
- `pa` - `push a`: take the element at the top of b and put it at the top of b.
- `pb` - `push b`: take the element at the top of a and put it at the top of a.
- `ra` - `rotate a`: shift forward all elements in a by one. The first element becomes the last one.
- `rb` - `rotate b`: shift forward all elements in b by one. The first element becomes the last one.
- `rr` - do both `ra` and `rb` at the same time.
- `rra` - `reverse rotate a`: shift backwards all elements in a by one. The last element becomes the first one.
- `rrb` - `reverse rotate b`: shift backwards all elements in b by one. The last element becomes the first one.
- `rrr` - do both `rra` and `rrb` at the same time.

## Algorithm 🧮

I used radix. As I could only use two stacks it is implemented using bitwise operations.
It could be improved on number of moves performance easily by checking on each operation if next number is also going to be changed, so it cat skip some movements. It would, on the other hand, add incrementaly execution time for bigger inputs.
For inputs of 5 or less items, radix doesn't optimize correctly the number of movements so it's hardcoded.

## How to use

Run `make`

```sh
./push_swap 3 4 0 2 1
```

To use the checker file that scans the stack and gives OK if it's correctly sorted

```sh
./push_swap 5 4 1 0 2 3 | ./checker_Mac 5 4 1 0 2 3
```
or

```sh
ARG="5 4 1 0 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
```

##
