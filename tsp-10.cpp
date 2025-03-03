#include <bits/stdc++.h>
using namespace std;


// Function to calculate the distance between two points (cities)
double distance(pair<int, int> city1, pair<int, int> city2) {
    return sqrt(pow(city2.first - city1.first, 2) + pow(city2.second - city1.second, 2));
}

// Function to implement TSP using Greedy approach
void greedyTSP(vector<pair<int, int>> cities) {
    int n = cities.size();
    vector<bool> visited(n, false); // Keep track of visited cities
    visited[0] = true; // Start from the first city (index 0)
    double totalDistance = 0.0; // Total distance traveled
    int currentCity = 0;

    // Iterate to visit all cities
    for (int i = 1; i < n; ++i) {
        double minDist = INT_MAX;
        int nextCity = -1;

        // Find the nearest unvisited city
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double dist = distance(cities[currentCity], cities[j]);
                if (dist < minDist) {
                    minDist = dist;
                    nextCity = j;
                }
            }
        }

        // Move to the nearest city
        visited[nextCity] = true;
        totalDistance += minDist;
        currentCity = nextCity;
    }

    // Return to the starting city
    totalDistance += distance(cities[currentCity], cities[0]);

    cout << "Total distance traveled (Greedy TSP): " <<  totalDistance << endl;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<pair<int, int>> cities(n);
    cout << "Enter the coordinates (x, y) of each city:\n";
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    greedyTSP(cities);


    return 0;
}
