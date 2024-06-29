/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:14:30 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/20 16:04:22 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
	{
		while (str[i])
			i++;
		return ((char *)str + i);
	}
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

/*int	main()
{
	printf("%s\n", ft_strchr("Bonjour", 'j'));
	printf("%s\n", strchr("Bonjour", 'j'));
}*/
