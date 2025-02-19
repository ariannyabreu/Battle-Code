/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Concrete implementation of the AbstractItem class. Represents a sword that modifies a hero's
 * stats by increasing attack power while slightly reducing stamina.
 * December 1, 2024
 * */

#ifndef PROJECT2_SWORDITEM_H
#define PROJECT2_SWORDITEM_H

#include "AbstractItem.h"

class SwordItem : public AbstractItem {
public:
    SwordItem(const std::string& name, const std::string& description);

    int getAttackModifier() const override;
    int getDefenseModifier() const override;
    int getHealthModifier() const override;
    int getStaminaModifier() const override;

    std::unique_ptr<AbstractItem> clone() const override;

};


#endif //PROJECT2_SWORDITEM_H
