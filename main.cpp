//create main function

//create function to parse move data
//use two different data structures here to measure time difference, this is the main project 
//potentially make different data structures depending on priority feature for optimization

//create function to parse pokemon data
//assign 'best' moves here by searching through the move data strucutres
//make sure to measure time to have an efficiency measure


#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>
#include "Pokemon.cpp"
#include "Move.h"

//Reading Pokemon CSV
void ReadingCSVFile(std::string fileName, std::vector<Pokemon>& pokemon) {
		std::ifstream file(fileName);

	//implementation of initializing the objects for each row
	if (file.is_open()) {

		std::string fileRow;
		//gets the headers of the file
		getline(file, fileRow);

		while (getline(file, fileRow)) {

			std::istringstream stringStream(fileRow);

			std::string sPokeDexNumber;
            int pokeDexNumber;
			std::string name;
			std::string type1;
            std::string type2;
			std::string sTotal;
			int total;
			std::string sHP;
			int hp;
			std::string sAttack;
			int attack;
            std::string sDefense;
			int defense;
            std::string sSpAttack;
			int spAttack;
            std::string sSpDef;
			int spDef;
            std::string sSpeed;
			int speed;
            std::string sGen;
			int gen;
            std::string sLegendary;
			bool legendary;


			getline(stringStream, sPokeDexNumber, ',');
            pokeDexNumber = stoi(sPokeDexNumber);
			getline(stringStream, name, ',');
			getline(stringStream, type1, ',');
            getline(stringStream, type2, ',');
            getline(stringStream, sTotal, ',');
            total = stoi(sTotal);
			getline(stringStream, sHP, ',');
			hp = stoi(sHP);
			getline(stringStream, sAttack, ',');
			attack = stoi(sAttack);
			getline(stringStream, sDefense, ',');
			defense = stoi(sDefense);
            getline(stringStream, sSpAttack, ',');
			spAttack = stoi(sSpAttack);
            getline(stringStream, sSpDef, ',');
			spDef = stoi(sSpDef);
            getline(stringStream, sSpeed, ',');
			speed = stoi(sSpeed);            
            getline(stringStream, sGen, ',');
			gen = stoi(sGen);
            getline(stringStream, sLegendary);
            if (sLegendary == "False")
            {
                legendary = false;
            }
            else 
            {
                legendary = true;
            }

			//each object will store a row
			Pokemon setPoke(pokeDexNumber, name, type1, type2, total, hp, attack, defense, spAttack, spDef, speed, gen, legendary);
			pokemon.push_back(setPoke);

		}
	}
}


//reading Move Set CSV
void ReadingCSVFile(std::string fileName, std::vector<Move>& moves) {
		std::ifstream file(fileName);

	//implementation of initializing the objects for each row
	if (file.is_open()) 
    {

		std::string fileRow;
		//gets the headers of the file
		getline(file, fileRow);

		while (getline(file, fileRow)) 
        {

			std::istringstream stringStream(fileRow);

            std::string sMoveNum;
            int moveNum;
			std::string name;
			std::string type;
            std::string category;
            std::string contest;
            std::string sPP;
            int pp;
            std::string sPower;
            int power;
            std::string sAccuracy;
            int accuracy;
            std::string sGen;
            int gen;

			getline(stringStream, sMoveNum, ';');
            moveNum = stoi(sMoveNum);
			getline(stringStream, name, ';');
			getline(stringStream, type, ';');
            getline(stringStream, category, ';');
            getline(stringStream, contest, ';');
			getline(stringStream, sPP, ';');
			pp = stoi(sPP);
			getline(stringStream, sPower, ';');
			if (sPower == "None")
			{
				power = 0;
			}
			else
			{
				power = stoi(sPower);
			}
			getline(stringStream, sAccuracy, ';');
			if (sAccuracy== "None")
			{
				accuracy = 0;
			}
			else
			{
				accuracy = stoi(sAccuracy);
			}
            getline(stringStream, sGen);
			gen = stoi(sGen);

			//each object will store a row
			Move setMoves(moveNum, name, type, category, contest, pp, power, accuracy, gen);
			moves.push_back(setMoves);
		}
	}
}

bool binarySearch(std::vector<Pokemon>& _pokemon, std::string target)
{
	int left = 0;
	int mid = 0;
	int right = _pokemon.size();

	while (left < right)
	{
		if (target == _pokemon[mid].getName())
		{
			return true;
		}

		mid = left + (right - 1) / 2;
		if (target > _pokemon[mid].getName())
		{
			left = mid + 1;
		}
		else if (target < _pokemon[mid].getName())
		{
			right = mid;
		}
	}
	return false;
}

int main()
{
    std::vector<Pokemon> pokemon;
    std::vector<Move> moveSet;
    std::vector<Move> selectedMoves;

    ReadingCSVFile("pokemon.csv", pokemon);
    ReadingCSVFile("move-data.csv", moveSet);

    
    sort(pokemon.begin(), pokemon.end(), [](Pokemon& poke1, Pokemon& poke2)
    {
        return poke1.getName() < poke2.getName();
    });
    //Here is where we will do the b tree and hash map?


    std::string selectedPokemon;
    std::cout << "Enter a Pokemon (case-sensitive): ";
    std::cin >> selectedPokemon;
    
	if (!binarySearch(pokemon, selectedPokemon))
	{
		std::cout << "Pokemon not found!";
	}
	else
	{
		//do the thing
	}
    //search if the selectedPokemon is in the b-tree or hash-map, maybe time it here to show the search timing

    //determine how to pick and select moves, but put it into the vector

	//when comparing the moves to determine what is best, we need to do an stoi on power based on if it is (!= "None" as some moves do not do damage, for accuracy 
	//same thing if that is taken into consideration)


    //basically what is used to time the functions vvvv
    auto start = std::chrono::steady_clock::now();
    //instert into hash and b tree
    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    
}
