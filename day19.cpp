#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expression) {
   
    if (!expression.empty() && expression.front() == '"') {
        expression.erase(0, 1);
    }
    if (!expression.empty() && expression.back() == '"') {
        expression.pop_back();
    }

    stack<int> st;
    stringstream ss(expression);
    string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            if (token == "+") {
                st.push(operand1 + operand2);
            } else if (token == "-") {
                st.push(operand1 - operand2);
            } else if (token == "*") {
                st.push(operand1 * operand2);
            } else if (token == "/") {
                st.push(operand1 / operand2);
            }
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main() {
    string expression;
    cout << "Enter postfix expression: ";
    getline(cin, expression);
    cout << evaluatePostfix(expression) << endl;
    return 0;
}
