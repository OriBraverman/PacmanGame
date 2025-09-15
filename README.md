# Pacman Game

A comprehensive C++ implementation of the classic Pacman game with advanced AI strategies, save/load functionality, and multi-level support.

## Project Overview

This is a console-based Pacman game developed in C++ that features multiple game boards, intelligent ghost AI with different difficulty levels, and a complete game recording/playback system. The game supports both interactive play and automated replay of saved games.

### Key Features

- **Multiple Game Modes**: Normal play, Save gameplay, Load and replay saved games
- **AI-Driven Ghost Strategies**: Three difficulty levels with different AI algorithms
- **Multiple Game Boards**: Pre-designed levels with varying difficulty
- **Color Support**: Optional colorized console output
- **Game Recording**: Complete save/load system for gameplay analysis
- **Cross-platform Design**: Built for Windows console applications

## Architecture & Design Patterns

### Core Components

1. **PacmanGame**: Main game controller managing game flow, board initialization, and game states
2. **Board**: Game field representation with collision detection and position management
3. **Creature Hierarchy**: Base class for all moving entities (Pacman, Ghosts, Fruits)
4. **Strategy Pattern**: Pluggable AI algorithms for ghost behavior
5. **Menu System**: User interface for game configuration and navigation

### Design Patterns Used

- **Strategy Pattern**: Different AI behaviors for ghosts (Best, Good, Novice)
- **Inheritance**: Creature base class extended by Pacman, Ghost, and Fruit
- **Template Method**: Game loop structure with customizable behaviors
- **State Pattern**: Different game modes (Normal, Save, Load, Load Silent)

### Class Structure

```
Creature (Base Class)
├── Pacman (Player character)
├── Ghost (AI-controlled enemies)
└── Fruit (Collectible items)

Strategy (Interface)
├── Best (Advanced AI using BFS)
├── Good (Intermediate AI with timing)
└── Novice (Basic AI behavior)

PacmanGame (Main Controller)
├── Board (Game field)
├── Menu (User interface)
└── Position (Coordinate system)
```

## Game Features

### Ghost AI Strategies

1. **Best Strategy**: Uses Breadth-First Search (BFS) algorithm to find optimal paths to Pacman
2. **Good Strategy**: Combines pathfinding with timing-based decisions
3. **Novice Strategy**: Simple movement patterns with basic decision-making

### Game Modes

- **Normal Mode**: Standard interactive gameplay
- **Save Mode**: Play while recording all moves to files
- **Load Mode**: Replay previously saved games with visual output
- **Load Silent Mode**: Replay games without visual output for analysis

### Controls

- **A** or **a**: Move LEFT
- **D** or **d**: Move RIGHT  
- **W** or **w**: Move UP
- **X** or **x**: Move DOWN
- **S** or **s**: STAY in place
- **ESC**: Pause game (press ESC again to resume)

## File Structure

### Source Files

**Core Game Logic:**
- `main.cpp` - Entry point and command-line argument processing
- `PacmanGame.cpp/h` - Main game controller and logic
- `Board.cpp/h` - Game board management and collision detection

**Game Entities:**
- `Creature.cpp/h` - Base class for all moving entities
- `Pacman.cpp/h` - Player character implementation
- `Ghost.cpp/h` - Enemy character implementation
- `Fruit.cpp/h` - Collectible fruit items

**AI System:**
- `Strategy.h` - Strategy pattern interface
- `Best.cpp/h` - Advanced AI strategy using BFS
- `Good.cpp/h` - Intermediate AI strategy
- `Novice.cpp/h` - Basic AI strategy
- `BFS.cpp/h` - Breadth-First Search algorithm implementation

**Utilities:**
- `Position.cpp/h` - 2D coordinate system
- `Utilities.cpp/h` - Console manipulation and helper functions
- `Menu.cpp/h` - User interface menus
- `Enum.h` - Game constants and enumerations

### Game Data Files

**Board Files:**
- `Pacman_A.screen` - Level A layout
- `Pacman_B.screen` - Level B layout  
- `Pacman_C.screen` - Level C layout

**Recorded Gameplay:**
- `Pacman_*.steps` - Movement recordings for replay
- `Pacman_*.result` - Game outcome data

### Documentation

- `file_format.txt` - Detailed specification of save file formats
- `README.md` - This comprehensive project documentation

## Build Instructions

### Prerequisites

- **Windows Operating System** (uses Windows Console API)
- **Microsoft Visual Studio** (2017 or later recommended)
- **Windows SDK** for console manipulation functions

### Building the Project

1. **Using Visual Studio:**
   ```
   Open "Pacman ex3.sln" in Visual Studio
   Build → Build Solution (Ctrl+Shift+B)
   ```

2. **Using MSBuild (Command Line):**
   ```bash
   msbuild "Pacman ex3.sln" /p:Configuration=Release
   ```

### Dependencies

The project uses Windows-specific libraries:
- `windows.h` - Console manipulation
- `conio.h` - Keyboard input handling
- Standard C++ libraries (iostream, fstream, vector, etc.)

## How to Run

### Command Line Usage

```bash
# Normal interactive game
PacmanGame.exe

# Save gameplay while playing
PacmanGame.exe -save

# Save gameplay in silent mode (no visual output)
PacmanGame.exe -save -silent

# Load and replay saved game
PacmanGame.exe -load

# Load and replay in silent mode
PacmanGame.exe -load -silent
```

### Game Setup

1. **Start the game**: Run the executable
2. **Choose mode**: Select from the main menu
   - (1) Start with color support
   - (2) Start without color support
   - (8) View instructions
   - (9) Exit
3. **Select difficulty**: Choose AI strategy level
   - (a) BEST - Advanced AI
   - (b) GOOD - Intermediate AI  
   - (c) NOVICE - Basic AI
4. **Choose board**: Select from available levels or play all sequentially

### Gameplay Objectives

- **Primary Goal**: Eat all breadcrumbs (*) on the board
- **Avoid**: Getting caught by ghosts ($)
- **Bonus**: Collect fruits (5-9) for extra points
- **Lives**: Start with 3 lives, lose one when caught by ghost
- **Winning**: Clear all breadcrumbs to advance to next level

## Save/Load System

### File Formats

The game uses a sophisticated recording system documented in `file_format.txt`:

**Steps Files** (`*.steps`):
- Record every game action with timestamps
- Track creature movements and direction changes
- Support fruit appearance/disappearance events
- Enable precise gameplay reproduction

**Result Files** (`*.result`):
- Record game outcomes (win/lose conditions)
- Track timestamps of significant events
- Enable game analysis and statistics

### Usage Examples

**Recording a game session:**
```bash
PacmanGame.exe -save
# Creates Pacman_A.steps and Pacman_A.result files
```

**Replaying recorded session:**
```bash
PacmanGame.exe -load
# Replays using existing .steps and .result files
```

## Technical Details

### Performance Characteristics

- **Real-time Gameplay**: 100ms game loop cycle
- **Ghost Movement**: Every 2nd game cycle
- **Fruit Logic**: Every 10th game cycle
- **Memory Usage**: Efficient board representation (81x25 character array)

### AI Algorithm Details

**Best Strategy (BFS):**
- Implements breadth-first search for optimal pathfinding
- Guarantees shortest path to player
- Higher computational complexity but optimal play

**Good Strategy:**
- Combines BFS with timing-based decisions
- Balances performance and challenge
- Adapts behavior based on game progression

**Novice Strategy:**
- Simple rule-based movement
- Predictable patterns for beginner-friendly gameplay
- Minimal computational overhead

## Contributing

This project was developed by:
- **Ori Braverman**
- **Shachar Levy**

### Development Notes

This represents the third iteration of the Pacman game development, featuring:
- Complete object-oriented design
- Robust save/load functionality  
- Multiple AI difficulty levels
- Comprehensive error handling
- Extensible architecture for future enhancements

## License

This project is an academic implementation developed as part of a computer science curriculum. Please respect academic integrity guidelines when using this code.

---

*For detailed technical specifications of file formats and internal APIs, please refer to `file_format.txt` and the source code documentation.*