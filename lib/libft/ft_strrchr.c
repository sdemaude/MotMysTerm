/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:58:46 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/19 14:57:46 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
		j++;
	}
	while (str[i] >= 0 && j >= 0)
	{
		if (str[j] == (char)c)
			return ((char *)str + j);
		j--;
	}
	return (0);
}

/*int	main()
{
	printf("%s\n", ft_strrchr("Bonjour", 'o'));
	printf("%s\n", strrchr("Bonjour", 'o'));
}*/
