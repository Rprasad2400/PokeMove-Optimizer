#include <string>
#include "Move.cpp"
#include <vector>
#pragma once

class Pokemon
{
    int pokeDexNumber;
	std::string pokeName;
	std::string pokeType1;
    std::string pokeType2 = "";
	int total;
	int hp;
	int attack;
	int defense;
	int spAttack;
	int spDef;
	int speed;
	int pokeGen;
	bool legendary;
    std::vector<Move> pokemonMoves;
    
    public:

    Pokemon() {pokeDexNumber = 0; pokeName = ""; pokeType1 = ""; pokeType2 = ""; total = 0; 
        hp = 0; attack = 0; defense = 0; spAttack = 0; spDef = 0; speed = 0; pokeGen = 0; legendary = false; pokemonMoves;}

    Pokemon(int _pokeDexNumber, std::string _name, std::string _type1, std::string type2, int _total, 
        int _hp, int _attack, int _defense, int _spAttack, int _spDef, int _speed, int _gen, bool _legendary);

    //make get functions
    int getPokeDexNumber();
    std::string getName();
    std::string getType1();
    std::string getType2();
    int getTotal();
    int getHP();
    int getAttack();
    int getDefense();
    int getSpAttack();
    int getSpDef();
    int getSpeed();
    int getPokeGen();
    int getLegendary();
    std::vector<Move> getMoves();
    void setMoves();
    

};