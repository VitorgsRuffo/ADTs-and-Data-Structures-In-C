/* 
* Problem:  Check if brackets (e.g, (), [], {}) in an expression are balanced. That is, for each opening bracket exist, after it, a closing one of the same type (a bracket can only close when all brackets opened after it are closed). 
* Examples: (A + B)               ->     balanced.
            (A  * [B - 1])        ->     balanced.
            (A + B - (C / 2 + 4)] -> not balanced.
     
     
            )A + B(               -> not balanced.  (because the closing one is not after the opening one)
            [A + B * (C])         -> not balanced.  (because a bracket can only close when all brackets opened after it are closed. Last unclosed should be first closed.)


*/

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int isExpressionBracketsBalanced(char* expression, int length){
    
    stack<char> s;
    
    for(int i = 0; i<length; i++){
        if(expression[i] == '(' || expression[i] == '['|| expression[i] == '{')
            s.push(expression[i]);

        else if(expression[i] == ')' || expression[i] == ']'|| expression[i] == '}'){
            
            if(s.empty()) //there isn't a corresponding opening bracket.
                return 0;
            
            /* ASCII codes:
            *  ( - 40; ) - 41; [ -  91; ] - 93; { - 123; } - 125.
            * So, when we subtract a pair of corresponding brackets (e.g, '(' - ')') the result should be 1 or 2, nothing more, nothing less.
            */
            int result = (int) expression[i] - (int) s.top();
            if(result < 1 || result > 2) //the last opened bracket doesn't match the just read closing bracket.
                return 0;
            
            s.pop();
        }

    }
    
    return s.empty()?1:0; //if stack is not empty some opened brackets were not closed.
}

int main(){
    char expression[101];
    printf("Check if an expression is balanced.\nEnter an expression containing brackets (e.g, (), [], {}):\n");
    fgets(expression, 101, stdin);
    printf("\n\nExpression is %sbalanced.\n\n" , isExpressionBracketsBalanced(expression, strlen(expression))?"":"not ");
    return 0;
}