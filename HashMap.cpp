#include "HashMap.h";
#include "Move.h";
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

