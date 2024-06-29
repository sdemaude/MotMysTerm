/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:40:59 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 11:59:09 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	*str = "abcdef";
	printf("%s", (char*)ft_memchr(str, 'd', 5));
}
*/
