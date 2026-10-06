
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class InfixConversion {
    string infix;

    int precedence(char op) {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || 
                ch == '*' || ch == '/' || ch == '^');
    }

public:

    void input() {
        cout << "Enter infix expression: ";
        cin >> infix;
    }

    string toPostfix(string exp) {
        stack<char> st;
        string postfix = "";

        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];

            // Operand
            if (isalnum(ch)) {
                postfix += ch;
            }

            // Opening bracket
            else if (ch == '(') {
                st.push(ch);
            }

            // Closing bracket
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }

            // Operator
            else if (isOperator(ch)) {
                while (!st.empty() &&
                       st.top() != '(' &&
                       precedence(st.top()) >= precedence(ch)) {
                    postfix += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        // Empty remaining operators
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }

    string toPrefix() {
        string exp = infix;

        // Reverse expression
        reverse(exp.begin(), exp.end());

        // Swap brackets
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '(')
                exp[i] = ')';
            else if (exp[i] == ')')
                exp[i] = '(';
        }

        // Convert reversed expression to postfix
        string postfix = toPostfix(exp);

        // Reverse postfix to get prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }

    void display() {
        cout << "Postfix: " << toPostfix(infix) << endl;
        cout << "Prefix : " << toPrefix() << endl;
    }
};

int main() {
    InfixConversion obj;

    obj.input();
    obj.display();

    return 0;
}
