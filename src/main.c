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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lststr_add_bk(&data->dictionary, lststr_new(line));
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

int	main(void)
{
	t_data	data;

	//get language ---> EN or FR (fr by default by now) -> set date.dic_path
	get_file(&data);
	printf("done\n");
	//print_list(data.dictionary);
	//set_keyboard(&keyboard);
	//print rules
	//get word
	//  |-->print tab-------------------|
	//  |--print_keyboard(&keyboard);<--|
	//display result
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
