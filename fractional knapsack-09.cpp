#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and corresponding value
struct Item {
    int weight, value;
};

// Comparison function to sort items according to value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get the maximum value in the knapsack
void fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sorting items by value/weight ratio in descending order
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0; // Maximum value in the knapsack

    for (auto item : items) {
        if (capacity >= item.weight) {
            // Take the whole item
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of the item
            totalValue += item.value * ((double)capacity / item.weight);
            break; // Knapsack is full
        }
    }

    cout<<totalValue<<endl;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;
 fractionalKnapsack(capacity, items);
  //  cout << "Maximum value in Knapsack = " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}

