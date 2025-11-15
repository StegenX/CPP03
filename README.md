## CPP03 — Module 03 (C++98)

This repository contains an implementation of the 42 School "CPP03" exercises (ex00–ex03) implemented in C++98. The project demonstrates class design, inheritance, and multiple inheritance (diamond problem) using the ClapTrap family of classes.

All code targets C++98 and is compiled with the following flags in each `Makefile`:

- `-Wall -Wextra -Werror -std=c++98`

Project layout

- `ex00/` — ClapTrap
  - `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`, `Makefile`
- `ex01/` — ScavTrap (inherits `ClapTrap`)
  - `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `main.cpp`, `Makefile`
- `ex02/` — FragTrap (inherits `ClapTrap`)
  - `ClapTrap.hpp`, `ClapTrap.cpp`, `FragTrap.hpp`, `FragTrap.cpp`, `main.cpp`, `Makefile`
- `ex03/` — DiamondTrap (inherits `ScavTrap` and `FragTrap`)
  - `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `FragTrap.hpp`, `FragTrap.cpp`, `DiamondTrap.hpp`, `DiamondTrap.cpp`, `main.cpp`, `Makefile`

Top-level `Makefile` builds every exercise with the `all` target and delegates to each sub-`Makefile`.

Build

To build everything from the project root:

```zsh
make
```

To build a single exercise (for example `ex03`):

```zsh
make -C ex03
```

Run

After building, run the produced binary inside each exercise folder. Example for `ex03`:

```zsh
cd ex03
./ex03
```

Memory/Quality

- All classes follow the Orthodox Canonical Form (default ctor, copy ctor, dtor, assignment) where required.
- `ScavTrap` and `FragTrap` use virtual inheritance of `ClapTrap` in `ex03` to resolve the diamond problem; `DiamondTrap` initializes the virtual `ClapTrap` base as required.
- No heap allocations are used in the exercises; valgrind should report no leaks. Example check:

```zsh
valgrind --leak-check=full ./ex03
```

Notes

- The demos in `main.cpp` files show basic usage and exercise features: attacking, taking damage, repairing, the `guardGate()` mode for `ScavTrap`, `highFivesGuys()` for `FragTrap`, and `whoAmI()` for `DiamondTrap`.
- The code is intentionally simple and follows the 42 Norminette-friendly layout (headers with include guards, small functions, clear file separation).

