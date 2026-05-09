#include <iostream>
#include <string>
using namespace std;

bool can(int l, string &s, int k) {
    int n = s.length();
    int operations = 0;

    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            operations++;   
            i += l;  
        } else {
            i++;
        }
    }

    return operations <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int low = 1, high = n;
    int answer = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (can(mid, s, k)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}
