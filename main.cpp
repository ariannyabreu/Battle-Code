/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: implements a battle simulation where different types of heroes.  The simulation includes the
 * usage of items for equipped heroes, which enhance their abilities. It also tests copy and move semantics for the
 * EquippedHero class.
 * December 1, 2024
 * */

#include <iostream>
#include "PowerfulHero.h"
#include "AgileHero.h"
#include "EquippedHero.h"
#include "AbstractItem.h"
#include "AbstractHero.h"
#include "ShieldItem.h"
#include "SwordItem.h"
#include "ArmorItem.h"

AbstractHero* battle(AbstractHero& hero1, AbstractHero& hero2) {
    std::cout << "Battle starts between: " << std::endl;
    hero1.printInfo();
    hero2.printInfo();

    // Set maximum num of battles.
    const int maxRounds = 10;

    for (int i = 1; i <= maxRounds; ++i) {
        std::cout << "Round " << i << ":" << std::endl;

        // Hero 1 turn
        if (hero1.getStamina() > 10) {
            hero1.attack(hero2);
        } else if (hero1.getStamina() <= 15) {
            hero1.rest();
        } else {
            hero1.defend();
        }

        // Hero 2 turn
        if (hero2.getHealth() < 30) {
            hero2.defend();
        } else if (hero2.getStamina() > 10) {
            hero2.attack(hero1);
        } else {
            hero2.rest();
        }

        // Print round status.
        hero1.printInfo();
        hero2.printInfo();
        std::cout << "--------------------------------------------" << std::endl;

        // Check if a hero health is depleted.
        if (hero1.getHealth() <= 0) {
            std::cout << "Hero 2 wins!" << std::endl;
            return &hero2;
        }
        if (hero2.getHealth() <= 0) {
            std::cout << "Hero 1 wins!" << std::endl;
            return &hero1;
        }
    }

    // Determine winner if no hero is defeated after maxRound.
    std::cout << "Battle ended after " << maxRounds << " rounds!" << std::endl;
    if (hero1.getHealth() > hero2.getHealth()) {
        std::cout << "Hero 1 wins!" << std::endl;
        return &hero1;
    } else if (hero2.getHealth() > hero1.getHealth()) {
        std::cout << "Hero 2 wins!" << std::endl;
        return &hero2;
    } else {
        std::cout << "It's a tie!" << std::endl;
        return nullptr;
    }
}


int main() {
    // Non-equipped heroes.
    PowerfulHero hero1(100, 50, 20, 10);
    AgileHero hero2(80, 60, 15, 25);

    // Equipped heroes.
    EquippedHero equippedHero1(100, 50, 18, 12);
    EquippedHero equippedHero2(90, 70, 14, 20);

    // Equip items to equipped heroes. name and description.
    equippedHero1.addItem(std::make_unique<SwordItem>("Payan Sword", "A sharp blade that increases attack power."));
    equippedHero1.addItem(std::make_unique<ShieldItem>("God's Bone Shield", "A sturdy shield that boosts defense."));
    equippedHero1.addItem(std::make_unique<ArmorItem>("Steel Armor", "Provides strong defense with a stamina penalty."));

    equippedHero2.addItem(std::make_unique<SwordItem>("Espada", "A legendary sword that grants immense power."));
    equippedHero2.addItem(std::make_unique<ArmorItem>("Dragon Stone Plate", "Provides unmatched defense at a great stamina cost."));

    // Test copy constructor.
    std::cout << "\nTesting Copy Constructor:\n";
    // Creates a deep copy of equippedHero1:
    EquippedHero copiedHero(equippedHero1);
    copiedHero.printInfo();

    // Test copy assignment.
    std::cout << "\nTesting Copy Assignment Operator:\n";
    // Create a place holder:
    EquippedHero assignedHero(100, 50, 15, 10);
    // Assign equippedHero2 to assignedHero.
    assignedHero = equippedHero2;
    assignedHero.printInfo();

    // Battle 1: Non-equipped hero VS Equipped hero.
    std::cout << "\nBattle 1: Hero1 (PowerfulHero) vs EquippedHero1\n";
    battle(hero1, equippedHero1);

    // Reset health and stamina.
    hero1.setHealth(100);
    hero1.setStamina(50);
    equippedHero1.setHealth(100);
    equippedHero1.setStamina(50);

    // Battle 2: EquippedHero1 Vs EquippedHero2.
    std::cout << "\nBattle 2: EquippedHero1 vs EquippedHero2\n";
    battle(equippedHero1, equippedHero2);

    // Reset health and stamina.
    equippedHero1.setHealth(100);
    equippedHero1.setStamina(50);
    equippedHero2.setHealth(90);
    equippedHero2.setStamina(70);

    // Battle 3: Non-equipped heroes against each other
    std::cout << "\nBattle 3: Hero1 (PowerfulHero) vs Hero2 (AgileHero)\n";
    battle(hero1, hero2);

    // Test clone().
    std::cout << "\nTesting Item Cloning:\n";
    // Clone the first item in equippedHero1. Now EquippedHero1 has its own independent copy of the item.
    auto clonedSword = equippedHero1.getItems()[0]->clone();
    std::cout << "Cloned Item: " << clonedSword->getName() << " - " << clonedSword->getDescription() << std::endl;

    return 0;
}


