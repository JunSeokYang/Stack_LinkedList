#include <iostream>

using namespace std;

class Node {
public:
	Node(int a);
	void Link(Node* a, Node* b);
	int Pop();
	Node* Next();
	Node* Left();
private:
	Node *Nextr, *Nextl;
	int elem;

};

class LinkedList {
public:
	LinkedList(int a);
	int Push(int a);
	int Pop();
	int size();
private:
	Node  *now;
	int sz;
};

Node::Node(int a) :
	elem{ a }, Nextr{ '\0' }, Nextl{ '\0' } {}

void Node::Link(Node* a, Node* b) {
	Nextr = a;
	a->Nextl = b;
}

int Node::Pop() {
	return elem;
}

Node* Node::Next() {
	return Nextr;
}

Node* Node::Left() {
	return Nextl;
}

LinkedList::LinkedList(int a) :
	now{ new Node(a) },sz{ 1 } {}

int LinkedList::Push(int a) {
	Node *buf;
	now->Link(new Node(a), now);
	now = now->Next();
	sz++;

	return a;
}

int LinkedList::Pop() {
	int a;
	Node *buf;
	if (sz == 0)
		return 100;
	else
		a = now->Pop();
	buf = now;
	now = now->Left();
	if (sz != 1)
		delete buf;
	sz--;
	return a;
}

int LinkedList::size() {
	return sz;
}