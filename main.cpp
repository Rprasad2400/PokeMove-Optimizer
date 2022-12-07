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
#include <random>
#include "Pokemon.cpp"
#include "Move.cpp"
#include "BTree.cpp"
#include "HashMap.cpp"

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
    std::ifstream file(babyFile);

    //implementation of initializing the objects for each row
    if (file.is_open()) 
    {

        std::string fileRow;
        //gets the headers of the file
        getline(file, fileRow);
        int moveIndexIterator = 729;

		std::srand(time(NULL));
        while (getline(file, fileRow) && moveIndexIterator < 150000) 
        {
            std::istringstream stringStream(fileRow);
            
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

			//Uncomment the line under if you wanna wait for a while ;)
			//std::cout << type << " " << category << " " << pp << " " << attack << " " << accuracy << std::endl;

            Move setMove(moveIndexIterator, babyMoveName, type, category, contest, pp, attack, accuracy, generation);
            moves.push_back(setMove);
			moveIndexIterator++;
        }
    }
}


int binarySearch(std::vector<Pokemon>& _pokemon, std::string target)
{
	int left = 0;
	int right = _pokemon.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (target == _pokemon[mid].getName())
		{
			return mid;
		}
		if (target > _pokemon[mid].getName())
		{
			left = mid + 1;
		}
		else if (target < _pokemon[mid].getName())
		{
			right = mid - 1;
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
	BTree B;
	HashMap H;

	//Reading the data sets
    ReadingCSVFile("pokemon.csv", pokemon);
    ReadingCSVFile("move-data.csv", moveSet);
	ReadingBabyNameCSVFile("NationalNames.csv", moveSet);

	//just to sort and find the Pokemon faster, we are comparing the data structure through moves
    sort(pokemon.begin(), pokemon.end(), [](Pokemon& poke1, Pokemon& poke2)
    {
        return poke1.getName() < poke2.getName();
    });
    
    
	std::string selectedPokemon;
    std::cout << "Enter a Pokemon (case-sensitive): ";
    std::cin >> selectedPokemon;
    
	//Search to see if the entered Pokemon is in the data set
	int foundPokemon = binarySearch(pokemon, selectedPokemon);


	if (foundPokemon == -1)
	{
		std::cout << "Pokemon not found!" << std::endl << "Try again!";
	}
	else
	{
		std::cout << pokemon[foundPokemon].getName() << ": " << std::endl;

		for (int i = 0; i < moveSet.size(); i++)
		{
			//B.insert(moveSet[i]);
			H.insert(moveSet[i]);
		}

		//Chrono is for getting when the function starts and ends, and then it subtracts to get how long it took
		//Testing out B Tree
    	auto start = std::chrono::high_resolution_clock::now();
		//optimalBTreeMoves = B.search(pokemon[foundPokemon]);
    	auto end = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout << "Finding optimal moves through B-Tree: " << diff.count() << " milliseconds" << std::endl << std::endl;	
		std::cout << "Possible Optimal Moveset with B-Tree " << selectedPokemon  << ": "<< std::endl; 

		//std::cout << "1. " << optimalBTreeMoves[0].getMoveName() << std::endl << 
		//"2. " << optimalBTreeMoves[1].getMoveName() << std::endl <<
		//"3. " << optimalBTreeMoves[2].getMoveName() << std::endl <<
		//"4. " << optimalBTreeMoves[3].getMoveName() << std::endl << std::endl << std::endl;
		

		//Testing out Hashmap 
		start = std::chrono::high_resolution_clock::now();
		optimalHashMapMoves = H.searchBestMove(pokemon[foundPokemon]);
		end = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout << "Finding optimal moves through Hashmap: " << diff.count() << " milliseconds" << std::endl;	
		std::cout << "Possible Optimal Moveset with Hashmap " << selectedPokemon  << ": "<< std::endl; 
		
		std::cout << "1. " << optimalHashMapMoves[0].getMoveName() << ": " << optimalHashMapMoves[0].getPower() << std::endl << 
		"2. " << optimalHashMapMoves[1].getMoveName() << ": " << optimalHashMapMoves[1].getPower() << std::endl <<
		"3. " << optimalHashMapMoves[2].getMoveName() << ": " << optimalHashMapMoves[2].getPower() << std::endl <<
		"4. " << optimalHashMapMoves[3].getMoveName() << ": " << optimalHashMapMoves[3].getPower() << std::endl;
		
	}

};
