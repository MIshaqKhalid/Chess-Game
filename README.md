<div align="center">

# ♟️ Object-Oriented Chess Game

### A Professional Console-Based Chess Engine Built in C++

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%20%7C%2014-blue?style=for-the-badge&logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/OOP-Fully%20Implemented-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" />
</p>

*Developed by **Muhammad Ishaq Khalid** & **Muhammed Hamza***

<p align="center">
  A modular and extensible Chess Game developed using core Object-Oriented Programming principles in C++.
</p>

</div>

---

# 📌 Introduction

This project is a **console-based Chess Game** implemented entirely in **C++** with a strong emphasis on:

- Clean software architecture
- Object-Oriented Programming
- Modular code organization
- Real-time game logic validation
- Professional terminal-based UI

The system accurately simulates standard chess gameplay while demonstrating practical implementation of advanced programming concepts including:

- Encapsulation
- Inheritance
- Polymorphism
- Abstraction

The game includes a visually enhanced command-line interface using **Unicode chess symbols** and **ANSI color styling** for a modern terminal experience.

---

## ✨ Features

- ♟️ **Complete Chess Logic** — All standard piece movements with proper validation
- 🎨 **Beautiful Console UI** — Unicode chess symbols + ANSI colors for visual appeal
- ⚡ **Real-time Validation** — Instant feedback on invalid moves
- 👑 **Check & Checkmate Detection** — Full game state awareness
- 🔄 **Turn Management** — Automatic White/Black alternation
- 🖥️ **Cross-Platform** — Works on Windows, Linux, and macOS
- 📦 **Zero Dependencies** — Pure C++ standard library only
- 🎓 **Educational Codebase** — Clean OOP design for learning purposes

---

# 📂 Project Structure

```bash
📦 OOP-Chess-Game
 ┣ 📜 Main.cpp
 ┣ 📜 chess.cpp
 ┣ 📜 chess.h
 ┣ 📜 report.txt
 ┗ 📜 README.md
```
## 📸 Screenshots

### Loading Screen
```
 ██████╗██╗  ██╗███████╗███████╗███████╗
██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝
██║     ███████║█████╗  ███████╗███████╗
██║     ██╔══██║██╔══╝  ╚════██║╚════██║
╚██████╗██║  ██║███████╗███████║███████║
 ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝

               ♔ ♕ ♖ ♗ ♘ ♙
               ♚ ♛ ♜ ♝ ♞

=====================================================
              OOP CHESS GAME PROJECT
=====================================================

Loading Game ■ ■ ■ ■ ■ ■
```

### Game Board
```
            ♔ CHESS BOARD ♚

      a     b     c     d     e     f     g     h
    ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
 8  ║  ♜  ║  ♞  ║  ♝  ║  ♛  ║  ♚  ║  ♝  ║  ♞  ║  ♜  ║  8
    ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
 7  ║  ♟  ║  ♟  ║  ♟  ║  ♟  ║  ♟  ║  ♟  ║  ♟  ║  ♟  ║  7
    ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
 ...
 1  ║  ♖  ║  ♘  ║  ♗  ║  ♕  ║  ♔  ║  ♗  ║  ♘  ║  ♖  ║  1
    ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
      a     b     c     d     e     f     g     h
```

---

## 🚀 Getting Started

### Prerequisites

- C++ compiler supporting **C++11** or later:
  - **Windows**: [MinGW-w64](https://www.mingw-w64.org/) or Visual Studio
  - **Linux**: GCC (`sudo apt install g++`)
  - **macOS**: Xcode Command Line Tools (`xcode-select --install`)
- Terminal with **Unicode** and **ANSI color** support (most modern terminals)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/oop-chess-game.git
   cd oop-chess-game
   ```

2. **Compile the source code**

   **Using g++ (All platforms):**
   ```bash
   g++ -o chess Main.cpp chess.cpp -std=c++11 -Wall
   ```

### Running the Game

```bash
# Windows
./chess.exe

# Linux / macOS
./chess
```

---

## 🎮 How to Play

### Menu Navigation
```
╔══════════════════════════════════════╗
║            ♔ CHESS MENU ♚           ║
╠══════════════════════════════════════╣
║                                      ║
║         [1] Start Game               ║
║         [2] Instructions             ║
║         [3] About Project            ║
║         [4] Exit                     ║
║                                      ║
╚══════════════════════════════════════╝
```

### Making Moves
Enter moves in **algebraic notation** (e.g., `e2 e4`):

```
Move: e2 e4
```

- **First input**: Source square (e.g., `e2`)
- **Second input**: Destination square (e.g., `e4`)
- **Type `quit`** during gameplay to return to menu

### Chess Notation Guide
| Symbol | Meaning |
|--------|---------|
| `a-h` | Files (columns) from left to right |
| `1-8` | Ranks (rows) from bottom to top |
| `e2 e4` | Move pawn from e2 to e4 |

### Color Legend
| Color | Usage |
|-------|-------|
| ⚪ White | White pieces & prompts |
| 🔴 Red | Black pieces & errors |
| 🔵 Blue | Board borders |
| 🟡 Yellow | Rank/file labels |
| 🟢 Green | Success messages |
| 🩵 Cyan | Headers & titles |

---

## 🏗️ Architecture

### Class Hierarchy

```
                    ┌─────────────┐
                    │   Piece     │◄────── Abstract Base
                    │  (Abstract) │
                    └──────┬──────┘
                           │
        ┌─────────┬────────┼────────┬────────┬────────┐
        │         │        │        │        │        │
   ┌────┴────┐ ┌──┴───┐ ┌──┴───┐ ┌──┴───┐ ┌──┴───┐ ┌──┴───┐
   │  Pawn   │ │ Rook │ │Knight│ │Bishop│ │ Queen│ │ King │
   └─────────┘ └──────┘ └──────┘ └──────┘ └──────┘ └──────┘
```

### System Layers

```
┌─────────────────────────────────────┐
│      🎨 Presentation Layer          │
│   Board Display • Menu • Styling    │
├─────────────────────────────────────┤
│       🧠 Game Logic Layer           │
│  Move Validation • Check/Checkmate  │
├─────────────────────────────────────┤
│        ♟️ Entity Layer              │
│    Pieces • Position • Board State  │
├─────────────────────────────────────┤
│        🛠️ Utility Layer             │
│   Console Ops • Cross-Platform      │
└─────────────────────────────────────┘
```

# 🧪 Implemented Functionalities

- ✅ Board Initialization
- ✅ Move Validation
- ✅ Path Clearance Checking
- ✅ Piece Capturing
- ✅ Turn Management
- ✅ Check Detection
- ✅ Checkmate Detection
- ✅ Self-Check Prevention
- ✅ Console Board Rendering
- ✅ User Input Parsing

---

# 📊 Performance Overview

| Operation | Complexity |
|---|---|
| Move Validation | O(1) – O(n) |
| Board Rendering | O(64) |
| Check Detection | O(64 × n) |
| Checkmate Detection | O(16 × 64 × checks) |

---

# 📚 Educational Purpose

This project was developed as an academic **Object-Oriented Programming Final Project** to demonstrate practical application of:

- Software Engineering Principles
- OOP Architecture
- Game Development Logic
- Data Structures
- Console UI Development

---

# 🔮 Future Enhancements

### 🤖 AI Opponent
- [ ] Minimax algorithm with alpha-beta pruning
- [ ] Multiple difficulty levels
- [ ] Opening book integration

### 🖥️ Graphical Interface
- [ ] SFML/SDL2 based GUI
- [ ] Drag-and-drop piece movement
- [ ] Sound effects & animations

### 🌐 Multiplayer
- [ ] Local network (LAN) play
- [ ] Online matchmaking
- [ ] Spectator mode

### 💾 Game State
- [ ] Save/load games
- [ ] Move history with algebraic notation
- [ ] Undo/redo functionality
- [ ] PGN export

### ⏱️ Advanced Features
- [ ] Chess clock / timer
- [ ] Special moves (castling, en passant, promotion)
- [ ] Endgame tablebases
- [ ] Position analysis engine
---

# 👨‍💻 Author

<div align="center">

## Muhammad Ishaq Khalid & Muhammad Hamza

Computer Science Students  

</div>

---

# 🤝 Contributing

Contributions, suggestions, and improvements are welcome.Please follow these steps:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

---

## 🙏 Acknowledgements

- **FIDE** — For the official Laws of Chess
- **Unicode Consortium** — For chess symbols (U+2654–U+265F)
- **C++ Community** — For best practices and design patterns
- **Open Source Chess Projects** — For inspiration and reference

---

<div align="center">

**⭐ Star this repo if you found it helpful!**

Made with ❤️ and C++

♔ ♕ ♖ ♗ ♘ ♙ ♚ ♛ ♜ ♝ ♞ ♟

</div>
