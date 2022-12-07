#include "HashMap.h";
#include "Move.h";
#include "Pokemon.h";
void HashMap::insertNode(Node* k, Move move) {

	while (!(k->next == nullptr)) {
		k = k->next;
	}
	if (k->next == nullptr) {

		k->next = new Node(move);
	}
}

Move HashMap::get(string key) {
	int hashNum = hashFunction(key);
	if (!arrayList[hashNum].hasValue) {
		throw std::invalid_argument("Move does not exist in hash Map");
	}
	else {
		return searchLinkedList(&arrayList[hashNum], key);
	}


};

int HashMap::hashFunction(string name) {
	int key = 0;
	for (int i = 0; i < name.size(); i++) {
		key += name[i];

	}
	vector<Node> arrayList(loadFactor);
	key = key % size;
	return key;
}

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

void HashMap::insert(Move value) {
	int key = hashFunction(value.getMoveName());


	if (arrayList[key].hasValue) {
		insertNode(&arrayList[key], value);
	}
	else {
		arrayList[key] = Node(value);
	}
	numelements++;

	if ((double(numelements) / double(arrayList.size())) > loadFactor) {
		size = (arrayList.size() / loadFactor);
		arrayList.resize(size);


	}


};
