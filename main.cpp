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
#include "Pokemon.cpp"
#include "move-data.csv"
#include "pokemon.csv"

//Reading Pokemon CSV
void ReadingCSVFile(string fileName, vector<Pokemon>& pokemon) {
		ifstream file(fileName);

	//implementation of initializing the objects for each row
	if (file.is_open()) {

		string fileRow;
		//gets the headers of the file
		getline(file, fileRow);

		while (getline(file, fileRow)) {

			istringstream stringStream(fileRow);

			string sPokeDexNumber;
            int pokeDexNumber;
			string name;
			string type1;
            string type2;
			string sTotal;
			int total;
			string sHP;
			int hp;
			string sAttack;
			int attack;
            string sDefense;
			int defense;
            string sSpAttack;
			int spAttack;
            string sSpDef;
			int spDef;
            string sSpeed;
			int speed;
            string sGen;
			int gen;
            string sLegendary;
			bool legendary;


			getline(stringStream, sPokeDexNumber, ',');
            pokeDexNumber = stoi(sPokeDexNumber);
			getline(stringStream, name, ',');
			getline(stringStream, type1, ',');
            getline(stringStream, type2, ',');

			getline(stringStream, sHP, ',');
			hp = stoi(sHP);
			getline(stringStream, sAttack, ',');
			attack = stoi(sAttack);
			getline(stringStream, sDefense, ',');
			defense = stod(sDefense);
            getline(stringStream, sSpAttack, ',');
			sSpAttack = stod(sSpAttack);
            getline(stringStream, sSpDef, ',');
			spDef = stod(sSpDef);
            getline(stringStream, sSpeed, ',');
			speed = stod(sSpeed);            
            getline(stringStream, sGen, ',');
			gen = stod(sGen);
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
			Pokemon setPoke(pokeDexNumber, name, type1, type2, hp, attack, defense, sSpAttack, spDef, speed, gen, legendary);
			pokemon.push_back(setPoke);

		}
	}
}


//reading Move Set CSV
void ReadingCSVFile(string fileName, vector<Moves>& moves) {
		ifstream file(fileName);

	//implementation of initializing the objects for each row
	if (file.is_open()) {

		string fileRow;
		//gets the headers of the file
		getline(file, fileRow);

		while (getline(file, fileRow)) {

			istringstream stringStream(fileRow);

            string sMoveNum
            int moveNum;
			string name;
			string type;
            string category;
            string contest;
            string sPP;
            int pp;
            string sPower;
            int power;
            string sAccuracy;
            int accuracy;
            string sGen;
            int gen;

			getline(stringStream, sMoveNum, ',');
            moveNum = stoi(sMoveNum);
			getline(stringStream, name, ',');
			getline(stringStream, type, ',');
            getline(stringStream, category, ',');
            getline(stringStream, contest, ',');
			getline(stringStream, sPP, ',');
			pp = stoi(sPP);
			getline(stringStream, sPower, ',');
			power = stoi(sPower);
			getline(stringStream, sAccuracy, ',');
			accuracy = stod(sAccuracy);
            getline(stringStream, sGen,);
			gen = stod(sGen);

			//each object will store a row
			Moves setMoves(moveNum, name, type, category, contest, pp, power, accuracy, gen);
			moves.push_back(setMoves)
		}
	}
}


int main()
{
    std::vector<Pokemon> pokemon;
    std::vector<Moves> moveSet;
    std::vector<Moves> selectedMoves;

    ReadingCSVFile("pokemon.csv", pokemon);
    ReadingCSVFile("move-data.csv", moveSet);


    //Here is where we will do the b tree and hash map?


    std::string selectedPokemon;
    std::cout << "Enter a Pokemon: ";
    std::cin >> selectedPokemon;
    
    //search if the selectedPokemon is in the b-tree or hash-map, maybe time it here to show the search timing

    //determine how to pick and select moves, but put it into the vector

    
}
