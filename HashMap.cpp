#include "HashMap.h";
#include "Move.h";
#include "Pokemon.h";

//method to perform seperate chaining and insert Node
void HashMap::insertNode(Node* k, Move move) {
	//iterates until it can place the new Node
	while (!(k->next == nullptr)) {
		k = k->next;
	}
	if (k->next == nullptr) {

		k->next = new Node(move);
	}
}

//return the move based on Name
Move HashMap::get(string key) {
	int hashNum = hashFunction(key);
	if (!arrayList[hashNum].hasValue) {
		throw std::invalid_argument("Move does not exist in hash Map");
	}
	else {
		return searchLinkedList(&arrayList[hashNum], key);
	}


};

//returns the hash value based on name
int HashMap::hashFunction(string name) {
	int key = 0;
	for (int i = 0; i < name.size(); i++) {
		key += name[i];

	}
	vector<Node> arrayList(loadFactor);
	key = key % size;
	return key;
}

//removes the value based on the name
void HashMap::remove(string key) {
	int hashNum = hashFunction(key);
	if (!arrayList[hashNum].hasValue) {
		throw std::invalid_argument("Move does not exist in hash Map");
	}
	else {
		if (arrayList[hashNum].val.getMoveName() == key) {
			arrayList.erase(arrayList.begin() + hashNum);
			numelements--;
		}
		else {
			bool removed = removeNode(&arrayList[hashNum], key);
			if (!removed) {
				throw std::invalid_argument("Move does not exist in hash Map");
			}
			else {
				numelements--;
			}
		}

	}
};

//searches for the bestMove Possible and reurns a subset of 4 of the strongest moves for the type 
vector<Move> HashMap::searchBestMove(Pokemon poke) {
	vector<Move> s;
	for (int i = 0; i < arrayList.size(); i++) {
		Node* k = &arrayList[i];
		while (k != nullptr) {
			if (k->val.getMoveType() == poke.getType1() || ((k->val.getMoveType() == poke.getType2()) && poke.getType2() != ""))
			{
				if (s.size() < 4) {
					s.push_back(k->val);
				}
				else {
					int min = 0;
					for (int j = 0; j < 4; j++) {
						if (s[min].getPower() > s[j].getPower()) {
							min = j;
						}

					}
					if(s[min].getPower() < k->val.getPower()){
						s[min] = k->val;
					}
					
				}

			}
			k = k->next;

		}
	}
	return s;
}

//searches the LinkedList for the name
Move HashMap::searchLinkedList(Node* k, string name) {
	while (k != nullptr) {
		if (k->val.getMoveName() == name) {
			return k->val;
		}
		else {
			k = k->next;
		}
	}
	throw std::invalid_argument("Move does not exist in hash Map");


}
//removes the Node from the index from the Linked List
bool HashMap::removeNode(Node* k, string name) {
	while (k->next != nullptr) {
		Node* child = k->next;
		if (child->val.getMoveName() == name) {
			k->next = child->next;
			delete child;
			return true;
		}
		else {
			k = child;
		}
	}
	return false;

}
//inserts the value in the HashMap
void HashMap::insert(Move value) {
	//returns the hash from the Move
	int key = hashFunction(value.getMoveName());


	//inserts the Node into the array
	if (arrayList[key].hasValue) {
		insertNode(&arrayList[key], value);
	}
	else {
		arrayList[key] = Node(value);
	}
	//increases the num of elements
	numelements++;

	//resizes the array based on the load factor
	if ((double(numelements) / double(arrayList.size())) > loadFactor) {
		size = (arrayList.size() / loadFactor);
		arrayList.resize(size);


	}


};
