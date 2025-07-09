#include "include/parser.h"
#include <stdio.h>


parser_T* init_parser(lexer_T* lexer){
	parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
	parser->lexer = lexer;
	parser->current_token = lexer_get_next_token(lexer);

	return parser;
}


void parser_eat(parser_T* parser, int token_type){
	if (parser->current_token->type == token_type)
	{
		parser->current_token = lexer_get_next_token(parser->lexer);
	}else{
		printf(
			"Unexpected token %s , with type %d",
			parser->current_token->value,
			parser->current_token->type
			);
		exit(1);
	}
}

AST_T* parser_parse(parser_T* parser){
	return parser_parse_statments(parser);
}

AST_T* parser_parse_statment(parser_T* parser){
	switch(parser->current_token->type){
		case TOKEN_ID: return parser_parse_id(parser);
	}
}

AST_T* parser_parse_statments(parser_T* parser){
	AST_T* compound = init_ast(AST_COMPOUND);

	compound->compound_value = calloc(1,sizeof(struct AST_STRUCT*));

	AST_T* ast_statment = parser_parse_statment(parser);
	compound->compound_value[0] = ast_statment;
	compound->compound_size +=1;
	
	while(parser->current_token->type == TOKEN_SEMI){
		parser_eat(parser, TOKEN_SEMI);
		AST_T* ast_statment = parser_parse_statment(parser);
		compound->compound_size +=1;
		compound->compound_value = realloc(
			compound->compound_value,
			compound->compound_size * sizeof(struct AST_STRUCT*)
		);

		compound->compound_value[compound->compound_size-1] = ast_statment;
	}
	
	return compound;
}

AST_T* parser_parse_expr(parser_T* parser);

AST_T* parser_parse_factor(parser_T* parser);

AST_T* parser_parse_term(parser_T* parser);

AST_T* parser_parse_function_call(parser_T* parser);

AST_T* parser_parse_function_definition(parser_T* parser){
	parser_eat(parser, TOKEN_ID);
	char* variable_definition_variable_name = parser->current_token->value;
	parser_eat(parser, TOKEN_ID);
	parser_eat(parser, TOKEN_EQUALS);
	AST_T* variable_definition_variable_name = parser_parse_expr(parser);

	AST_T* variable_definition = init_ast(AST_VARIABLE_DEFINITION);
	variable_definition->variable_definition_variable_name = variable_definition_variable_name;
	variable_definition->variable_value = variable_value;

	return variable_definition;
}

AST_T* parser_parse_variable(parser_T* parser);

AST_T* parser_parse_string(parser_T* parser);


AST_T* parser_parse_id(parser_T* parser){
	if (strcmp(parser->current_token->type, "var") == 0){
		return parser_parse_variable_definition(parser);
	}else{
		return parser_parse_variable(parser);
	}	
}
