/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:27:39 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 13:21:14 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}
/*
int	main()
{
	t_list  *lst1 = malloc(sizeof(t_list));
        t_list  *lst2 = malloc(sizeof(t_list));
        t_list  *lst3 = malloc(sizeof(t_list));
        t_list  *new = malloc(sizeof(t_list));

        lst1->next = lst2;
        lst2->next = lst3;
        lst3->next = NULL;

        ft_lstadd_back(&lst1, new);
}
*/
