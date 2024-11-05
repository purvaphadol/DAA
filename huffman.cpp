#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node class for Huffman Tree
class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) {
        data = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator to create a min-heap based on frequency
class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree and generate codes
void buildHuffmanTree(char data[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        
        pq.push(newNode);
    }

    printCodes(pq.top(), "");
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {50, 10, 30, 5, 3, 2};

    buildHuffmanTree(data, freq, 6);
    return 0;
}

//Complexity Analysis :
//Time complexity: O(nlogn) where n is the number of unique characters.
//If there are n nodes, extractMin() is called 2*(n – 1) times. 
//extractMin() takes O(logn) time as it calls minHeapify(). So, overall time complexity is O(nlogn).
//Space Complexity is O(n) 
//Where n is the number of Unique Characters

/*

a :  0
b :  100
d :  1010
f :  10110
e :  10111
c :  11

*/