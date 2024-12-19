#include "../include/include.h"

bool	get_file(t_data *data) { //TODO : check if the file is correct
	char	*line;
	int		fd;

	fd = open(DICT_PATH, O_RDONLY);
	if (fd < 0)
		return (printf("Error\n"), false);
	line = get_next_line(fd);
	data->dictionary = lststr_new(line);
	data->word_in_dic = 1;
	while (1) {
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lststr_add_front(&data->dictionary, lststr_new(line));
		data->word_in_dic++;
	}

	return (close(fd), true);
}

void	get_word(t_data	*data) {
	t_list_str	*tmp = data->dictionary;

	srand(time(NULL));
	int	rand_word = rand() % data->word_in_dic;

	for (int i = 0; i < rand_word - 1; i++)
		tmp = tmp->next;

	data->word.word = tmp->line;
	data->word.first_letter = data->word.word[0];
	data->word.nb_letter = ft_strlen(data->word.word);
}

void	init_keyboard(t_data *data) {
	static t_key keyboard[] = {
		// First row
	{'A', WHITE}, {'Z', WHITE}, {'E', WHITE}, {'R', WHITE}, {'T', WHITE},
	{'Y', WHITE}, {'U', WHITE}, {'I', WHITE}, {'O', WHITE}, {'P', WHITE},
		// Second row
	{'Q', WHITE}, {'S', WHITE}, {'D', WHITE}, {'F', WHITE}, {'G', WHITE},
	{'H', WHITE}, {'J', WHITE}, {'K', WHITE}, {'L', WHITE}, {'M', WHITE},
		// Third row
	{'W', WHITE}, {'X', WHITE}, {'C', WHITE}, {'V', WHITE}, {'B', WHITE},
	{'N', WHITE}
	};

	data->keyboard = keyboard;
}

void	init_guesses(t_data *data) {
	for (int i = 0; i < ATTEMPT; i++) {
		data->guesses_color[i] = malloc(sizeof(t_key) * data->word.nb_letter);
	}
	for (int i = 0; i < ATTEMPT; i++) {
		for (int j = 0; j < data->word.nb_letter; j++) {
			if (i == 0)
				data->guesses_color[i][j].letter = '.';
			else
				data->guesses_color[i][j].letter = ' ';
			data->guesses_color[i][j].color = WHITE;
		}
	}
	data->guesses_color[0][0].letter = data->word.first_letter;
}
