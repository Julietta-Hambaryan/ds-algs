#include <iostream>
#include <string>
#include "linkedListStack.h"
#include "commonUtils.h"

int calculate(int operand1, int operand2, char op) {
    switch (op) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 != 0) return operand1 / operand2;
        else {
            std::cerr << "Division by zero." << std::endl;
            exit(1);
        }
    case '^': return std::pow(operand1, operand2);
    default:
        std::cerr << "Invalid operator: " << op << std::endl;
        exit(1);
    }
}

/*
* postfix expertion evaluation using stack implemenation with linked list
*/
int evaluatePostfix(const std::string& postfix) {
    LinkedListStack<int> operandStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0');  // Convert character to integer
        }
        else if (isOperator(c)) {
            if (operandStack.isEmpty()) {
                std::cerr << "Invalid postfix expression." << std::endl;
                exit(1);
            }
            int operand2 = operandStack.pop();
            if (operandStack.isEmpty()) {
                std::cerr << "Invalid postfix expression." << std::endl;
                exit(1);
            }
            int operand1 = operandStack.pop();
            int result = calculate(operand1, operand2, c);
            operandStack.push(result);
        }
    }

    int result = operandStack.pop();

    if (!operandStack.isEmpty()) {
        std::cerr << "Invalid postfix expression." << std::endl;
        exit(1);
    }
   
    return result;
}

