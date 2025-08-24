#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> parseInput(const string& input) {
    vector<string> strs;
    string cleaned = input;
    
    cleaned.erase(remove(cleaned.begin(), cleaned.end(), '['), cleaned.end());
    cleaned.erase(remove(cleaned.begin(), cleaned.end(), ']'), cleaned.end());
    
    stringstream ss(cleaned);
    string token;
    while (getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(" \""));
        token.erase(token.find_last_not_of(" \"") + 1);
        if (!token.empty()) {
            strs.push_back(token);
        }
    }
    return strs;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for (const auto& pair : groups) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    string input;
     getline(cin, input);
    
    vector<string> strs = parseInput(input);
    vector<vector<string>> result = groupAnagrams(strs);
    
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
