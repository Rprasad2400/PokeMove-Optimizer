#include "Move.h"
    
Move(int _moveNum, string _name, string _type, string _category, string _contest,
        int _pp, int _power, int _accuracy,int _gen)
    {
        moveNum = _moveNum;
        moveName = _name;
        moveType = _type;
        category = _category;
        contest = _contest;
        pp = _pp;
        power = _power;
        accuracy = _accuracy;
        moveGen = _gen;
    }

    //make get functions
    int Move::getMoveNum();
    {
        return moveNum;
    }
    std::string Move::getMoveName()
    {
        return moveName;
    }
    std::string Move::getMoveType()
    {
        return moveType;
    }
    std::string  Move::getCategory()
    {
        return category;
    }
    std::string Move::getContest()
    {
        return contest;
    }
    int Move::getPP()
    {
        return pp;
    }
    int Move::getPower()
    {
        return power;
    }
    int Move::getAccuracy()
    {
        return accuracy;
    }
    int Move::getMoveGen()
    {
        return moveGen;
    }
