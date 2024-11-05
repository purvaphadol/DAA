#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio; // Value to weight ratio

    // Constructor to easily create an item
    Item(int v, int w) : value(v), weight(w) {
        ratio = (double)v / (double)w;
    }
};

// Structure to represent a node in the decision tree
struct Node {
    int level;       // Level of the node in the decision tree
    int profit;      // Profit of the node
    int weight;      // Weight of the node
    double bound;    // Upper bound of maximum profit in subtree
};

// Function to calculate the upper bound
double bound(const Node& node, int n, int W, const vector<Item>& items) {
    if (node.weight >= W) return 0; // If weight exceeds capacity

    double profitBound = node.profit;
    int j = node.level + 1; // Start from the next item
    int totalWeight = node.weight;

    // Add items while we can
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    // If there is still room for the next item, add the fraction
    if (j < n) {
        profitBound += (W - totalWeight) * items[j].ratio; // Add fractional part
    }

    return profitBound;
}

// Comparison function for max-heap (priority queue)
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.bound < b.bound; // Max-heap based on bound
    }
};

// Function to solve the knapsack problem using branch and bound
int knapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio; // Sort items by value-to-weight ratio
    });

    priority_queue<Node, vector<Node>, Compare> pq;
    Node root;
    root.level = -1; // Start with level -1
    root.profit = 0; // Initial profit
    root.weight = 0; // Initial weight
    root.bound = bound(root, items.size(), W, items); // Calculate bound for root node

    pq.push(root); // Push root into the queue

    int maxProfit = 0;

    while (!pq.empty()) {
        Node current = pq.top(); // Get the node with max bound
        pq.pop();

        // If we reach the last level, continue
        if (current.level == items.size() - 1) continue;

        // Move to the next level
        Node next;

        // Include the next item
        next.level = current.level + 1;
        next.weight = current.weight + items[next.level].weight;
        next.profit = current.profit + items[next.level].value;
        next.bound = bound(next, items.size(), W, items);

        // If the new weight is within limits and profit is greater than maxProfit, update maxProfit
        if (next.weight <= W && next.profit > maxProfit) {
            maxProfit = next.profit;
        }

        // Only add to the queue if the bound is greater than maxProfit
        if (next.bound > maxProfit) {
            pq.push(next);
        }

        // Exclude the next item
        next.weight = current.weight; // Keep weight same as current
        next.profit = current.profit; // Keep profit same as current
        next.bound = bound(next, items.size(), W, items); // Update bound

        // Add to the queue only if the bound is greater than maxProfit
        if (next.bound > maxProfit) {
            pq.push(next);
        }
    }

    return maxProfit;
}

int main() {
    int W; // Maximum capacity of the knapsack
    int n; // Number of items

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Enter value and weight for item " << (i + 1) << ": ";
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    int maxProfit = knapsack(W, items);
    cout << "Maximum profit in the knapsack: " << maxProfit << endl;

    return 0;
}
