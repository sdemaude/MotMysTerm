#include "../include/include.h"

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
		printf("%s%sGagné !!%s\n", GREEN, BOLD, RESET);
	else
		printf("%s%sPerdu...%s\nLe mot à trouver était : %s.\n", RED, BOLD, RESET, data->word.word);
}

void	update_tab(t_data *data)
{
	int	i;

	for (i = 0; i < ATTEMPT && data->guesses[i]; i++);
	if (i < ATTEMPT)
		data->guesses[i] = strdup(data->last_input);
}

void	free_tab(char **tab)
{
	if (!tab)
		return ;
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
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
	update_tab(&data);
	display_interface(&data);
	display_result(&data);
	free_tab(data.guesses);
	free_list(data.dictionary);
	return (EXIT_SUCCESS);
}