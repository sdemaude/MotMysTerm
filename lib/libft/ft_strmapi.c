/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:32 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/24 15:16:11 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dest;

	i = ft_strlen(s);
	dest = malloc(i + 1);
	if (!dest)
		return (0);
	dest[i] = '\0';
	while (i > 0)
	{
		i--;
		dest[i] = (*f)(i, s[i]);
	}
	return (dest);
}
