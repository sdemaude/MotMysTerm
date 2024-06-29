/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:31:49 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 15:27:09 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void    del(void *content)
{
        content = NULL;
}

void	*f(void *content)
{
	*((int *)content) += 5;
	return (content);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new;
	t_list	*map;

	new = NULL;
	while (lst != NULL)
	{
		content = (*f)(lst->content);
		map = ft_lstnew(content);
		if (!map)
		{
			(*del)(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, map);
		lst = lst->next;
	}
	return (new);
}
/*
int	main()
{
	t_list	*map;
	t_list	*lst0;
	int	n[] = {15};


	lst0 = ft_lstnew(n);
	map = ft_lstmap(lst0, f, del);
	printf("%d", *((int *)map->content));
	free(map);
}
*/
