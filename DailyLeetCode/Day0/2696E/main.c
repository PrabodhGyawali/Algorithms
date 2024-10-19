#include <stdio.h>
#include <string.h>

// Using stack implementation which is the most elegant
void push(char* s, int* top, char c) {
    *(s + *top) = c;
}

int pop(char* s, int* top) {
    return s[(*top)--];
}

int minLength(char* s) {
    // Initialize a stack of strings
    char s_list[100];
    int top = -1;
    int s_len = strlen(s);


    
    return s_len;
}

int main(void) {
    char* s = "string1";
    int length = minLength(s);
    printf("%d\n", length);

    return 1;
}