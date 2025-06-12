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

Lexer lexer(char *input_str, int position, Token current_token){
    int index = 0;
    switch (input_str[index])
    {
    case ' ':
        continue;
    case '(':
        current_node =  pack_single_node(input_str[index], (index + 1), TOKEN_LPAREN, &input_str[index+1]);
    case ')':
        current_node =  pack_single_node(input_str[index], (index + 1), TOKEN_RPAREN &input_str[index+1]);
    case '+':
        current_node = pack_single_node(input_str[index], (index + 1), TOKEN_PLUS);
    case '-':
        current_node = pack_single_node(input_str[index], (index + 1), TOKEN_MINUS);
    case '*':
        current_node = pack_single_node(input_str[index], (index + 1), TOKEN_MULTIPLICATION);
    }
}

Lexer pack_single_node(char input, int position, Token current_token){
    Lexer node;
    node.input = input;
    node.position = index + 1;
    node.current_token = current_token;
    return node;
}

void lexer_with_nested_mul(NestedLexer new_node, const char *input_str, int index){
    int start_index = index;
    StrSlice *substring;
    substring->string_to_slice = input_str;
    while (input_str[index])
    {   if(start_index == 0){
            substring->left_index_inclusive = start_index;
        }
        switch (input_str[index]) {
            case ' ':
                continue;
            case '(':
                pack_lexer(substring, new_node, TOKEN_LPAREN, 1, index, input_str);
            case ')':
                pack_lexer(substring, new_node, TOKEN_RPAREN, 1, index, input_str);
            case '+':
                pack_lexer(substring, new_node, TOKEN_PLUS, 0, index, input_str);
            case '-':
                pack_lexer(substring, new_node, TOKEN_MINUS, 1, index, input_str);
            case '*':
                pack_lexer(substring, new_node, TOKEN_MULTIPLICATION, 0, index, input_str);
            case '\0':
                substring->right_index_exclusive = index;
                new_node.prev = *substring;
                return new_node;
            }
        index++;
    }
}

NestedLexer pack_lexer(StrSlice *substring, NestedLexer new_node, int token_type, int order_matters, int index, const char *input_str)
{
    substring->right_index_exclusive = index;
    new_node.prev = *substring;
    Token new_token;
    new_token.type = token_type;
    Operator new_operator;
    new_operator.operator = new_token;
    int operator_priority = priority(input_str[index]);
    new_operator.order_matters = order_matters;
    new_operator.priority = operator_priority;
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
