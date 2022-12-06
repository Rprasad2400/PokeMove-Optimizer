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
#include <queue>
#include <time.h>
#include "Pokemon.cpp"
#include "Move.h"
#include "BTree.h"
#include "HashMap.h"

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

//For fabricating more moves
void ReadingBabyNameCSVFile(std::string babyFile, std::vector<Move>& moves)
{
    //use this for the move index
    std::ifstream file(babyFile);

    //implementation of initializing the objects for each row
    if (file.is_open()) 
    {

        std::string fileRow;
        //gets the headers of the file
        getline(file, fileRow);
        int moveIndexIterator = 729;

        while (getline(file, fileRow) && moveIndexIterator < 150000) 
        {
            std::istringstream stringStream(fileRow);
            std::srand(time(NULL));
            int randomIndex;

            std::string index;
            std::string babyMoveName;

            getline(stringStream, index, ',');
            getline(stringStream, babyMoveName, ',');
			babyMoveName += index;
            getline(stringStream, fileRow);

			//The rest is to fabricate more data points to fit into the >100000 data point requirement
            std::string possibleTypes[18] = { "Normal", "Fire", "Water", "Grass", "Electric", 
                "Ice", "Fighting", "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost",
                "Dark", "Dragon", "Steel", "Fairy"};
            randomIndex = rand() % 18;
            std::string type = possibleTypes[randomIndex];

            std::string possibleCategories[2] = { "Physical", "Special"};
            randomIndex = rand() % 2;
            std::string category = possibleCategories[randomIndex];

            std::string contest = "???";

            int possiblePP[9] = {1, 5, 10, 15, 20, 25, 30, 35, 40};
            randomIndex = rand() % 9;
            int pp = possiblePP[randomIndex];

            int possibleAttacks[50] = {0, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 
				80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 
				165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 
				245, 250};

            randomIndex = rand() % 50;
            int attack = possibleAttacks[randomIndex];

            int possibleAccuracy[16] = {0, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
            randomIndex = rand() % 16;
            int accuracy = possibleAccuracy[randomIndex];
			int generation = 0;

            Move setMove(moveIndexIterator, babyMoveName, type, category, contest, pp, attack, accuracy, generation);
            moves.push_back(setMove);
			moveIndexIterator++;
        }
    }



    //in csv file, do this and store it into another variable, then do the same for the rest, then use the variables for the construction
    //after that add it into the vector
}


int binarySearch(std::vector<Pokemon>& _pokemon, std::string target)
{
	int left = 0;
	int mid = 0;
	int right = _pokemon.size();

	while (left < right)
	{
		if (target == _pokemon[mid].getName())
		{
			return mid;
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
	return -1;
}

int main()
{
	using std::chrono::milliseconds;
    std::vector<Pokemon> pokemon;
    std::vector<Move> moveSet;
	std::vector<Move> optimalBTreeMoves;
	std::vector<Move> optimalHashMapMoves;
	//std::priority_queue <Move, std::vector<Move>, HigherPower> selectedMovesPrio;


    ReadingCSVFile("pokemon.csv", pokemon);
    ReadingCSVFile("move-data.csv", moveSet);
	ReadingBabyNameCSVFile("NationalNames.csv", moveSet);
	//int size = moveSet.size();
	//std::cout << moveSet[140001].getMoveName() << std::endl;
	/*
    selectedMovesPrio.push(moveSet[0]);
	selectedMovesPrio.push(moveSet[100]);
	selectedMovesPrio.push(moveSet[1000]);
	selectedMovesPrio.push(moveSet[300]);

	Move move = selectedMovesPrio.top();
	std::cout << move.getMoveName() << std::endl;
	selectedMovesPrio.pop();

	move = selectedMovesPrio.top();
	std::cout << move.getMoveName() << std::endl;
	selectedMovesPrio.pop();

	move = selectedMovesPrio.top();
	std::cout << move.getMoveName() << std::endl;
	*/

	//just to sort and find the Pokemon faster, we are comparing the data structure through moves
    sort(pokemon.begin(), pokemon.end(), [](Pokemon& poke1, Pokemon& poke2)
    {
        return poke1.getName() < poke2.getName();
    });
    
    
	std::string selectedPokemon;
    std::cout << "Enter a Pokemon (case-sensitive): ";
    std::cin >> selectedPokemon;
    
	int foundPokemon = binarySearch(pokemon, selectedPokemon);
	std::cout << pokemon[foundPokemon].getName() << std::endl;

	if (foundPokemon == -1)
	{
		std::cout << "Pokemon not found!";
	}
	else
	{
		//Testing out B-Tree searching
    	auto startB = std::chrono::high_resolution_clock::now();
		optimalBTreeMoves = search(pokemon[foundPokemon]);
    	auto endB = std::chrono::high_resolution_clock::now();
		auto diffB = std::chrono::duration_cast<std::chrono::milliseconds>(endB - startB);
		std::cout << "Finding optimal moves through B-Tree: " << diffB.count() << " milliseconds" << std::endl;	
		std::cout << "Possible Optimal Moveset with B-Tree " << selectedPokemon  << ": "<< std::endl; 

		std::cout << "1. " << optimalBTreeMoves[0].getMoveName() << std::endl << 
		"2. " << optimalBTreeMoves[1].getMoveName() << std::endl <<
		"3. " << optimalBTreeMoves[2].getMoveName() << std::endl <<
		"4. " << optimalBTreeMoves[3].getMoveName() << std::endl << std::endl;
		

		//Testing out Hashmap searching
		auto starthash = std::chrono::high_resolution_clock::now();
		optimalHashMapMoves = searchBestMove(pokemon[foundPokemon]);
		auto endhash = std::chrono::high_resolution_clock::now();
		auto diffhash = std::chrono::duration_cast<std::chrono::milliseconds>(endhash - starthash);
		std::cout << "Finding optimal moves through Hashmap: " << diffhash.count() << " milliseconds" << std::endl;	
		std::cout << "Possible Optimal Moveset with Hashmap " << selectedPokemon  << ": "<< std::endl; 
		
		std::cout << "1. " << optimalHashMapMoves[0].getMoveName() << std::endl << 
		"2. " << optimalHashMapMoves[1].getMoveName() << std::endl <<
		"3. " << optimalHashMapMoves[2].getMoveName() << std::endl <<
		"4. " << optimalHashMapMoves[3].getMoveName() << std::endl;
		

		/*
		if (pokemon[foundPokemon].getType1() > pokemon[foundPokemon].getSpAttack())
		{
			//search for the move that is physical and has higher power
			searchfunction(category "physical")
		}
		else
		{
			//search for the move that is special and has higher power
			searchfunction(category "special")
		}
		*/
	}

};
