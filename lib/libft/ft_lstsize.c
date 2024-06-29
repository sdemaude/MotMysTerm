/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:31:21 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/31 10:51:30 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main()
{
	t_list	*lst0 = malloc(sizeof(t_list));
	t_list	*lst1 = malloc(sizeof(t_list));
	t_list	*lst2 = malloc(sizeof(t_list));
	t_list	*lst3 = malloc(sizeof(t_list));
	t_list	*lst4 = malloc(sizeof(t_list));

	lst0->next = lst1;
	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next = lst4;
	lst4->next = NULL;

	printf("%d", ft_lstsize(lst0));
}*/
