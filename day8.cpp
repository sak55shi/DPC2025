#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    bool hasQuotes = false;
        if (!s.empty() && s.front() == '"' && s.back() == '"') {
        hasQuotes = true;
        s = s.substr(1, s.size() - 2);
    }
    
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string result;
    for (size_t i = 0; i < words.size(); i++) {
        if (i != 0) result += " ";
        result += words[i];
    }
    
    if (hasQuotes) {
        result = "\"" + result + "\"";
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}
