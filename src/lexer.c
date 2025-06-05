#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"

void lexer_init(Lexer *lexer, const char *input) {
    lexer->input = input;
    lexer->position = 0;
    lexer_next_token(lexer);
}

static void skip_whitespace(Lexer *lexer) {
    while (lexer->input[lexer->position] && isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }
}

static int read_number(Lexer *lexer) {
    int value = 0;
    while (isdigit(lexer->input[lexer->position])) {
        value = value * 10 + (lexer->input[lexer->position] - '0');
        lexer->position++;
    }
    return value;
}

void lexer_with_nested_mul(NestedLexer new_node, const char *input_str, int index){
    int start_index = index;
    StrSlice *substring;
    substring->input_str;
    while (input_str[index])
    {   if(start_index == 0){
            substring->left_index_inclusive = start_index;
        }
        switch (input_str[index]) {
            case ' ':
                continue;
            case '(':
                substring->right_index_exclusive = index;
                new_node.prev = *substring;
                Operator new_lparen;
                new_lparen.operator = TOKEN_LPAREN;
                int operator_priority = priority(input_str[index]);
                new_lparen.priority = operator_priority;
            case ')':
                substring->right_index_exclusive = index;
                new_node.prev = *substring;
                Operator new_rparen;
                new_rparen.operator = TOKEN_RPAREN;
                int operator_priority = priority(input_str[index]);
                new_rparen.priority = operator_priority;
            case '\0':
                substring->right_index_exclusive = index;
                new_node.prev = *substring;
                new_node.operator = '\0'
                new_node.next = '\0'
                return new_node;
            }
        index++;
    }
}

void lexer_next_token(Lexer lexer, const char *input_str) {
    if (lexer.to_the_left_left_index){
        for (int i = lexer.to_the_left_left_index; i <= lexer.to_the_left_right_end_index, i++)
        {
            new_operation.right_left_index = lexer.to_the_left_left_index;
            switch (input_str[i])
            {
            case '+':
                lexer.new_operation.right_right_index = lexer.to_the_left_left_index;
                lexer->current_token.type = TOKEN_PLUS;
                lexer->position++;
                break;
            case '(':
                lexer->current_token.type = TOKEN_LPAREN;
                lexer->position++;
                break;
            case ')':
                lexer->current_token.type = TOKEN_RPAREN;
                lexer->position++;
                break;
            case '*':
                lexer->current_token.type = TOKEN_MULTIPLICATION;
                lexer->position++;
            default:
                lexer->current_token.type = TOKEN_ERROR;
                lexer->position++;
                break;
        }
        }
    }


}

int priority(char operator){
    if (operator == '('){
        int priority = 1;
    }elif(operator == '*'){
        int priority = 3;
    }elif(operator == '+'){
        int priority = 5;
    }elif(operator == 's'){
        int priority = 6;
    }
    if(priority){
        return priority;
    }
}

void token_free(Token *token) {
}
