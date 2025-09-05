#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int firstElementToRepeatKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }
    return -1;
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

    cout << firstElementToRepeatKTimes(arr, k) << endl;
    return 0;
}
