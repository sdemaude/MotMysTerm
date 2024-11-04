#include "../include/include.h"

void	set_keyboard_color(t_key *keyboard, char letter, char *color) {
	for (int i = 0; i < 26; i++) {
		if (keyboard[i].letter == letter) {
			if ((!strcmp(keyboard[i].color, YELLOW) && !strcmp(color, RED)) || !strcmp(keyboard[i].color, WHITE)) 
				keyboard[i].color = color;
			break;
		}
	}
}

void	refill_alpha(t_data *data) {
	for (int i = 0; i < 26; i++)
		data->word.alpha[i] = 0;
	for (int i = 0; data->word.word[i]; i++)
		data->word.alpha[data->word.word[i] - 65]++;
}

void	update_guesses(t_data *data) {
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
