/*
* Problem: evaluate expressions. 
* Expressions written in prefix or postfix notation are easier to interpret by computer algorithms than those written in infix notation. 
* 
* Examples of expressions:
* Infix:   A + 2,   1 * 4,   (3 + 1) * 4
* Prefix:  + A 2,   * 1 4,   * + 3 1 4 
* Postfix: A 2 +,   1 4 *,   3 1 + 4 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;

double performOperation(double operand1, double operand2, char op){
         if(op == '+') return operand1 + operand2;
    else if(op == '-') return operand1 - operand2;
    else if(op == '/') return operand1 / operand2;
    else if(op == '*') return operand1 * operand2;
    else return -999;
}

int isOperator(char character){
    if(character == '+' || character == '-' || character == '/' || character == '*' ) return 1;
    else return 0;
}

//Obs1: this function assumes that the expression is correctly written thus it does not handle syntax errors.
//Obs2: In order to evaluate a prefix expression the logic is basically the same. We just have to scan the expression from right to left.
double evaluatePostfixExpression(char* expression, int length){
    stack<double> s;
    int operandIndex = 0;
    double operand, operand2, result;

    for(int i = 0; i<length; i++){
        
        if(!isOperator(expression[i])){
            
            if(expression[i] == ' '){
                
                expression[i] = '\0';
                operand = atof(&expression[operandIndex]);
                s.push(operand);
                expression[i] = ' ';
                operandIndex = i+1;

            }else continue;

        }else{

            operand2 = s.top(); s.pop();
            operand = s.top(); s.pop();
            result = performOperation(operand, operand2, expression[i]);
            s.push(result);
            operandIndex = i + 2;
            i++;
        }
    }

    return s.top();
}

int main(){
    char expression[101];
    printf("Evaluating a postfix expression.\nEnter an expression:\n");
    fgets(expression, 101, stdin);
    printf("\n\nExpression value: %.2lf.\n\n" , evaluatePostfixExpression(expression, strlen(expression)));
    return 0;
}

