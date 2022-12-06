#include "Pokemon.h"
#pragma once

    Pokemon::Pokemon(int _pokeDexNumber, std::string _name, std::string _type1, std::string type2, int _total, 
        int _hp, int _attack, int _defense, int _spAttack, int _spDef, int _speed, int _gen, bool _legendary)
    {
        pokeDexNumber = _pokeDexNumber;
        pokeName = _name;
        pokeType1 = _type1;
        pokeType2 = type2;
        total = _total;
        hp = _hp;
        attack = _attack;
        defense = _defense;
        spAttack = _spAttack;
        spDef = _spDef;
        speed = _speed;
        pokeGen = _gen;
        legendary = _legendary;
        pokemonMoves = {Move(), Move(), Move(), Move()};
    }

    int Pokemon::getPokeDexNumber()
    {
        return pokeDexNumber;
    }
    std::string Pokemon::getName()
    {
        return pokeName;
    }
    std::string Pokemon::getType1()
    {
        return pokeType1;
    }
    std::string Pokemon::getType2()
    {
        return pokeType2;
    }
    int Pokemon::getTotal()
    {
        return total;
    }
    int Pokemon::getHP()
    {
        return hp;
    }
    int Pokemon::getAttack()
    {
        return attack;
    }
    int Pokemon::getDefense()
    {
        return defense;
    }
    int Pokemon::getSpAttack()
    {
        return spAttack;
    }
    int Pokemon::getSpDef()
    {
        return spDef;
    }
    int Pokemon::getSpeed()
    {
        return speed;
    }
    int Pokemon::getPokeGen()
    {
        return pokeGen;
    }
    int Pokemon::getLegendary()
    {
        return legendary;
    }
    std::vector<Move> Pokemon::getMoves()
    {
        return pokemonMoves;
    }

    void setMoves()
    {
        //search through the b-tree or hash-map, and then find which ever one has the highest power
       //pokemonMoves.push_back( 
    }