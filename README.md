# PF-Sudoku-Product
Sudoku Project for PF by BSCS26001 and BSCS26079
## How to play Soduko

### Objective 
Fill the **9×9 grid** with digits from **1 to 9** so that every cell is completed without breaking any placement rules.

### Rules 
Every digit placed on the board must be unique within three regions:
1. **Row Rule:** Each horizontal row (1–9) must contain the digits `1` through `9` with no duplicates.
2. **Column Rule:** Each vertical column (1–9) must contain the digits `1` through `9` with no duplicates.
3. **3×3 Box Rule:** Each of the nine **3×3 subgrids** (separated by lines on the board) must contain the digits `1` through `9` with no duplicates.

### Gameplay and controls 
* **Clues vs. Player Entries:** The game starts with pre-filled numbers (**clues**) loaded from `puzzle.txt`. Clues are locked and cannot be changed or erased.
* **Placing a Number:** Enter the **row** (`1–9`), **column** (`1–9`), and **value** (`1–9`). If the move breaks any of the three rules above, the game rejects it and tells you which rule was violated.
* **Erasing a Cell:** Enter `0` as the value (or use the erase command) on any cell you filled to clear it back to `.`.
* **Winning the Game:** Once all 81 cells are filled and obey all three rules, the puzzle is solved and the game displays your total move count and completion time.


## Work Division 

### Phase 1 
The development of Phase 1 is divided into 2 clear roles:
* **Architecture and skeleton setup by BSCS26079: Constructed the core `Sudoku` struct, defined all required function prototypes, and built the number-based main menu loop (with Phase 2 placeholders) as the foundation for the project.

* **Function Implementation by BSCS26001: Writing the implementation for each prototyped function based on the agreed-upon structure—handling puzzle loading, board display, move validation, clue protection, and the gameplay loop.

### Phase 2 
The roles for phase 2 are yet to be decided.


## Core architecture and logic 
### 1. Game State 
The entire game is stored in one `Sudoku` struct and passed by a pointer ('Sudoku* S')
* `board[9][9]`: The live 9×9 grid updated as the player places or erases numbers.
* `initial[9][9]`: A locked copy of the original puzzle clues so fixed numbers cannot be overwritten or erased.
* `completed`: Tracks whether the puzzle has been fully and correctly solved.
* `moveCount`: Counts the total valid moves made during the game.
* `startTime`: Stores the starting timestamp to calculate total time taken when the puzzle is solved.
 
### 2. Functions 
* `readInt()` — Safely reads number inputs from the menu/player without crashing on invalid text.
* `newGame()` — Loads `puzzle.txt`, verifies it has 9 valid rows of 9 characters with no broken rules, and initializes `board` and `initial`.
* `printBoard()` — Displays the 9×9 grid with row/column numbers, 3×3 box dividers, `.` for empty spaces, and a visual difference between clues and player numbers.
* `isValidMove()` — Checks that a move is within range (`1–9`) and does not repeat a number in the same row, column, or 3×3 box.
* `placeNumber()` — Checks that the cell is not a fixed clue, validates the move, places the number on `board`, and updates `moveCount`.
* `eraseNumber()` — Clears a player-entered number back to `.` (when entering `0`) while protecting original clues.
* `checkCompletion()` — Checks if the board is full and valid, then displays the total moves and elapsed time.
* `playGame()` — Runs the main gameplay loop (move, erase, check, quit) until the player wins or exits.

### The Main Menu 
1. **New game: Loads a fresh puzzle from puzzle.txt and starts a new session.
2. **PLay a move: Opens the gameplay loop where you can enter moves, erase player entries using 0, or check if the board is solved.
3. **Save Game: Reserved for Phase 2 (currently displays a placeholder message).
4. **Load Game: Reserved for Phase 2 (currently displays a placeholder message).
5. **Board Status: Reserved for Phase 2 (currently displays a placeholder message).
0. **Exit: Closes the program.