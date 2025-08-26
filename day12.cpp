#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    if (s.length() % 2 != 0) return false; 
    stack<char> st;
    unordered_map<char, char> mapping = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != mapping[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    getline(cin, s);

    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
        s = s.substr(1, s.size() - 2);
    }

    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
