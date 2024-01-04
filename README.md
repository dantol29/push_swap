# Push_swap 
Project that involves sorting a stack of integers using a limited set of operations. The goal is to implement an efficient algorithm to sort the stack with the minimum number of moves.

## Usage
```
make
```
```
./push_swap 4 2 7 1
```
## Tester 
```
make bonus
```
```
./tester 4 2 7 1 or ./push_swap 4 2 7 1 | ./tester 4 2 7 1
```
## Effiency
100 numbers - ~650 instructions

500 numbers - ~5500 instructions
## Algorithm
I have tried Insertion sort, Quicksort, "Divide and Conquer" approach, however "the cheapest move" algorithm turned out to be the best

Video that explains how this approach works - https://youtu.be/OaG81sDEpVk?si=ClfUaMz8SdSunAZ1
## Visualizer
The best tool to visualize your algorithm - https://github.com/o-reo/push_swap_visualizer
## Structure
Push everything, but 3 numbers from the stack a to the stack b
```
if (a->size_a == 2 && check_if_sorted(a) != 1) // if only 2 numbers and they are not sorted
  sa(a);
else if (a->size_a == 3) // there are only 5 possible combinations of 3 numbers (3! = 6 - 1(1 is sorted)) 
  sort_3(a);
else
{
  while (a->size_a > 3) // push everything, but 3 numbers from the stack a to the stack b
    pb(a);
  sort_3(a);
  solve(a);
}
```
Push the cheapest number back to a
```
while (a->size_b > 0) // until b is empty
{
  get_target(a); // assign target position for each number in b
  get_cost(a); // calculate the cost of moving b on top of the stack and to the right position in a
  move_cheapest(a); // compare prices and move the cheapest
}
shift_stack(a);
```
## Error handling
You have to handle mixed arguments
```
./push swap "1 2" 3 4 " 5 6"
```
Empty string - Error on STDIN
```
./push_swap "" 1
Error
```
MAX/MIN int - Error on STDIN
```
./push_swap -2147483649
Error
```
Duplicates - Error on STDIN
```
./push_swap 1 1
Error
```
Invalid characters - Error on STDIN
```
./push_swap a --1
Error
```
## What I have learned
1. Time complexity

2. Quicksort algorithm

3. Insertion algorithm

4. Quite a few custom algorithms

5. How to work with STDIN

6. Mastered memory leaks finding skills  
