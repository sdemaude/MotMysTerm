#include "../include/include.h"

// Add a new element at the end of the list
void	lststr_add_bk(t_list_str **lst, t_list_str *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}

// Create a new element
t_list_str	*lststr_new(char *str)
{
	t_list_str	*new;

	new = malloc(sizeof(t_list_str));
	if (!new)
		return (0);
	str[ft_strlen(str) - 1] = '\0'; //TODO: use modified gnl (for lines without '\n')
	new->line = str;
	new->next = NULL;
	return (new);
}

// Free the list
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

/*
void	print_list(t_list_str *list)
{
	t_list_str	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}*/
