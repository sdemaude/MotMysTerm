#include "../include/include.h"

void	set_keyboard(t_data *data)
{
	static t_key keyboard[] = {
		// Première rangée
	{'A', WHITE}, {'Z', WHITE}, {'E', WHITE}, {'R', WHITE}, {'T', WHITE},
	{'Y', WHITE}, {'U', WHITE}, {'I', WHITE}, {'O', WHITE}, {'P', WHITE},
		// Deuxième rangée
	{'Q', WHITE}, {'S', WHITE}, {'D', WHITE}, {'F', WHITE}, {'G', WHITE},
	{'H', WHITE}, {'J', WHITE}, {'K', WHITE}, {'L', WHITE}, {'M', WHITE},
		// Troisième rangée
	{'W', WHITE}, {'X', WHITE}, {'C', WHITE}, {'V', WHITE}, {'B', WHITE},
	{'N', WHITE}
	};

	data->keyboard = keyboard;
}

bool	get_file(t_data *data) //bool ??
{
	char	*file;
	char	*line;
	int		fd;

	file = NULL;
	fd = open(DICT_PATH, O_RDONLY);
	if (fd < 0)
		return (printf("Error\n"), false);
	line = get_next_line(fd);
	data->dictionary = lststr_new(line);
	data->word_in_dic = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lststr_add_bk(&data->dictionary, lststr_new(line));
		data->word_in_dic++;
	}
	return (close(fd), true);
}

void	get_word(t_data	*data)
{
	t_list_str	*tmp = data->dictionary;

	srand(time(NULL));
	int	rand_word = rand() % (data->word_in_dic + 1);

	for (int i = 0; i < rand_word - 1; i++)
		tmp = tmp->next;

	data->word.word = tmp->line;
	data->word.first_letter = data->word.word[0];
	data->word.nb_letter = ft_strlen(data->word.word);
}
