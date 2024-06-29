/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:09:52 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 14:48:10 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(void *content)
{
	*(int *)content += 1;
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
int	main()
{
	t_list	*lst;
	int	n[] = {14};
	lst = ft_lstnew(n);
	ft_lstiter(lst, f);
	printf("%d", *(int *)lst->content);
}
*/
