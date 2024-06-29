/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:50:29 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 12:10:34 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (i < n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
/*
int	main()
{
	char 	*dest;
	dest = malloc(5 * sizeof(char));
	printf("%s", (char*)ft_memmove(dest, "Bonjour", 5));
}
*/
