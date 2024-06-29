/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:37:57 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/30 14:56:56 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void    del(void *content)
{
        content = NULL;
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	while (*lst != NULL)
	{
		new = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = new;
	}
	free(*lst);
	*lst = NULL;
}
/*
int     main()
{
        t_list  *lst1 = malloc(sizeof(t_list));
        t_list  *lst2 = malloc(sizeof(t_list));
        t_list  *lst3 = malloc(sizeof(t_list));
        t_list  *lst4 = malloc(sizeof(t_list));

        lst1->next = lst2;
        lst2->next = lst3;
        lst3->next = lst4;
        lst4->next = NULL;

        ft_lstclear(&lst1, del);
}*/
