#include "../include/include.h"

void	free_tab(t_key *tab[ATTEMPT]) {
	for (int i = 0; i < ATTEMPT; i++)
		free(tab[i]);
}

void	init_game(t_data *data) {
	get_file(data);
	get_word(data);
	init_keyboard(data);
	init_guesses(data);
}

void	get_input(t_data *data) {
	data->last_input = NULL;
	while (!is_input_correct(data)) {
		free(data->last_input);
		data->last_input = readline("> ");
	}
}

int		main(void) {
	static t_data	data;
	init_game(&data);

	while (data.attempts < ATTEMPT) {
		display_interface(&data);
		get_input(&data);
		update_guesses(&data);

		if (is_to_find(&data)) {
			data.win = true;
			break;
		}
		if (data.attempts < ATTEMPT - 1)
			update_next_guess(&data);
		free(data.last_input);
		data.attempts++;
	}

	display_interface(&data);
	display_result(&data);
	free_tab(data.guesses_color);
	free_list(data.dictionary);

	return (EXIT_SUCCESS);
}