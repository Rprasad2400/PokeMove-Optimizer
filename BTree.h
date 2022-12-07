#include <iostream>
#include "Move.cpp"
#include <vector>
#include "Pokemon.cpp"
#include <algorithm>
#define MAXKEYS 1000000



//meant to map out and store several differnt b trees sorted by type.
//new approach: iterate through one big tree, and make min heap for top 4 moves by damage 
//if multiple type pokemon, check for all types
//maybe input types as a vector? to iterate through all types?


class BTree{
    //declare structure for Nodes and holding values 
    struct TreeNode{
        std::vector<Move> values;
        std::vector<TreeNode*> children; 

        TreeNode(){
            values = {};
            children = {};
        }

        TreeNode(Move move){
            values = {move};
            children =  {};
        }
    };

    //variables for overall Tree structure
    int nodeLimit; 
    BTree::TreeNode* root;

    //helper functions for internal operations
    BTree::TreeNode* helperInsert(TreeNode* helpRoot, Move key);
    std::vector<Move> helperPreOrder(TreeNode* helpRoot, std::vector<Move>& moves, std::string type1, std::string type2);


    public: 
    BTree();

    //public functions
    std::vector<Move> search(Pokemon pokemon);
    void insert(Move key);
};
