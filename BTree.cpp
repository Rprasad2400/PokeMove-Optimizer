#include <iostream> 
#include "BTree.h"

//default constructor
BTree::BTree(){
    root = nullptr;
}

//public search function
std::vector<Move> BTree::search(Pokemon pokemon){
    std::vector<Move> moves;                 //vector to store top 4 moves based on types
    
    
    if (this->root == nullptr){             //check for an empty tree
        std::cout << "Error: No moves loaded \n";
        return moves;
    }
    else {                                 //run through recurive helper function 
        return helperPreOrder(this->root, moves, pokemon.getType1(), pokemon.getType2());
    }                        //output vector of top four moves based on type and damage
}

//recursive function to traverse tree
std::vector<Move> BTree::helperPreOrder(TreeNode* helpRoot, std::vector<Move>& moves, std::string type1, std::string type2){
    if (helpRoot == nullptr){
        return moves;
    } else{                                                                  //if not null
        for (auto value : helpRoot->values){                                 //iterate through every value in the node
        //it at least makes it here
            if (value.getMoveType() == type1 || value.getMoveType() == type2){                      //check if types match
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
                    // for (auto a : moves){
                    //     std::cout << a.getMoveName() << " ";
                    // }
                    //     std::cout << std::endl;
                }
            }
        }
                for (auto a : moves){
                        std::cout << a.getMoveName() << " ";
                    }
                        std::cout << std::endl;
        
        int counter = 0;
        for (auto a : helpRoot->children){       //iterate through all children of root
                std::cout << counter++ << std::endl;
                return helperPreOrder(a, moves, type1, type2);
        }
    }
    return moves;
}

//public insertion function, no access to root
void BTree::insert(Move key){
      this->root = helperInsert(this->root, key);
}


//recursive helper insertion function
BTree::TreeNode* BTree::helperInsert(TreeNode* helpRoot, Move key){
//try to make it recursive, return and update pointer and children values 

    if (helpRoot == nullptr){
        return new TreeNode(key);                                                                                                 //return value 
    } 
    
    else if (helpRoot->children.size() == 0){
        helpRoot->values.push_back(key);
        if(helpRoot->values.size() > MAXKEYS){
            TreeNode* temp1 = new TreeNode();
            TreeNode* temp2 = new TreeNode();
            TreeNode* temp3 = new TreeNode();
            temp1->values.push_back(helpRoot->values[MAXKEYS/2]);
            for (int i = 0; i < MAXKEYS/2; i++){
                temp2->values.push_back(helpRoot->values[i]);
            }
            for (int j = MAXKEYS/2 + 1; j < helpRoot->values.size(); j++){
                temp3->values.push_back(helpRoot->values[j]);
            }
            helpRoot = temp1;
            helpRoot->children.push_back(temp2);
            helpRoot->children.push_back(temp3);
        }
        return helpRoot;                                                                                                         //return value
    } 
    
    
    else {    
        int a = 0;
        for(; a < helpRoot->children.size(); a++){
            if (key < helpRoot->values[a]){

                TreeNode* temp = helperInsert(helpRoot->children[a], key);
                if (temp->values.size() <= 1){

                    int b = 0;
                    for (; b < helpRoot->values.size(); b++){

                        if (temp->values[0] < helpRoot->values[b]){
                            helpRoot->values.insert(helpRoot->values.begin(), b, temp->values[0]);
                            helpRoot->children[b] = temp->children[0];
                            helpRoot->children.insert(helpRoot->children.begin(), b+1, temp->children[1]);
                            return helpRoot;                                                                                 //return value

                        }
                    }
                    helpRoot->values.insert(helpRoot->values.begin(), b, temp->values[0]);
                    helpRoot->children[b] = temp->children[0];
                    helpRoot->children.insert(helpRoot->children.begin(), b+1, temp->children[1]);
                    return helpRoot;                                                                                        //return value
                }
                
            }
            
        }
         TreeNode* temp = helperInsert(helpRoot->children[a], key);
        int c = 0;
        for (; c < helpRoot->values.size(); c++){

            if (temp->values[0] < helpRoot->values[c]){
                helpRoot->values.insert(helpRoot->values.begin(), c, temp->values[0]);
                helpRoot->children[c] = temp->children[0];
                helpRoot->children.insert(helpRoot->children.begin(), c+1, temp->children[1]);
                return helpRoot;                                                                                             //return value
            }
        }
        helpRoot->values.insert(helpRoot->values.begin(), c, temp->values[0]);
        helpRoot->children[c] = temp->children[0];
        helpRoot->children.insert(helpRoot->children.begin(), c+1, temp->children[1]);
        return helpRoot;                                                                                                    //return value 
    }

    return helpRoot;                                                                                                       //return value
}

