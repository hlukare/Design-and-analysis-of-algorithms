#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* lr, Node* ri) {
        return lr->freq > ri->freq;
    }
};

void print(Node* root, string str) {
    if (!root)
        return;

    if (root->ch != '$')
        cout << root->ch << ": " << str << "\n";

    print(root->left, str + "0");
    print(root->right, str + "1");
}

void make_tree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }
    print(pq.top(), "");
}

int main() {
    string text;
    cout<<"Enter string:- ";
    cin>>text;
    make_tree(text);
    return 0;
}
