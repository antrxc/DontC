#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structs.h"

TokenLiteral generate_number(char current, FILE *file){
    TokenLiteral *token;
    token->type = INT;
    int value= 0;
    while (isdigit(current) && current != EOF)
    {
        if (!isdigit(current))
        {
            break;
        }
        value = value *10 + (int) (current - '0');
        current = fgetc(file);
    }    
    token->value=value;
    return (*token);
}




void Lexer(FILE *file){
    char current =  fgetc(file);

    while (current != EOF)
    {
        if (current==';')
        {
            printf("FOUND SEMICOLON\n");
        }
        else if (current=='(')
        {
            printf("OPEN VENDOR\n");
        }
        else if (current==')')
        {
            printf("CLOSE PARE\n");
        }
        
        else if (isdigit(current))
        {
            TokenLiteral *test_token = generate_number(current,file); 
            printf("TEST TOKEN VALUE: %d \n", test_token->value);
        }
        else if (isalpha(current))
        {
            printf("character: %c\n",current );
        }
        
        current=fgetc(file);
    }

}
int main(){
    FILE *file;
    file = fopen("test.dc", "r");
    Lexer(file);
}