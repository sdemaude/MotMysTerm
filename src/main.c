#include "../include/include.h"

void	lststr_add_bk(t_list_str **lst, t_list_str *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}

t_list_str	*lststr_new(char *str)
{
	t_list_str	*new;

	new = malloc(sizeof(t_list_str));
	if (!new)
		return (0);
	str[ft_strlen(str) - 1] = '\0'; //or modified gnl for line without '\n'
	new->line = str;
	new->next = NULL;
	return (new);
}

void	free_list(t_list_str *list)
{
	t_list_str	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->line);
		free(list);
		list = tmp;
	}
}

bool	get_file(t_data *data) //bool ??
{
	char	*file;
	char	*line;
	int		fd;

	file = NULL;
	fd = open(FR_DIC, O_RDONLY); //data->dic_path later
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

void	print_list(t_list_str *list)
{
	t_list_str	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
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

int	main(void)
{
	t_data	data;

	//get language ---> EN or FR (fr by default for now) -> set date.dic_path
	//print rules
	get_file(&data);
	get_word(&data);
	printf("word to find = %s\nfirst letter = %c\nnumber of letter = %d\n", data.word.word, data.word.first_letter, data.word.nb_letter);
	//set_keyboard(&keyboard);
	//  |-->print tab-------------------|
	//  |--print_keyboard(&keyboard);<--|
	//display result
	free_list(data.dictionary);
	return (EXIT_SUCCESS);
}
/*
int	main(void)
{
	//int	fd = open();
	print_rules();

	//close(fd);
	return (0);
}*/
