#include "../include/include.h"

void	lststr_add_front(t_list_str **lst, t_list_str *new) {
	new->next = *lst;
	*lst = new;
}

t_list_str	*lststr_new(char *str) {
	t_list_str	*new;

	new = malloc(sizeof(t_list_str));
	if (!new)
		return (0);
	str[ft_strlen(str) - 1] = '\0';
	new->line = str;
	new->next = NULL;
	return (new);
}

void	free_list(t_list_str *list) {
	t_list_str	*tmp;

	while (list != NULL) {
		tmp = list->next;
		free(list->line);
		free(list);
		list = tmp;
	}
}
