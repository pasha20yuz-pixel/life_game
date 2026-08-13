# Conway's Game of Life

A C implementation of Conway's Game of Life — a cellular automaton created by mathematician John Conway.

The project simulates the evolution of a two-dimensional grid according to a simple set of rules and includes several predefined patterns, random world generation and file-based world storage.

## Features

- 🧬 Conway's Game of Life simulation
- 🎲 Random world generation with configurable density
- 🚀 Predefined patterns such as:
  - Glider
  - Blinker
- 💾 Save and load worlds from files
- 🧩 Modular C architecture
- ⚙️ Configurable world dimensions

## How Conway's Game of Life Works

Each cell in the grid can be either alive or dead.

For every generation:

1. A live cell survives with two or three live neighbours.
2. A live cell with fewer than two neighbours dies.
3. A live cell with more than three neighbours dies.
4. A dead cell with exactly three neighbours becomes alive.

All cells are updated simultaneously, producing the next generation.

## Project Structure

```text
src/
├── main.c
├── world.c
├── world.h
├── patterns.c
├── patterns.h
├── file_io.c
└── file_io.h
```
## Modules

world.c / world.h

Responsible for the game world and simulation logic, including neighbour counting and generation updates.

patterns.c / patterns.h

Contains predefined cellular patterns such as the Glider and Blinker.

file_io.c / file_io.h

Handles saving and loading the world state.

main.c

Provides the application entry point and connects the different components.

## Technologies
- C
- Standard C Library
- Modular programming
- File I/O
- Dynamic memory management
## Building

Compile the project with GCC:
```bash
gcc src/main.c src/world.c src/patterns.c src/file_io.c -o life_game
```
On Windows:
```bash
gcc src/main.c src/world.c src/patterns.c src/file_io.c -o life_game.exe
```
## Running

After compilation:
```bash
./life_game
```
On Windows:
```bash
life_game.exe
```
## What I Practiced

This project was developed as a practical C programming project and helped me practice:

- modular program structure;
- working with .c and .h files;
- dynamic memory management;
- algorithms and data structures;
- file input/output;
- simulation of discrete systems;
- debugging and working with GCC.
