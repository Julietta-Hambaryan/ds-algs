#pragma once
#include <iostream>
#include <string>
#include "arrayStack.h"
#include "commonUtils.h"


/*
* infix to postfix converion using stack implemenataion with array
*/
std::string infixToPostfix(const std::string& infix) {
    ArrayStack<char> operatorStack;
    std::string postfix;

    for (char c : infix) {
        if (isdigit(c)) {  
            postfix += c;
        }
        else if (isOperator(c)) { 
            while (!operatorStack.isEmpty() && getPriority(operatorStack.top()) >= getPriority(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else {
            throw std::invalid_argument("Unexpected character");
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

