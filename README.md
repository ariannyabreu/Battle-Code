# BattleCode: Turn-Based Battle Game

## Project Overview
**BattleCode** is a turn-based battle game implemented in C++. Players control Heroes with unique traits (health, stamina, strength, agility) and abilities, engaging in strategic combat. The project demonstrates advanced C++ concepts, including inheritance, polymorphism, dynamic memory management, and move/copy semantics. Heroes can also equip items to enhance their abilities, adding depth to gameplay.

---

## Features
1. **Hero Classes**:
   - Abstract base class `AbstractHero` with pure virtual methods for `attack()`, `defend()`, and `rest()`.
   - Derived classes like `PowerfulHero` and `AgileHero` with unique combat behaviors.
2. **Item System**:
   - Abstract base class `AbstractItem` for items like `SwordItem`, `ArmorItem`, and `ShieldItem`.
   - Items modify Hero traits (attack, defense, health, stamina) during combat.
3. **Battle Simulation**:
   - A `battle()` function simulates 10-round battles between Heroes, with detailed logs for each action.
4. **Dynamic Memory Management**:
   - Use of `std::vector` and `std::unique_ptr` for managing equipped items.
   - Proper implementation of move and copy semantics for the `EquippedHero` class.
5. **Testing**:
   - Comprehensive testing of Hero interactions and item effects.

---

## How to Run the Program
1. **Prerequisites**:
   - Ensure you have a C++ compiler (e.g., GCC, Clang) or an IDE like CLion installed.
2. **Compilation**:
   - Open the project in CL
  
## Files Included
- `main.cpp`: Contains the `battle()` function and main game loop.
- `AbstractHero.h/cpp`, `PowerfulHero.h/cpp`, `AgileHero.h/cpp`: Hero classes.
- `AbstractItem.h/cpp`, `SwordItem.h/cpp`, `ArmorItem.h/cpp`, `ShieldItem.h/cpp`: Item classes.
- `EquippedHero.h/cpp`: Manages equipped items.
- `README.md`: This file.

---

## Author
- **Name**: Arianny Abreu Gonzalez
- Project 2 - BattleCode
