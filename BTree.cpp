#include <iostream> 
#include "BTree.h"

//default constructor
BTree::BTree(){
    root = nullptr;
}

//public search function
std::vector<Move> BTree::search(Pokemon pokemon){
    std::vector<Move> moves;                 //vector to store top 4 moves based on types
    
    std::sort(this->root->values.begin(), this->root->values.end());
    
    
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
        return new TreeNode(key);
    }
     else if (helpRoot->values.size() < MAXKEYS) {
        helpRoot->values.push_back(key);
    } else if (helpRoot->children.size() != 0){                         
        int i = 0;
        bool traversed = false;
        TreeNode* temp = nullptr;
        for (;i < helpRoot->values.size(); i++){          
            if (key.getPower() < helpRoot->values[i].getPower()){       
               helpRoot->children[i] = helperInsert(helpRoot->children[i], key);
               traversed = true;
               break;
            }
        }
        if (!traversed){
            helpRoot->children[i] = helperInsert(helpRoot->children[i], key);
        }

        if (temp != nullptr && temp->values.size() <= 1){   
            int x = 0;
            bool added = false;
            for (; x < helpRoot->values.size(); x++){
                if(helpRoot->values[x].getPower() > temp->values[0].getPower()){
                        helpRoot->values.insert(helpRoot->values.begin(), x, temp->values[0]);
                        helpRoot->children[x] = temp->children[0];
                        helpRoot->children.insert(helpRoot->children.begin(), x+1, temp->children[1]);
                        added = true;
                        break;
                }
            }
            if (!added){
                helpRoot->values.insert(helpRoot->values.begin(), x, temp->values[0]);
                helpRoot->children[x] = temp->children[0];
                helpRoot->children.insert(helpRoot->children.begin(), x+1, temp->children[1]);
            }

            helpRoot = temp;
        } 
        //if no split occurred, no special function is needed
    }

    if(helpRoot->values.size() > MAXKEYS){
        //split the children into two parts, down the middle (element 5 will always be the middle)
        //bring the new element up, let the left pointer go to new node of elements 0 - 4, right pointer to new node of elements 6 to 10
        TreeNode* temp1 = new TreeNode(helpRoot->values[MAXKEYS/2]);
        TreeNode* temp2 = new TreeNode();
        TreeNode* temp3 = new TreeNode();
        for (int a = 0; a < MAXKEYS/2; a++){
            temp2->values.push_back(helpRoot->values[a]);
        }
        for (int b = MAXKEYS/2 + 1; b < helpRoot->values.size(); b++){
            temp3->values.push_back(helpRoot->values[b]);
        }

        temp1->children.push_back(temp2);
        temp1->children.push_back(temp3);

        // TreeNode* current = temp1;
        // if (current->parent != nullptr && current->parent->values.size() < MAXKEYS){
        //     current = current->parent;
        //     int x = 0;
        //     bool added = false;
        //     for (; x < current->values.size(); x++){
        //         if(current->values[x].getPower() > temp1->values[0].getPower()){
        //                 current->values.insert(current->values.begin(), x, temp1->values[0]);
        //                 current->children[x] = temp1->children[0];
        //                 current->children.insert(current->children.begin(), x+1, temp1->children[1]);
        //                 added = true;
        //                 break;
        //         }
        //     }
        //     if (!added){
        //         current->values.insert(current->values.begin(), x, temp1->values[0]);
        //         current->children[x] = temp1->children[0];
        //         current->children.insert(current->children.begin(), x+1, temp1->children[1]);
        //     }

        // }
        // helpRoot = temp1;
    }    
    return helpRoot;
}

