/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:07:43 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 12:32:03 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
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

	ft_lstadd_front(&lst1, new);
}
*/
