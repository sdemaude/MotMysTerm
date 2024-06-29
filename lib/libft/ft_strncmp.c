/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:11:55 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/20 16:53:17 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if ((s1[i] < s2[i]) || (s1[i] > s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else if (s1[i])
		return (1);
	else if (s2[i])
		return (-1);
	return (0);
}
/*
int	main()
{
	printf("%d\n", ft_strncmp("chaine", "chaine", 5));
	printf("%d\n", strncmp("chaine", "chaine", 5));
}*/
