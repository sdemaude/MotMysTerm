/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:37:19 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 12:24:45 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *content)
{
	content = NULL;
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}
/*
int	main()
{
	t_list	*lst = malloc(sizeof(t_list));
	lst->next = NULL;
	ft_lstdelone(lst, del);
}
*/
