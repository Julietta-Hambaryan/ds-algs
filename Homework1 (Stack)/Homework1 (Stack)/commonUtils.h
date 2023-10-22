#pragma once

/* assume that only '+', '-', '*', '/' operators will be provided*/
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

/*
* Giving priorities to opeations as follows.
* '+' or '-' -> priority = 1
* '*' or '/' -> priority = 2
* '^' (power) -> priority = 3 
*/
int getPriority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
