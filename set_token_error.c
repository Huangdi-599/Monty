#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int token_length = 0, i = 0;
	char *exit_str = NULL;
	char **new_token = NULL;

	token_length = token_arr_len();
	new_token = malloc(sizeof(char *) * (token_length + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < token_length)
	{
		new_token[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_token);
		malloc_error();
		return;
	}
	new_token[i++] = exit_str;
	new_token[i] = NULL;
	free(op_toks);
	op_toks = new_token;
}
