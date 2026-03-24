# Game Project Context

## Project Overview

- **Project Name:** Flying Beagle
- **Language:** C++ (C++23 minimum)
- **Current Status:** Early prototype/foundation phase

### Vision

The vision is a top-down 2D, slow-paced, strategic post-apocalyptic survival game.

The player controls a single character, who must survive a harsh world by scavenging for resources, crafting items, and managing their needs (hunger, thirst, fatigue).

What I want to focus on to make this experience special is a detailed, in-depth procedurally generated world with a strong emphasis on procedurally generated lore and emergent storytelling. Think Dwarf Fortress meets Don't Starve.

The procedural generation system should be able to generate not just terrain and items, but also complex backstories for the world, factions, and characters. The goal is to create a rich, dynamic world that feels alive and full of stories waiting to be discovered.

---

## Architecture & Design Decisions

### Core Systems
List the major systems you plan to build. Example structure:
- **Windowing System** - Library of choice: GLFW
- **Rendering System** - Library of choice: Vulkan for backend
- **Input System** - Support through GLFW
- **Physics/Collision** - Custom collision and physics system for 2D
- **Game Loop** - To be determined.
- **Entity/Object System** - To be determined.
- **Audio System** - To be determined.
- **State Management** - To be determined.

### Key Dependencies
- **Windowing/Input:** GLFW
- **Graphics:** Vulkan (emphasis on using vk-bootstrap for setup, and other official helper libraries as needed)
- **Audio:** To be determined.
- **Build System:** CMake

### Design Patterns & Conventions
- **ECS vs OOP vs Hybrid:** To be determined.
- **Game Loop Structure:** To be determined.
- **Memory Management:** Always prefer smart pointers.
- **Coordinate System:** Bottom-left origin, Y-up for world coordinates. Screen coordinates will be top-left origin, Y-down.

---

## Code Organization

### Directory Structure
```
project/
├── src/              # Implementation files (.cpp)
├── include/          # Header files (.h)
│   └── [projectname]/
├── assets/           # Game assets (sprites, audio, data)
│   ├── sprites/
│   ├── audio/
│   └── levels/
├── cmake/            # CMake modules and helpers
├── docs/             # Design documents, architecture notes
└── third_party/      # External libraries (if vendored)
```

### File Naming Conventions
- **Classes/Types:** `PascalCase` (e.g., `GameWorld.h`)
- **Functions/Methods:** `camelCase` (e.g., `updateGame()`)
- **Variables:** `camelCase` (e.g., `playerHealth`)
- **Constants:** `UPPER_SNAKE_CASE` (e.g., `MAX_PLAYERS`)
- **Files:** Match class name (e.g., `GameWorld.h`/`GameWorld.cpp`)

### Coding Style Preferences
- **Indentation:** 4 spaces.
- **Line Length:** 120 characters.
- **Const Correctness:** Yes / Prefer it where reasonable
- **Null Safety:** No null safety for now, but always prefer smart pointers.
- **Error Handling:** No exceptions. If it is something that cannot be handled gracefully, simply log and exit.

---

## Building & Running

### Prerequisites
- C++ compiler supporting C++23: Use MSVC.
- CMake: Version 3.15 or higher.

## Useful Context for AI Agents

### What Helps Me Help You Better
- Be specific about which system you're working on
- Reference existing code patterns when describing new features

## Notes for Future Self
[Any important gotchas, architectural decisions that were debated, or things that surprised you during setup]
