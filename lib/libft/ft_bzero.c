/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:41:39 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/30 19:22:37 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i != n)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	buffer[10];
	int		i;

	i = 0;
	while (i != 10)
	{
		buffer[i] = 'A';
		i++;
	}
	ft_bzero(buffer, 5);
}*/
