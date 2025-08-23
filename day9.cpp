#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }    
    if (strs.size() == 1) {
        return strs[0];
    }
     
    string shortest = *min_element(strs.begin(), strs.end(), 
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });
    
    string prefix = "";
    for (int i = 0; i < shortest.length(); i++) {
        char current_char = strs[0][i];
        for (const string& s : strs) {
            if (s[i] != current_char) {
                return prefix;
            }
        }
        prefix += current_char;
    }
    
    return prefix;
}
int main() {
    vector<string> strs;
    string input;   
    
    getline(cin, input); 
    
    string cleaned;
    for (char c : input) {
        if (c != '[' && c != ']' && c != '"' && c != ' ' && c != '\'') {
            cleaned += c;
        }
    }    
    stringstream ss(cleaned);
    string token;
    while (getline(ss, token, ',')) {
        strs.push_back(token);
    }    
    string result = longestCommonPrefix(strs);

    cout << "\"" << result << "\"" << endl;    
    return 0;
}
