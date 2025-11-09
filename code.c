#include <stdio.h>

/*
    This program tests the lexical analyzer.
    It includes:
    -Keywords
    -Identifiers
    -Literals (int, float, char, string)
    -Operators and separators
    -Single-line and multi-line comments
*/

int main() {
    //Variable Declarations
    int a = 10;
    float b = 3.14;
    char c = 'x';
    char *str = "Hello World!";

    //Arithmetic Operations
    a = a + 5 * (b - 2);

    //Conditional Statement
    if (a > 20) {
        printf("%s\n", str);
    } else {
        printf("Value is small.\n");
    }

    //Return Statement
    return 0;
}
