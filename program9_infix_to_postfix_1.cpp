/*
 * Program 9: Infix to Postfix Conversion
 * Objective: Convert "(A+B)*C-D" into a postfix expression using stack operations
 *            and display the equivalent postfix expression.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

#define MAX_SIZE 100

// Stack implementation for characters
class CharStack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    CharStack() {
        top = -1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() const {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }

    string getStackContent() const {
        if (isEmpty()) return "(empty)";
        string s = "";
        for (int i = 0; i <= top; i++) {
            s += arr[i];
        }
        return s;
    }
};

// Function to return operator precedence
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // For '(' and others
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix with step-by-step demonstration
string infixToPostfix(const string& infix, bool showTrace = true) {
    CharStack st;
    string postfix = "";

    if (showTrace) {
        cout << "\n" << string(65, '-') << "\n";
        cout << left << setw(10) << "Symbol" 
             << setw(25) << "Stack (Bottom->Top)" 
             << setw(30) << "Postfix Expression" << "\n";
        cout << string(65, '-') << "\n";
    }

    for (size_t i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Skip whitespace
        if (isspace(ch)) continue;

        // If operand (alphanumeric), append to postfix expression
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If left parenthesis '(', push onto stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If right parenthesis ')', pop and output until '(' is met
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(') {
                st.pop(); // Remove '(' from stack
            }
        }
        // If operator
        else if (isOperator(ch)) {
            while (!st.isEmpty() && st.peek() != '(' &&
                   getPrecedence(st.peek()) >= getPrecedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }

        if (showTrace) {
            cout << left << setw(10) << ch 
                 << setw(25) << st.getStackContent() 
                 << setw(30) << postfix << "\n";
        }
    }

    // Pop all remaining operators in the stack
    while (!st.isEmpty()) {
        char popped = st.pop();
        if (popped != '(') {
            postfix += popped;
        }
        if (showTrace) {
            cout << left << setw(10) << "[End]" 
                 << setw(25) << st.getStackContent() 
                 << setw(30) << postfix << "\n";
        }
    }

    if (showTrace) {
        cout << string(65, '-') << "\n";
    }

    return postfix;
}

int main() {
    cout << "=== Infix to Postfix Conversion using Stack ===\n";

    string targetExpr = "(A+B)*C-D";
    cout << "Target Expression given: " << targetExpr << "\n";

    cout << "\nConverting the target expression step-by-step:\n";
    string result = infixToPostfix(targetExpr, true);

    cout << "\n============================================\n";
    cout << "Infix Expression   : " << targetExpr << "\n";
    cout << "Postfix Expression : " << result << "\n";
    cout << "============================================\n";

    // Option to enter a custom expression
    cout << "\nWould you like to test another expression? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cin.ignore();
        string userExpr;
        cout << "Enter Infix Expression: ";
        getline(cin, userExpr);
        string userPostfix = infixToPostfix(userExpr, true);
        cout << "\nInfix Expression   : " << userExpr << "\n";
        cout << "Postfix Expression : " << userPostfix << "\n";
    }

    return 0;
}

