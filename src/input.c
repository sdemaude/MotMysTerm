#include "../include/include.h"

// Check if the input is the word to find
bool	is_to_find(t_data *data) {
	if (!strcmp(data->word.word, data->last_input))
		return (true);
	return (false);
}

// Check if the input is in the dictionary
bool	is_in_dict(t_data *data, char *input) {
	t_list_str	*tmp;

	tmp = data->dictionary;
	while (tmp)	{
		if (!strcmp(tmp->line, input))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

// Print wrong input message
static void	print_incorrect_input(t_data *data, t_incorrect_input err_msg) {
	if (err_msg == ONLY_LETTER)
		printf(ERR_ONLY_LETTER);
	else if (err_msg == NUMBER_LETTER)
		printf(ERR_NUMBER_LETTER);
	else if (err_msg == IN_DICTIONARY)
		printf(ERR_IN_DICTIONARY);
	else if (err_msg == FIRST_LETTER)
		printf(ERR_FIRST_LETTER, data->word.word[0]);
}

bool	is_input_correct(t_data *data) {
	if (!data->last_input)
		return (false);
	for (int i = 0; data->last_input[i]; i++) {
		if (!ft_isalpha(data->last_input[i]))
			return (print_incorrect_input(data, ONLY_LETTER), false);
		data->last_input[i] = toupper(data->last_input[i]);
	}
	if ((int)ft_strlen(data->last_input) != data->word.nb_letter)
		return (print_incorrect_input(data, NUMBER_LETTER), false);
	if (!is_in_dict(data, data->last_input))
		return (print_incorrect_input(data, IN_DICTIONARY), false);
	if (data->last_input[0] != data->word.word[0])
		return (print_incorrect_input(data, FIRST_LETTER), false);

	return (true);
}