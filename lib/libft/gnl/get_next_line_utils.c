/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:33 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/26 17:02:51 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_nl(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*mod_strjoin(char const *s1, char const *s2, long long ir)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s2 || s2[i] == '\0')
	{
		dest = malloc(1);
		dest[i] = '\0';
		return (dest);
	}
	dest = malloc(mod_strlen(s1, '\0') + ir + 1);
	if (!dest)
		return (0);
	if (s1)
		while (s1[i])
			dest[j++] = s1[i++];
	i = 0;
	while (s2[i] && ir-- > 0)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	free((char *)s1);
	return (dest);
}

size_t	mod_strlen(const char *str, char c)
{
	size_t	i;

	(void)c;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
