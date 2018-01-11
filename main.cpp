#include <iostream>
#include <vector>

template<typename T>
struct Node {
	Node* next;
	T data;

	Node(T data) : data(data), next()
	{}
};

template<typename T>
Node<T> * createList(std::vector<T> vect) {
	Node<T> *root = nullptr;
	Node<T> **pp = &root;
	for (auto i = vect.begin(); i != vect.end(); i++) {
		*pp = new Node<T>(*i);
		pp = &(*pp)->next;
	}
	return root;
}

template<typename T>
void printList(const Node<T>* root) {
	for (; root; root = root->next)
		std::cout << root->data << " ";
	std::cout << '\n';
}

template<typename T>
void split(Node<T> *&root, Node<T> *&lhs, Node<T> *&rhs, Node<T> *&pvt, Node<T> **&pplhs, Node<T> **&pprhs) {
	root = root->next;
	pvt->next = nullptr;

	while (root) {
		if (root->data < pvt->data) {
			*pplhs = root;
			pplhs = &(*pplhs)->next;
		}
		else {
			*pprhs = root;
			pprhs = &(*pprhs)->next;
		}
		root = root->next;
	}

	*pplhs = *pprhs = nullptr;
}

template<typename T>
void bonding(Node<T> *&root, Node<T> *&lhs, Node<T> *&rhs, Node<T> *&pvt, Node<T> **&pplhs, Node<T> **&pprhs) {
	while (*pplhs)
		pplhs = &(*pplhs)->next;
	*pplhs = pvt;
	pvt->next = rhs;
}

template<typename T>
void quickSort(Node<T> *&root) {
	if (!root || !(root->next))
		return;

	Node<T> *lhs = nullptr, **pplhs = &lhs;
	Node<T> *rhs = nullptr, **pprhs = &rhs;
	Node<T> *pvt = root;

	split(root, lhs, rhs, pvt, pplhs, pprhs);

	quickSort(lhs);
	quickSort(rhs);

	bonding(root, lhs, rhs, pvt, pplhs, pprhs);

	root = lhs;
}

int main() {
	size_t n = 0;
	std::cin >> n;
	std::vector<int> vect(n, 0);
	for (auto i = vect.begin(); i != vect.end(); i++)
		std::cin >> *i;
	Node<int>* root = createList(vect);
	quickSort(root);
	printList(root);
	return 0;
}
