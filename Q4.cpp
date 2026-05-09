#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Solves the Too Chocolatey game logic.
 * Returns "Alex" if Alex wins, otherwise returns "Bob".
 */
string solve(int n, vector<int> arr) {
    // Sort chocolates in descending order so players pick the largest piles first
    sort(arr.begin(), arr.end(), greater<int>());

    long long alexTotal = 0;
    long long bobTotal = 0;

    set<int> alexEaten;
    set<int> bobEaten;

    // True if it's Alex's turn, False if it's Bob's turn
    bool alexTurn = true;

    for (int i = 0; i < n; i++) {
        int currentQuantity = arr[i];

        if (alexTurn) {
            // Alex tries to eat the chocolate
            if (alexEaten.find(currentQuantity) == alexEaten.end()) {
                alexTotal += currentQuantity;
                alexEaten.insert(currentQuantity);
            }
            // Move turn to Bob regardless of whether Alex could eat this specific pile
            alexTurn = false;
        } else {
            // Bob tries to eat the chocolate
            if (bobEaten.find(currentQuantity) == bobEaten.end()) {
                bobTotal += currentQuantity;
                bobEaten.insert(currentQuantity);
            }
            // Move turn back to Alex
            alexTurn = true;
        }
    }

    // Alex wins only if he has strictly more chocolates than Bob
    if (alexTotal > bobTotal) {
        return "Alex";
    } else {
        return "Bob";
    }
}

int main() {
    // Optimize I/O operations
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(n, arr) << "\n";
    }

    return 0;
}
