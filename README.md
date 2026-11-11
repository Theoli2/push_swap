# push_swap — sorting with two stacks and a limited instruction set

A 42 curriculum project in C: sort a list of integers using **two stacks (`a` and `b`) and only 11 operations**, while printing **as few operations as possible**. The repository also contains a `checker` program that runs those operations and verifies the result.

## Build & run

```bash
make                      # builds ./push_swap and ./checker
./push_swap 2 1 3 6 5 8   # prints the operations, one per line
```

Check that the output really sorts the numbers:

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker $ARG    # OK
./push_swap $ARG | wc -l             # number of operations
```

Invalid input (non-integer, out of `int` range, duplicates) prints `Error` on standard error.

## The rules

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | move the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate up: the first element becomes the last (`a` / `b` / both) |
| `rra` / `rrb` / `rrr` | rotate down: the last element becomes the first (`a` / `b` / both) |

## Algorithm

1. **Normalise**: each value is replaced by its rank (`0` to `n-1`), so the rest of the algorithm only works with small, contiguous indexes.
2. **Small inputs**: 2 numbers take at most one `sa`. 3 numbers are handled case by case in at most 2 operations.
3. **Pre-sort into `b`**: while `a` holds more than 3 elements, the lower half of `a` (indexes below the median) is pushed to `b`, each time rotating `a` in whichever direction (`ra` or `rra`) reaches the next element faster. The last 3 elements left in `a` are sorted directly.
4. **Greedy insertion back into `a`**: for every element of `b`, compute the cost of moving it to the top of `b` **and** its target position (the smallest bigger index) to the top of `a`. Rotations in the same direction are merged (`ra` + `rb` → `rr`, `rra` + `rrb` → `rrr`). The cheapest element is pushed with `pa`, then the process repeats.
5. **Final rotation**: `a` is rotated in the shortest direction until the smallest element is on top.

## Performance

Measured on random inputs, every run validated by the official checker:

| Numbers | Average | Worst seen | Runs |
|---|---|---|---|
| 3 | ≤ 2 | 2 | 50 |
| 5 | 9.5 | 12 | 50 |
| 100 | 564 | 623 | 50 |
| 500 | 4 297 | 4 472 | 20 |

These counts are under the limits needed for the maximum grade at 42 (fewer than 700 operations for 100 numbers and 5 500 for 500).

## Checker (bonus)

`./checker` takes the same numbers as arguments, reads operations from standard input, runs them, and prints `OK` if `a` is sorted and `b` is empty, `KO` otherwise, or `Error` for an invalid operation.

## Project structure

```
.
├── Makefile
├── srcs/              # push_swap
│   ├── main.c, verif.c                    # entry point, input validation
│   ├── index.c                            # rank normalisation
│   ├── push.c, swap.c, rotate.c, reverse_rotate.c, do_rotate.c   # the 11 operations
│   ├── small_sort.c                       # 2 and 3 elements
│   ├── big_sort.c, big_sort_bis.c         # pre-sort and greedy insertion
│   └── calculate_moves*.c                 # cost of each candidate move
├── push_swap_bonus/   # checker
└── libft/             # my own C library (libc functions, ft_printf, get_next_line)
```

The stacks are singly linked lists. Each node stores the original value and its rank.

## Tech

C · linked lists · greedy algorithm · Makefile
