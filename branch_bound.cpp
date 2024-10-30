#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

float bound(Node u, int n, int W, Item items[]) {
    if (u.weight >= W) return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while ((j < n) && (total_weight + items[j].weight <= W)) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    if (j < n) {
        profit_bound += (W - total_weight) * (float(items[j].value) / items[j].weight);
    }

    return profit_bound;
}

int knapsack(Item items[], int n, int W) {
    Node nodes[100];
    int numNodes = 0;
    
    sort(items, items + n, [](Item a, Item b) {
        return (float)a.value / a.weight > (float)b.value / b.weight;
    });

    Node u;
    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = bound(u, n, W, items);

    nodes[numNodes++] = u;
    int maxProfit = 0;

    while (numNodes > 0) {
        Node currentNode = nodes[--numNodes];

        if (currentNode.bound > maxProfit) {
            Node v;
            v.level = currentNode.level + 1;
            v.weight = currentNode.weight + items[v.level].weight;
            v.profit = currentNode.profit + items[v.level].value;

            if (v.weight <= W && v.profit > maxProfit)
                maxProfit = v.profit;

            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit && v.level < n)
                nodes[numNodes++] = v;

            v.weight = currentNode.weight;
            v.profit = currentNode.profit;
            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit && v.level < n)
                nodes[numNodes++] = v;
        }
    }
    return maxProfit;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    int maxProfit = knapsack(items, n, W);
    cout << "Maximum profit in knapsack = " << maxProfit << endl;

    return 0;
}
