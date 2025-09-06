#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter array: ";
    getline(cin, input);
    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<int> arr;
    if (input.front() == '[' && input.back() == ']') {
        input = input.substr(1, input.size() - 2);
        stringstream ss(input);
        string token;
        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" "));
            token.erase(token.find_last_not_of(" ") + 1);
            if (!token.empty()) {
                arr.push_back(stoi(token));
            }
        }
    } else {
        stringstream ss(input);
        string token;
        while (ss >> token) {
            arr.push_back(stoi(token));
        }
    }

    vector<int> result = maxSlidingWindow(arr, k);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
