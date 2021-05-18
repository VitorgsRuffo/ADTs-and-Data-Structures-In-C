#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

//time complexity: O(n) (time taken is proportional to number of characters in the input string)
//space complexity: O(n) (extra memory is proportional to number of characters in the input string. That's because we push all characters to the stack.)
void reverse(char* string, int length){
   
    stack<char> s;

    for(int i = 0; i<length; i++) //time: O(n)   
        s.push(string[i]); //time: O(1)

    for(int i = 0; i<length; i++){ //time: O(n) 
        string[i] = s.top();//time: O(1)
        s.pop();
    }
}

int main(){
    char string[101];
    printf("Reverse string.\nEnter a string: ");
    scanf("%s", string);
    reverse(string, strlen(string));
    printf("Result: %s\n\n", string);
    return 0;
}

//Obs: there are better ways to do the reversing.