#include "../include/include.h"

void	refill_alpha(t_data *data) {
	for (int i = 0; i < 26; i++)
		data->word.alpha[i] = 0;
	for (int i = 0; data->word.word[i]; i++)
		data->word.alpha[data->word.word[i] - 65]++;
}

// Initialize the game
void	init_game(t_data *data) {
	set_keyboard(data);
	get_file(data);
	get_word(data);
	init_guesses(data);
}

// Display the game interface
void	display_interface(t_data *data) {
	print_rules();
	print_grid(data);
	print_keyboard(data, data->keyboard);
}

void update_guesses(t_data *data) {
	refill_alpha(data);
	for (int i = 0; i < data->word.nb_letter; i++) {
		data->guesses_color[data->attempts][i].letter = data->last_input[i];
		if (data->guesses_color[data->attempts][i].letter == data->word.word[i]) {
			data->guesses_color[data->attempts][i].color = RED;
			data->word.alpha[data->word.word[i] - 65]--;
		}
	}
	for (int i = 0; i < data->word.nb_letter; i++) {
		if (data->guesses_color[data->attempts][i].letter != data->word.word[i]) {
			if (data->word.alpha[data->guesses_color[data->attempts][i].letter - 65] > 0) {
				data->guesses_color[data->attempts][i].color = YELLOW;
				data->word.alpha[data->guesses_color[data->attempts][i].letter - 65]--;
				set_keyboard_color(data->keyboard, data->guesses_color[data->attempts][i].letter, YELLOW);
			} else {
				set_keyboard_color(data->keyboard, data->guesses_color[data->attempts][i].letter, BLACK);
			}
		} else if (data->guesses_color[data->attempts][i].letter == data->word.word[i]) {
			set_keyboard_color(data->keyboard, data->guesses_color[data->attempts][i].letter, RED);
		}
	}
}

void	update_next_guess(t_data *data) {
	for (int i = 0; i < data->word.nb_letter; i++)
		data->guesses_color[data->attempts + 1][i].letter = '.';
	for (int i = 0; i <= data->attempts; i++) {
		for (int j = 0; j < data->word.nb_letter; j++) {
			if (!strcmp(data->guesses_color[i][j].color, RED))
				data->guesses_color[data->attempts + 1][j].letter = data->word.word[j];
		}
	}
}

void	display_result(t_data *data) {
	if (data->win)
		printf("%s%sGagné !!%s\n", GREEN, BOLD, RESET);
	else
		printf("%s%sPerdu...%s\nLe mot à trouver était : %s.\n", RED, BOLD, RESET, data->word.word);
}

void	free_tab(t_key *tab[ATTEMPT]) {
	for (int i = 0; i < ATTEMPT; i++)
		free(tab[i]);
}

void	get_input(t_data *data) {
	data->last_input = NULL;
	while (!is_input_correct(data)) {
		free(data->last_input);
		data->last_input = readline("> ");
	}
}

int	main(void) {
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