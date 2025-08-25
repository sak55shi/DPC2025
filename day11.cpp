#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(string& s, vector<bool>& visited, string& current, vector<string>& result) {
    if (current.length() == s.length()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        if (visited[i]) continue;
        if (i > 0 && s[i] == s[i-1] && !visited[i-1]) continue;
        visited[i] = true;
        current.push_back(s[i]);
        backtrack(s, visited, current, result);
        current.pop_back();
        visited[i] = false;
    }
}
vector<string> permute(string s) {
    sort(s.begin(), s.end());
    vector<string> result;
    string current;
    vector<bool> visited(s.length(), false);
    backtrack(s, visited, current, result);
    return result;
}
int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    s.erase(remove(s.begin(), s.end(), '\''), s.end());
    
    vector<string> permutations = permute(s);
    cout << "[";
    for (size_t i = 0; i < permutations.size(); i++) {
        cout << "\"" << permutations[i] << "\"";
        if (i < permutations.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
