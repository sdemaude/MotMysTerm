/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:18:49 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/31 11:07:21 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = (void *)content;
	new->next = NULL;
	return (new);
}
/*
int	main()
{
	t_list	*lst0 = malloc(sizeof(t_list));
	t_list	*lst1;
	
	lst0->next = NULL;

	printf("%d\n", ft_lstsize(lst0));
	lst1 = ft_lstnew("content");
	lst0->next = lst1;
	printf("%d\n", ft_lstsize(lst0));
}*/
