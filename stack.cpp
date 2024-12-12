#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cmath> // For pow
using namespace std;

// Stack structure for operators (used in conversion)
struct stack1 {
    char data;
    stack1* next;
} *top = NULL;

// Stack structure for operands (used in evaluation)
struct stack2 {
    int data;
    stack2* next;
} *top1 = NULL;

// Function prototypes
int precedence(char op);
void evalPostfix(string postfix);

// Function to get operator precedence
int precedence(char op) {
    if (op == '^') return 3; // Highest precedence
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // For non-operators
}

// Function to convert infix to postfix
void infixToPostfix(char infix[30]) {
    stack1 *newnode, *temp;
    string postfix;           // To store the postfix expression
    int i = 0, l;

    // Add an opening '(' at the start and a closing ')' at the end
    newnode = new stack1;
    newnode->data = '(';
    newnode->next = top;
    top = newnode;

    l = strlen(infix);
    infix[l] = ')';

    while (top != NULL) {
        if (infix[i] == '(') {
            newnode = new stack1;
            newnode->data = '(';
            newnode->next = top;
            top = newnode;
        } else if (strchr("+-*/^", infix[i])) {
            // Process operators and handle precedence
            while (precedence(top->data) >= precedence(infix[i])) {
                postfix += top->data;
                temp = top;
                top = top->next;
                delete temp;
            }
            newnode = new stack1;
            newnode->data = infix[i];
            newnode->next = top;
            top = newnode;
        } else if (infix[i] == ')') {
            // Pop until '(' is encountered
            while (top->data != '(') {
                postfix += top->data;
                temp = top;
                top = top->next;
                delete temp;
            }
            temp = top;
            top = top->next; // Pop the '('
            delete temp;
        } else {
            // Append operands directly to postfix expression
            postfix += infix[i];
        }

        i++;
    }

    cout << "=========================================================\n";
    cout << "Postfix expression is: " << postfix;
    cout << "\n=========================================================\n";

    // Evaluate the postfix expression
    evalPostfix(postfix);
}

// Function to evaluate a postfix expression
void evalPostfix(string postfix) {
    stack2 *newnode, *temp;
    int a, b, c;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            // Push operands onto the stack
            newnode = new stack2;
            newnode->data = ch - '0'; // Convert char to int
            newnode->next = top1;
            top1 = newnode;
        } else {
            // Pop two operands for the operator
            a = top1->data;
            temp = top1;
            top1 = top1->next;
            delete temp;

            b = top1->data;
            temp = top1;
            top1 = top1->next;
            delete temp;

            // Perform the operation
            switch (ch) {
                case '+': c = b + a; break;
                case '-': c = b - a; break;
                case '*': c = b * a; break;
                case '/': c = b / a; break;
                case '^': c = pow(b, a); break;
            }

            // Push the result back onto the stack
            newnode = new stack2;
            newnode->data = c;
            newnode->next = top1;
            top1 = newnode;
        }
    }

    cout << "\nValue of postfix expression is: " << top1->data;
    cout << "\n=========================================================\n";
}

int main() {
    char infix[30];
    int ch;
    do {
        cout << "\nChoose the operation:";
        cout << "\n1. Convert infix to postfix and evaluate";
        cout << "\n2. Exit\n";
        cout << "=========================================================\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                infixToPostfix(infix);
                break;
        }
    } while (ch != 2);

    return 0;
}
