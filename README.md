# Sudoku-Solver
## Overview
This is a console-based Sudoku game written in C++. The program offers a variety of Sudoku puzzles across different difficulty levels (Easy, Medium, and Hard), allowing the user to either play the game or view the solution instantly. It also includes a Sudoku solver that uses a backtracking algorithm to solve the puzzles.

## Features
Three Difficulty Levels: Choose from Easy, Medium, or Hard puzzles.
Play Mode: Solve the Sudoku puzzle by entering values for empty cells.
Solver Mode: View the solution to any puzzle instantly.
Random Puzzle Generator: The program randomly selects a puzzle from predefined sets based on the selected difficulty level.
Real-Time Validation: The game checks if the player’s input is valid according to Sudoku rules.
Hint and Solution: Players can opt to view the solution at any point if they get stuck.

## How to Play
1. Select Difficulty Level: Choose the difficulty level by entering a number between 1 and 3:
    1 -> for Easy
    2 -> for Medium
    3 -> for Hard
2. Game Options:
    Choose 1 to start playing the game.
    Choose 2 to view the solution without playing.
    Choose 3 to exit the game.
3. Playing the Game:
    Enter the row and column numbers (1-9) and the number (1-9) you wish to place in the puzzle.
    If the placement is valid, the number will be added to the board. Otherwise, you’ll be prompted to try again.
    Hints:
    If you can’t solve the puzzle, enter -1 as the row, column, and number to view the complete solution.
