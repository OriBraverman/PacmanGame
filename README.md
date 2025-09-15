# Pacman Game

🎮 **A feature-rich C++ implementation of the classic Pacman arcade game**

This project is a comprehensive, console-based recreation of the iconic Pacman game, built entirely in C++ with advanced artificial intelligence, game recording capabilities, and multiple difficulty levels. Perfect for computer science students, game development enthusiasts, and anyone interested in learning about AI algorithms and object-oriented programming.

## What This Project Does

Transform your console into a fully functional Pacman arcade experience featuring:

- **🤖 Intelligent AI Ghosts**: Three distinct difficulty levels with sophisticated pathfinding algorithms
- **💾 Complete Game Recording**: Save and replay entire gameplay sessions for analysis and demonstration
- **🎯 Multiple Game Modes**: Interactive play, automated replay, and silent analysis modes
- **🎨 Visual Console Interface**: Colorful ASCII-based graphics with smooth animations
- **📚 Educational Codebase**: Well-documented, object-oriented design showcasing advanced programming concepts

## Who This Project Is For

- **Computer Science Students** learning object-oriented programming, AI algorithms, and software design patterns
- **Game Development Enthusiasts** interested in classic arcade game mechanics and AI implementation
- **Educators** looking for a comprehensive example of C++ programming with practical applications
- **Developers** studying pathfinding algorithms, state machines, and game architecture patterns
- **Anyone** who enjoys classic Pacman and wants to see how it works under the hood

## 🌟 Key Features

### Game Modes
- **🎮 Normal Play**: Classic interactive Pacman gameplay
- **💾 Save Mode**: Record your gameplay while playing for later analysis
- **▶️ Load Mode**: Replay previously saved games with full visual output
- **🔍 Silent Mode**: Run games without display for performance analysis

### Artificial Intelligence
- **🧠 Best Strategy**: Advanced AI using Breadth-First Search for optimal pathfinding
- **⚡ Good Strategy**: Balanced AI combining smart decisions with timing
- **🎯 Novice Strategy**: Beginner-friendly AI with predictable patterns

### Technical Features
- **🎨 Color Support**: Optional colorized console output for enhanced visuals
- **📊 Multiple Boards**: Pre-designed levels (A, B, C) with increasing difficulty
- **🏗️ Modular Architecture**: Clean object-oriented design with extensible components
- **💻 Windows Console**: Optimized for Windows console applications with full keyboard support

## 🚀 Quick Start

### Prerequisites
- Windows Operating System (uses Windows Console API)
- Microsoft Visual Studio 2017 or later
- Windows SDK for console functions

### Build & Run
1. Open `Pacman ex3.sln` in Visual Studio
2. Build the solution (Ctrl+Shift+B)
3. Run the executable:
   ```bash
   # Start normal game
   PacmanGame.exe
   
   # Record gameplay
   PacmanGame.exe -save
   
   # Replay saved game
   PacmanGame.exe -load
   ```

### Controls
- **W/A/S/D**: Move Up/Left/Down/Right
- **X**: Move Down (alternative)
- **S**: Stay in place
- **ESC**: Pause/Resume game

## 🏗️ Architecture & Design Patterns

This project serves as an excellent example of object-oriented programming and design patterns in action. Here's how the code is organized:

### Core Components

1. **🎮 PacmanGame**: Central game controller managing game flow, state transitions, and coordination between all components
2. **🏗️ Board**: Game field representation with collision detection, boundary checking, and spatial management
3. **👾 Creature Hierarchy**: Polymorphic base class system for all moving entities (Pacman, Ghosts, Fruits)
4. **🤖 Strategy Pattern**: Pluggable AI algorithms allowing easy swapping of ghost behavior strategies
5. **📋 Menu System**: User interface management for game configuration and navigation

### Design Patterns Demonstrated

- **🔄 Strategy Pattern**: Interchangeable AI behaviors (Best, Good, Novice strategies)
- **🏛️ Inheritance & Polymorphism**: Creature base class extended by Pacman, Ghost, and Fruit
- **📋 Template Method**: Structured game loop with customizable behavior hooks  
- **🔄 State Pattern**: Different operational modes (Normal, Save, Load, Silent)
- **🏭 Factory Pattern**: Dynamic creation of different game entities

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

## 🎮 Game Features & Mechanics

### 🤖 AI Ghost Strategies

Each ghost difficulty level demonstrates different algorithmic approaches:

1. **🏆 Best Strategy**: 
   - Implements Breadth-First Search (BFS) for optimal pathfinding
   - Guarantees shortest path to player
   - Perfect for demonstrating graph algorithms

2. **⚖️ Good Strategy**: 
   - Combines BFS with timing-based decisions
   - Balances challenge with playability
   - Shows hybrid algorithmic approaches

3. **🎯 Novice Strategy**: 
   - Simple rule-based movement patterns
   - Predictable behavior for beginners
   - Demonstrates basic AI state machines

### 🎲 Gameplay Mechanics

- **🎯 Objective**: Collect all breadcrumbs (*) while avoiding ghosts ($)
- **🍎 Bonus Items**: Grab fruits (5-9) for extra points
- **❤️ Lives System**: Start with 3 lives; lose one when caught by ghosts
- **🏆 Progression**: Complete levels A → B → C with increasing difficulty
- **⏸️ Pause Feature**: ESC key pauses/resumes gameplay

### 🎮 Game Modes

- **🎯 Normal Mode**: Standard interactive gameplay experience
- **💾 Save Mode**: Play while recording all moves for later analysis
- **▶️ Load Mode**: Replay previously saved games with full visual output
- **🔇 Load Silent Mode**: Run replays without display for performance testing

## 📁 Project Structure & Files

### 🔧 Core Source Files

**🎮 Game Engine:**
- `main.cpp` - Application entry point and command-line argument processing
- `PacmanGame.cpp/h` - Central game controller and logic coordinator  
- `Board.cpp/h` - Game field management with collision detection

**👾 Game Entities:**
- `Creature.cpp/h` - Polymorphic base class for all moving game objects
- `Pacman.cpp/h` - Player character with movement and interaction logic
- `Ghost.cpp/h` - AI-controlled enemy characters
- `Fruit.cpp/h` - Collectible bonus items with spawn mechanics

**🤖 AI Strategy System:**
- `Strategy.h` - Strategy pattern interface for pluggable AI behaviors
- `Best.cpp/h` - Advanced AI using Breadth-First Search algorithms
- `Good.cpp/h` - Balanced AI with timing-based decision making
- `Novice.cpp/h` - Simple rule-based AI for beginners
- `BFS.cpp/h` - Graph search algorithm implementation

**🛠️ Utilities & Infrastructure:**
- `Position.cpp/h` - 2D coordinate system and spatial calculations
- `Utilities.cpp/h` - Console manipulation and system utilities
- `Menu.cpp/h` - User interface and navigation systems
- `Enum.h` - Game constants, enumerations, and configuration

### 🎮 Game Data Files

**🗺️ Level Layouts:**
- `Pacman_A.screen` - Beginner level layout and configuration
- `Pacman_B.screen` - Intermediate level with increased complexity  
- `Pacman_C.screen` - Advanced level with challenging maze design

**📹 Gameplay Recording:**
- `Pacman_*.steps` - Complete movement history for replay analysis
- `Pacman_*.result` - Game outcome data and performance metrics

### 📚 Documentation

- `file_format.txt` - Technical specification for save/load file formats
- `README.md` - Comprehensive project documentation and user guide

## 🛠️ Build Instructions

### 📋 Prerequisites

- **Windows 10/11** (uses Windows Console API for display and input)
- **Microsoft Visual Studio 2017** or later (Community edition works perfectly)
- **Windows SDK** for console manipulation functions

### 🔨 Building the Project

**Option 1: Visual Studio GUI**
1. Open `Pacman ex3.sln` in Visual Studio
2. Select your preferred configuration (Debug/Release)
3. Build → Build Solution (Ctrl+Shift+B)
4. Run with F5 or Ctrl+F5

**Option 2: Command Line with MSBuild**
```bash
# For Release build
msbuild "Pacman ex3.sln" /p:Configuration=Release

# For Debug build  
msbuild "Pacman ex3.sln" /p:Configuration=Debug
```

### 📦 Dependencies

This project uses only standard Windows libraries:
- `windows.h` - Console API for colors and cursor control
- `conio.h` - Real-time keyboard input handling
- Standard C++ STL libraries (iostream, fstream, vector, etc.)

## 🎯 How to Run & Play

### 🚀 Launch Options

```bash
# 🎮 Standard interactive gameplay
PacmanGame.exe

# 💾 Record your gameplay for analysis
PacmanGame.exe -save

# 🔇 Record gameplay without visual output (performance mode)
PacmanGame.exe -save -silent

# ▶️ Replay a previously saved game
PacmanGame.exe -load

# 📊 Replay in silent mode for data analysis
PacmanGame.exe -load -silent
```

### 🎮 Getting Started

1. **🚀 Launch**: Run the executable to start
2. **🎨 Display Mode**: Choose your visual experience
   - `(1)` Start with colorful display
   - `(2)` Start with standard console colors
   - `(8)` View detailed game instructions
   - `(9)` Exit application

3. **🤖 AI Difficulty**: Select ghost intelligence level
   - `(a)` **BEST** - Master level AI with optimal pathfinding
   - `(b)` **GOOD** - Balanced AI for enjoyable challenge  
   - `(c)` **NOVICE** - Beginner-friendly predictable AI

4. **🗺️ Level Selection**: Choose your challenge
   - Play individual levels (A, B, or C)
   - Play all levels in sequence for full experience

### 🎯 How to Win

- **🍞 Primary Mission**: Collect every breadcrumb (*) on the game board
- **👻 Avoid Danger**: Stay away from ghosts ($) - they cost you a life!
- **🍎 Bonus Points**: Grab fruits (numbers 5-9) for extra score
- **❤️ Lives Management**: You start with 3 lives; use them wisely
- **🏆 Level Progression**: Complete A → B → C for full game experience

## 💾 Advanced Save/Load System

### 🎯 Why This Feature Matters

The save/load system is perfect for:
- **📊 Game Analysis**: Study optimal strategies and AI behavior patterns
- **🎓 Educational Use**: Demonstrate AI algorithms and game mechanics  
- **🐛 Debugging**: Reproduce specific game scenarios for testing
- **🏆 Performance Testing**: Benchmark different AI strategies

### 📁 File Format Specifications

**🎬 Steps Files** (`Pacman_*.steps`):
- Precise timestamped recording of every game action
- Complete movement history for all creatures (Pacman, ghosts, fruits)
- Fruit spawn/despawn events with positions and types
- Frame-perfect gameplay reproduction capability

**📈 Result Files** (`Pacman_*.result`):  
- Game outcome data (victory/defeat conditions)
- Timing information for critical game events
- Statistical data for performance analysis

### 🔄 Practical Examples

**📹 Recording Your Gameplay:**
```bash
# Play and record simultaneously
PacmanGame.exe -save
# → Generates: Pacman_A.steps, Pacman_A.result, etc.
```

**▶️ Analyzing Recorded Games:**
```bash
# Watch your previous gameplay
PacmanGame.exe -load
# → Replays using saved .steps and .result files

# Batch analysis mode (no visual output)
PacmanGame.exe -load -silent
# → Perfect for automated testing and data collection
```

## ⚙️ Technical Implementation Details

### 🚀 Performance & Optimization

- **⏱️ Real-time Engine**: 100ms game loop for smooth 10 FPS gameplay
- **🎯 Efficient Timing**: Ghosts move every 2nd cycle, fruits every 10th cycle
- **💾 Memory Optimized**: Compact 81x25 character array board representation
- **🔄 Event-Driven**: Responsive input handling with Windows Console API

### 🧠 AI Algorithm Deep Dive

**🏆 Best Strategy (Breadth-First Search)**
- **Algorithm**: Complete BFS implementation for graph traversal
- **Guarantee**: Always finds the shortest path to player
- **Use Case**: Demonstrates optimal pathfinding and graph theory
- **Complexity**: O(V + E) time, higher CPU usage but perfect play

**⚖️ Good Strategy (Hybrid Approach)**  
- **Algorithm**: BFS combined with timing-based heuristics
- **Balance**: Optimal pathfinding with strategic delays
- **Use Case**: Shows practical AI balancing challenge vs. playability
- **Complexity**: Adaptive behavior based on game state

**🎯 Novice Strategy (Rule-Based System)**
- **Algorithm**: Simple state machine with basic decision trees
- **Behavior**: Predictable movement patterns for learning
- **Use Case**: Perfect for beginners and AI concept demonstration
- **Complexity**: O(1) decision making, minimal computational overhead

### 🏗️ Software Engineering Highlights

This project showcases professional development practices:
- **🔄 SOLID Principles**: Single responsibility, dependency injection
- **🧪 Design Patterns**: Strategy, Template Method, State, Factory patterns
- **🏛️ Clean Architecture**: Separation of concerns, modular design
- **📊 Performance Monitoring**: Built-in timing and analysis tools

## 👥 Contributors & Development

**🎓 Academic Project by:**
- **Ori Braverman** - Lead Developer
- **Shachar Levy** - Co-Developer

### 📈 Project Evolution

This represents the **third iteration** of Pacman game development, showcasing:

✅ **Advanced Features Implemented:**
- Complete object-oriented architecture with design patterns
- Sophisticated AI strategies with multiple difficulty levels  
- Comprehensive save/load system for gameplay analysis
- Robust error handling and edge case management
- Extensible codebase architecture for future enhancements
- Professional-grade documentation and code organization

### 🤝 Educational Value

Perfect for students and educators studying:
- **Object-Oriented Programming** in C++
- **Algorithm Implementation** (BFS, pathfinding)
- **Design Patterns** in real applications
- **Game Development** fundamentals
- **Software Architecture** principles

## 📜 License & Usage

### 🎓 Academic Context
This project was developed as part of a **computer science curriculum** to demonstrate:
- Advanced programming concepts and implementation
- Algorithm design and optimization techniques  
- Software engineering best practices

### ⚖️ Usage Guidelines
- **Educational Use**: Freely study the code and algorithms
- **Academic Integrity**: Please respect academic honesty policies
- **Attribution**: Credit the original authors when referencing this work
- **Learning**: Use as inspiration for your own implementations

---

## 📚 Additional Resources

**📖 For Technical Deep-Dive:**
- `file_format.txt` - Detailed save/load file specifications
- Source code comments - Inline documentation and explanations
- Class hierarchy - Study the object-oriented design patterns

**🔗 Related Learning Topics:**
- Graph algorithms and pathfinding
- Object-oriented design patterns  
- Game loop architecture
- Console application development

*Happy coding and game development! 🎮*