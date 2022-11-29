#include <string>

class Move
{
    int moveNum;
	std::string moveName;
	std::string moveType;
    std::string category;
    std::string contest;
    int pp;
    int power;
    int accuracy;
    int moveGen;

    Move() {moveNum = 0; moveName = ""; moveType = ""; category = ""; contest = ""; 
        pp = 0; power = 0; accuracy = 0; gen = 0;}
        
    Move(int _moveNum, string _name, string _type, string _category, string _contest,
        int _pp, int _power, int _accuracy,int _gen);

    //make get functions
    int getMoveNum();
    std::string getMoveName();
    std::string getMoveType();
    std::string getCategory();
    std::string getContest();
    int getPP();
    int getPower();
    int getAccuracy();
    int getMoveGen();
}
