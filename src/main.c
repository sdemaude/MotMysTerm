#include "../include/include.h"

bool	is_to_find(t_data *data)
{
	if (!strcmp(data->word.word, data->last_input))
		return (true);
	return (false);
}

bool	is_in_dict(t_data *data, char *input)
{
	t_list_str	*tmp;

	tmp = data->dictionary;
	while (tmp)
	{
		if (!strcmp(tmp->line, input))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	incorrect_input(t_data *data, t_incorrect_input err_msg)
{
	if (err_msg == ONLY_LETTER)
		printf("must be only letters\n");
	else if (err_msg == NUMBER_LETTER)
		printf("incorrect nb of letter\n");
	else if (err_msg == IN_DICTIONARY)
		printf("not in dictionary\n");
	else if (err_msg == FIRST_LETTER)
		printf("must start by a %c\n", data->word.word[0]);
	return (false);
}

bool	check_input(t_data *data)
{
	if (!data->last_input)
		return (false);
	for (int i = 0; data->last_input[i]; i++)
	{
		if (!ft_isalpha(data->last_input[i]))
			return (incorrect_input(data, ONLY_LETTER));
		data->last_input[i] = toupper(data->last_input[i]);
	}
	if ((int)ft_strlen(data->last_input) != data->word.nb_letter)
		return (incorrect_input(data, NUMBER_LETTER));
	if (!is_in_dict(data, data->last_input))
		return (incorrect_input(data, IN_DICTIONARY));
	if (data->last_input[0] != data->word.word[0])
		return (incorrect_input(data, FIRST_LETTER));
	return (true);
}

void	refill_alpha(t_data *data)
{
	for (int i = 0; i < 26; i++)
		data->word.alpha[i] = 0;
	for (int i = 0; data->word.word[i]; i++)
		data->word.alpha[data->word.word[i] - 65]++;
}

void	init_game(t_data *data)
{
	set_keyboard(data);
	get_file(data);
	get_word(data);
	refill_alpha(data);
}

void	display_interface(t_data *data)
{
	print_rules();
	refill_alpha(data);
	print_grid(data);
	refill_alpha(data);
	print_keyboard(data, data->keyboard);
}

void	display_result(t_data *data)
{
	if (data->win)
		printf("%s%sGagné%s\n", GREEN, BOLD, RESET);
	else
		printf("%s%sPerdu%s\nmot a trouver : %s\n", RED, BOLD, RESET, data->word.word);
}

void	update_tab(t_data *data)
{
	int	i;

	for (i = 0; i < ATTEMPT && data->guesses[i]; i++);
	if (i < ATTEMPT)
		data->guesses[i] = strdup(data->last_input);
}

int	main(void)
{
	static t_data	data;

	init_game(&data);
	display_interface(&data);
	for (int i = 0; i < ATTEMPT; i++)
	{
		data.last_input = NULL;
		while (!check_input(&data))
		{
			free(data.last_input);
			data.last_input = readline("> ");
		}
		if (is_to_find(&data))
		{
			data.win = true;
			break ;
		}
		data.attempts++;
		update_tab(&data);
		display_interface(&data);
		free(data.last_input);
	}
	display_result(&data);
	//freeTab guesses
	free_list(data.dictionary);
	return (EXIT_SUCCESS);
}
