#include <iostream> 
#include "BTree.h"

//default constructor
BTree::BTree(){
    root = nullptr;
}

//public search function
std::vector<Move> BTree::search(Pokemon pokemon){
    std::vector<Move> moves;                 //vector to store top 4 moves based on types
    std::unordered_set<std::string> types;   //set to make type comparison easier
    types.insert(pokemon.getType1());
    types.insert(pokemon.getType2());
    
    if (this->root == nullptr){             //check for an empty tree
        std::cout << "Error: No moves loaded \n";
    }
    else {                                 //run through recurive helper function 
        helperPreOrder(this->root, moves, types);
    }
    return moves;                         //output vector of top four moves based on type and damage
}

//recursive function to traverse tree
void BTree::helperPreOrder(TreeNode* helpRoot, std::vector<Move> moves, std::unordered_set<std::string> types){
    if (helpRoot == nullptr){
        return;
    } else{                                                                  //if not null
        for (auto value : helpRoot->values){                                 //iterate through every value in the node
            if (types.count(value.getMoveType()) != 0){                      //check if types match
                if(moves.size() < 4){  
                    moves.push_back(value);                                  //if current moveset smaller than 4, add any move
                    std::sort(moves.begin(), moves.end());
                } else {
                    int tempIndex = -1;
                    for (int i = 0; i < 4; i++){
                        if (value.getPower() > moves[i].getPower()){        //check if new power level greater, replace smallest value
                            if (tempIndex == -1){
                                tempIndex = i;                             //if no value yet, set to current value
                            }else if (moves[tempIndex].getPower() > moves[i].getPower()){ //compare new value with existing smallest
                                tempIndex = i;
                            }
                        }
                    }
                    if (tempIndex != -1){         //if value was found to be greater, replace with current smallest element 
                        moves[tempIndex] = value;
                    }
                }
            }
            for (auto a : helpRoot->children){       //iterate through all children of root
                helperPreOrder(a, moves, types);
            }
        }
    }
}

//public insertion function, no access to root
void BTree::insert(Move key){
    this->root = helperInsert(this->root, key);
}


//recursive helper insertion function
BTree::TreeNode* BTree::helperInsert(TreeNode* helpRoot, Move key){
//try to make it recursive, return and update pointer and children values 

    if (helpRoot == nullptr){                                           //this should never be the case, but checking just in case
        std::cout << "Reached a null node" << std::endl;
        return;
    } else if (helpRoot->children.size() != 0){                         //if the node has children, append to those instead

        for (int i = 0; i < helpRoot->values.size(); i++){              //numbers of pointers = number of keys + 1, so pointer array values
                                                                        //line up with the comparison values
            if (helpRoot->values[i].getPower() > key.getPower()){       
                                                                        //if a node has been found to be a greater value, traverse the child path before it
                //need some way to differ between normal return and split return
                //add code block for balanced insertion
            }
            
            //balanced insertion code block, same as above              //if end of children, node value is greater, go to end value 

        }
    } else {
        helpRoot->children.push_back(&TreeNode(key));
        std::sort(helpRoot->children.begin(), helpRoot->children.end());
        if(helpRoot->children.size() > MAXKEYS){
            //split the children into two parts, down the middle (element 5 will always be the middle)
            //bring the new element up, let the left pointer go to new node of elements 0 - 4, right pointer to new node of elements 6 to 10
        }    
    }
}

