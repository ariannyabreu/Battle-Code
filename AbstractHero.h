/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Serves as a base class for all types of heroes in the game.
 * December 1, 2024
 * */

#ifndef PROJECT2_ABSTRACTHERO_H
#define PROJECT2_ABSTRACTHERO_H

class AbstractHero {
public:
    AbstractHero(int health, int stamina, int strength, int agility);

    virtual ~AbstractHero();

    // Setters and Getters:
    void setHealth(int newHealth);
    void setStamina(int stamina);

    int getHealth() const;
    int getStamina() const;

    // Adder an Remover:
    void addHealth(int health);
    void removeHealth(int health);

    // Pure virtual methods:
    virtual void attack(AbstractHero& target) = 0;
    virtual void defend() = 0;
    virtual void rest() = 0;
    virtual void printInfo() const = 0;
    virtual bool compareHealth(const AbstractHero& other) const = 0;


protected:
    int m_health;
    int m_stamina;
    int m_strength;
    int m_agility;
};


#endif //PROJECT2_ABSTRACTHERO_H
