#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void insertAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(temp);
}

void reverseStack(stack<int> &s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, temp);
    }
}

int main() {
    string input;
    cout << "Enter the stack elements: ";
    getline(cin, input);

    vector<int> elements;
    stringstream ss(input);
    string token;
    while (ss >> token) {
        elements.push_back(stoi(token));
    }

    stack<int> s;
    for (int i = 0; i < elements.size(); i++) {
        s.push(elements[i]);
    }

    reverseStack(s);

    cout << "Reversed stack (top to bottom): [";
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
