#include "../include/include.h"

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

int	main(void)
{
	t_data	data;
	t_key keyboard[] = {
		// Première rangée
		{'A', WHITE}, {'Z', WHITE}, {'E', WHITE}, {'R', WHITE}, {'T', WHITE}, 
		{'Y', WHITE}, {'U', WHITE}, {'I', WHITE}, {'O', WHITE}, {'P', WHITE},
		
		// Deuxième rangée
		{'Q', "\033[35m"}, {'S', "\033[36m"}, {'D', "\033[31m"}, {'F', "\033[32m"}, {'G', "\033[33m"}, 
		{'H', "\033[34m"}, {'J', "\033[35m"}, {'K', "\033[36m"}, {'L', "\033[31m"}, {'M', "\033[32m"},
		
		// Troisième rangée
		{'W', "\033[35m"}, {'X', "\033[36m"}, {'C', "\033[31m"}, {'V', "\033[32m"}, {'B', "\033[33m"}, 
		{'N', "\033[34m"}
};

int numRows = 3;
int numCols[] = {10, 10, 6}; // Nombre de colonnes pour chaque rangée

	print_rules();
	display_keyboard(keyboard, numRows, numCols);
	get_file(&data);
	get_word(&data);
	printf("word to find = %s\nfirst letter = %c\nnumber of letter = %d\n", data.word.word, data.word.first_letter, data.word.nb_letter);
	for (int i = 0; i < ATTEMPT; i++)
	{
		get_input(&data);
		//update_tab(&data);
		printf("%s\n", data.last_input); //free after each call to this function
		//update_ltrs();
		if (is_to_find(&data))
		{
			data.win = true;
			break ;
		}
		//set_keyboard(&keyboard);
		//  |-->print tab-------------------|
		//  |--print_keyboard(&keyboard);<--|
		free(data.last_input);
	}
	//display result
	free_list(data.dictionary);
	return (EXIT_SUCCESS);
}
