cmake_minimum_required(VERSION 3.28)
project(Project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project2 main.cpp
        AbstractHero.cpp
        AbstractHero.h
        PowerfulHero.cpp
        PowerfulHero.h
        AgileHero.cpp
        AgileHero.h
        AbstractItem.cpp
        AbstractItem.h
        SwordItem.cpp
        SwordItem.h
        ArmorItem.cpp
        ArmorItem.h
        ShieldItem.cpp
        ShieldItem.h
        EquippedHero.cpp
        EquippedHero.h)
