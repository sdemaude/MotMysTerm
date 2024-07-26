#include "../include/include.h"
#include <string.h>

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

void	incorrect_input(t_data *data, char *input, t_incorrect_input err_msg)
{
	if (err_msg == ONLY_LETTER)
		printf("must be only letters\n");
	else if (err_msg == NUMBER_LETTER)
		printf("incorrect nb of letter\n");
	else if (err_msg == IN_DICTIONARY)
		printf("not in dictionary\n");
	else if (err_msg == FIRST_LETTER)
		printf("must start by a %c\n", data->word.word[0]);
	free(input);
	get_input(data);
}

void	get_input(t_data *data)
{
	char	*input;

	input = readline("> ");
	for (int i = 0; input[i]; i++)
	{
		if (!ft_isalpha(input[i]))
			incorrect_input(data, input, ONLY_LETTER);
		input[i] = toupper(input[i]);
	}
	if ((int)ft_strlen(input) != data->word.nb_letter)
		incorrect_input(data, input, NUMBER_LETTER);
	if (!is_in_dict(data, input))
		incorrect_input(data, input, IN_DICTIONARY);
	if (input[0] != data->word.word[0])
		incorrect_input(data, input, FIRST_LETTER);
	data->last_input = input;
}

void	init_game(t_data *data)
{
	data->attempts = 0;
	for (int i = 0; i < ATTEMPT; i++)
		data->guesses[i] = NULL;
	set_keyboard(data);
	get_file(data);
	get_word(data);
}

void	display_interface(t_data *data)
{
	//reset_keyboard(&keyboard);
	//  |-->print tab-------------------|
	//  |--print_keyboard(&keyboard);<--|
	print_rules();
	print_grid(data); 
	print_keyboard(data, data->keyboard);
}

void	display_result(t_data *data)
{
	if (data->win)
		printf("%s%sGagné%s\n", GREEN, BOLD, RESET);
	else
		printf("%s%sPerdu%s\n", RED, BOLD, RESET);
}

void	update_tab(t_data *data)
{
	int i;
	printf("last input : %s\n", data->last_input);

	for (i = 0; i < ATTEMPT && data->guesses[i]; i++);
	if (i < ATTEMPT)
		data->guesses[i] = strdup(data->last_input);
}

int	main(void)
{
	t_data	data;

	init_game(&data);
	display_interface(&data);
	for (int i = 0; i < ATTEMPT; i++)
	{
		get_input(&data);
		if (is_to_find(&data))
		{
			data.win = true;
			break ;
		}
		update_tab(&data); // + update_ltrs();
		sleep(3);
		display_interface(&data);
		free(data.last_input);
		data.attempts++;
	}
	display_result(&data);
	//freeTab guesses
	free_list(data.dictionary);
	return (EXIT_SUCCESS);
}
