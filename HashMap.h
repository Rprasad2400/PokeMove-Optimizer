
#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "Move.h";
using namespace std;
class HashMap {

private:
	class Node {
	public:
		Node() {
		}
		Node(Move move) {
			val = move;
			hasValue = true;

		};
		Node* next = nullptr;
		Move val;
		bool hasValue = false;
		~Node() {
			next = nullptr;
		}
	};
	int numelements= 0;
	int size = 10;
	double loadFactor = 0.8;
	
	vector<Node> arrayList = vector<Node>(10);
	void insertNode(Node* k, Move move);
	int hashFunction(string name);
	Move searchLinkedList(Node* k, string name);
	bool removeNode(Node* k, string name);
public:
	Move get(string key);
	void remove(string key);
	vector<Move> searchBestMove(string typemove);
    	vector<Move> searchBestMove(string typemove,string typemove2);
	void insert(Move value);

};
