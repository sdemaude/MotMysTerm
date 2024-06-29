/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:19:58 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/30 19:24:54 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
	return ((char *)s);
}

/*int	main()
{
	char	buffer[10];
	int		i;

	i = 0;
	while (i != 10)
	{
		buffer[i] = 'A';
		i++;
	}
	ft_memset(buffer, 'd', 5);
}*/
