#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,        // +
    TOKEN_LPAREN,      // (
    TOKEN_RPAREN,      // )
    TOKEN_EOF,         // End of input
    TOKEN_MINUS,
    TOKEN_DIVISION,
    TOKEN_MULTIPLICATION,
    TOKEN_MUL,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    union {
        int number;
    } value;
} Token;

typedef struct {
    const char *input;
    int position;
    Token current_token;
} Lexer;

typedef struct {
    Token operator;
    int priority;

} Operatior;

typedef struct
{
    StrSlice *prev;
    Operator operator;
    const char *next;
} NestedLexer;

typedef struct
{
    int left_index_inclusive;
    int right_index_exclusive;
    const char *string_to_slice;

} StrSlice;

void lexer_with_nested_mul();
lexer_init(Lexer *lexer, const char *input);
void lexer_next_token(Lexer *lexer);
void token_free(Token *token);

#endif /* LEXER_H */
