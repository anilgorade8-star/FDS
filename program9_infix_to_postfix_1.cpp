#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string infix = "(A+B)*C-D";

    cout << "Given Infix Expression: " << infix << "\n";
    cout << "Do you want to use this default expression? (y/n): ";
    char ans;
    cin >> ans;
    if (ans == 'n' || ans == 'N') {
        cout << "Enter your infix expression: ";
        cin >> infix;
    }

    char stack[100];
    int top = -1;
    string postfix = "";

    // Convert infix to postfix directly using stack
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Skip spaces
        if (ch == ' ') continue;

        // If operand (alphabet or digit), add directly to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push onto stack
        else if (ch == '(') {
            top++;
            stack[top] = ch;
        }
        // If ')', pop from stack until '('
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += stack[top];
                top--;
            }
            if (top != -1 && stack[top] == '(') {
                top--; // remove '('
            }
        }
        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int currentPrec = 0;
            if (ch == '^') currentPrec = 3;
            else if (ch == '*' || ch == '/') currentPrec = 2;
            else if (ch == '+' || ch == '-') currentPrec = 1;

            while (top != -1 && stack[top] != '(') {
                int topPrec = 0;
                if (stack[top] == '^') topPrec = 3;
                else if (stack[top] == '*' || stack[top] == '/') topPrec = 2;
                else if (stack[top] == '+' || stack[top] == '-') topPrec = 1;

                if (topPrec >= currentPrec) {
                    postfix += stack[top];
                    top--;
                } else {
                    break;
                }
            }
            // Push current operator
            top++;
            stack[top] = ch;
        }
    }

    // Pop remaining operators from stack
    while (top != -1) {
        if (stack[top] != '(') {
            postfix += stack[top];
        }
        top--;
    }

    cout << "\n----------------------------------------\n";
    cout << "Infix Expression   : " << infix << "\n";
    cout << "Postfix Expression : " << postfix << "\n";
    cout << "----------------------------------------\n";

    return 0;
}
