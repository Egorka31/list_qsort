#include <iostream>
#include <vector>

struct Node {
    Node* next;
    int data;
    
    Node(int data) : data(data), next()
    {}
};

Node * createList(std::vector<int> vect) {
    Node *root = nullptr;
    Node **pp = &root;
    for (auto i = vect.begin(); i != vect.end(); i++) {
        *pp = new Node(*i);
        pp = &(*pp)->next;
    }
    return root;
}

void printList(const Node* root) {
    for (;root;root = root->next)
        std::cout << root->data << " ";
    std::cout << '\n';
}

void quickSort(Node *&root) {
    if  (!root || !(root->next))
        return;
    
    Node *lhs = nullptr, **pplhs = &lhs;
    Node *rhs = nullptr, **pprhs = &rhs;
    Node *pvt = root;
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
    
    quickSort(lhs);
    quickSort(rhs);
    
    while (*pplhs)
        pplhs = &(*pplhs)->next;
    *pplhs = pvt;
    pvt->next = rhs;
    
    root = lhs;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vect(n);
    for(auto i = vect.begin(); i != vect.end(); i++)
        std::cin >> *i;
    Node* root = createList(vect);
    quickSort(root);
    printList(root);
    return 0;
}
