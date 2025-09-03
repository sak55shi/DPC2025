#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

void insertSorted(stack<int> &s, int element) {
    if (s.empty() || s.top() >= element) {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(temp);
}

void sortStack(stack<int> &s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        sortStack(s);
        insertSorted(s, temp);
    }
}

int main() {
    string input;
    cout << "Enter the stack elements: ";
    getline(cin, input);

    vector<int> elements;
    if (input.front() == '[' && input.back() == ']') {
     
        input = input.substr(1, input.size() - 2);
  
        stringstream ss(input);
        string token;
        while (getline(ss, token, ',')) {
            
            token.erase(0, token.find_first_not_of(" "));
            token.erase(token.find_last_not_of(" ") + 1);
            if (!token.empty()) {
                elements.push_back(stoi(token));
            }
        }
    } else {
        
        stringstream ss(input);
        string token;
        while (ss >> token) {
            elements.push_back(stoi(token));
        }
    }

    
    stack<int> s;
    for (int i = 0; i < elements.size(); i++) {
        s.push(elements[i]);
    }

 
    sortStack(s);

    
    cout << "Sorted stack : [";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
