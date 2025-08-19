#include <bits/stdc++.h>
using namespace std;

// function to search leaders in an array
vector<int> SearchLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;

    int maxFromRight = arr[n - 1];  // last element is  a leader
    leaders.push_back(maxFromRight);

    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }

    
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    // Example 
    vector<vector<int>> testCases = {
        {16, 17, 4, 3, 5, 2},
        {1, 2, 3, 4, 0},
        {7, 10, 4, 10, 6, 5, 2},
        {5},
        {100, 50, 20, 10},
        {1, 2, 3, 1000000}
    };

    for (auto arr : testCases) {
        vector<int> leaders = SearchLeaders(arr);
        cout << "Leaders: ";
        for (int num : leaders) cout << num << " ";
        cout << endl;
    }

    return 0;
}
