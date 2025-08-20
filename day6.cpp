#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

vector<int> parseArray(const string& line) {
    vector<int> arr;
    string processed = line;
    
    processed.erase(remove(processed.begin(), processed.end(), '['), processed.end());
    processed.erase(remove(processed.begin(), processed.end(), ']'), processed.end());
    
    replace(processed.begin(), processed.end(), ',', ' ');
    
    istringstream iss(processed);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }
    return arr;
}

vector<pair<int, int>> findSubarraysWithZeroSum(const vector<int>& arr) {
    unordered_map<long long, vector<int>> prefixMap;
    prefixMap[0].push_back(-1);
    long long prefixSum = 0;
    vector<pair<int, int>> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int idx : prefixMap[prefixSum]) {
                result.push_back({idx + 1, i});
            }
        }
        prefixMap[prefixSum].push_back(i);
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<int> arr = parseArray(line);
        vector<pair<int, int>> result = findSubarraysWithZeroSum(arr);
        
        cout << "[";
        for (size_t i = 0; i < result.size(); i++) {
            cout << "(" << result[i].first << ", " << result[i].second << ")";
            if (i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
