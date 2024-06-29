/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:24:35 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 11:22:25 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(size_t n, size_t start)
{
	if (n < start)
		return (n);
	return (start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = ft_len(ft_strlen(s), start);
	len = ft_len(ft_strlen(s) - i, len);
	dest = malloc(len + 1);
	if (dest == 0)
		return (0);
	else if (dest)
		ft_strlcpy(dest, s + i, len + 1);
	return (dest);
}
/*
int	main()
{
	printf("%s", ft_substr("Bonjour", 2, 4));
}
*/
