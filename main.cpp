#include iostream
#include vector

struct Node {
    Node next;
    int data;
    
    Node(int data)  data(data), next()
    {}
};

Node  createList(stdvectorint vect) {
    Node root = nullptr;
    Node pp = &root;
    for (auto i = vect.begin(); i != vect.end(); i++) {
        pp = new Node(i);
        pp = &(pp)-next;
    }
    return root;
}

void printList(const Node root) {
    for (;root;root = root-next)
        stdcout  root-data   ;
    stdcout  'n';
}

void quickSort(Node &root) {
    if  (!root  !(root-next))
        return;
    
    Node lhs = nullptr, pplhs = &lhs;
    Node rhs = nullptr, pprhs = &rhs;
    Node pvt = root;
    root = root-next;
    pvt-next = nullptr;
    
    while (root) {
        if (root-data  pvt-data) {
            pplhs = root;
            pplhs = &(pplhs)-next;
        }
        else {
            pprhs = root;
            pprhs = &(pprhs)-next;
        }
        root = root-next;
    }
    
    pplhs = pprhs = nullptr;
    
    quickSort(lhs);
    quickSort(rhs);
    
    while (pplhs)
        pplhs = &(pplhs)-next;
    pplhs = pvt;
    pvt-next = rhs;
    
    root = lhs;
}

int main() {
    int n;
    stdcin  n;
    stdvectorint vect(n);
    for(auto i = vect.begin(); i != vect.end(); i++)
        stdcin  i;
    Node root = createList(vect);
    quickSort(root);
    printList(root);
    return 0;
}
