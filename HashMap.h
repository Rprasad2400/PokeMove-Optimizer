
#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "Move.h";
#include "Pokemon.h";
using namespace std;
class HashMap {

private:
//Node used for the seperate chaining within the hashMap
	class Node {
	public:
	//basic constructor
		Node() {
		}
	//constructor used to add Move within the Node
		Node(Move move) {
			val = move;
			hasValue = true;

		};
		//pointer to next Node
		Node* next = nullptr;
		//contains the value
		Move val;
		//checks whehther the Node has no value
		bool hasValue = false;
		~Node() {
			next = nullptr;
		}
	};
	//number of elements
	int numelements= 0;
	//current size of array
	int size = 10;
	//when to increase the size fo the array
	double loadFactor = 0.8;
	//array used in the HashMap containing Nodes
	vector<Node> arrayList = vector<Node>(10);

	//helperFunctions
	void insertNode(Node* k, Move move);
	int hashFunction(string name);
	Move searchLinkedList(Node* k, string name);
	bool removeNode(Node* k, string name);
public:
	Move get(string key);
	void remove(string key);
  	vector<Move> searchBestMove(Pokemon poke);
	void insert(Move value);

};
