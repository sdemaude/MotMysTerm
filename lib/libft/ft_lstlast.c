/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:55:22 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/31 18:57:30 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main()
{
	char	str[] = "abc";

	t_list	*lst0 = malloc(sizeof(t_list));
        t_list  *lst1 = malloc(sizeof(t_list));
        t_list  *lst2 = malloc(sizeof(t_list));
        t_list  *lst3 = malloc(sizeof(t_list));
	t_list	*plus;

	lst0->next = lst1;
	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next = NULL;
	
	lst3->content = (void *)str;
	plus = ft_lstlast(lst0);
	printf("%s", (char *)plus->content);
}
*/
