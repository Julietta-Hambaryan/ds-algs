#include <iostream>
#include "arrayStack.h"
#include "linkedListStack.h"
#include "infixToPostfixConverter.h"
#include "postfixExpCalculation.h"

int main() {
    std::string infixExpression = "2+3*8*(5+4^2+3*7)";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Postfix: " << postfixExpression << std::endl;

    int result = evaluatePostfix(postfixExpression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
