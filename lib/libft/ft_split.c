/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:56:00 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/28 18:28:25 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numw(char *s, char c)

{
	int	i;
	int	nbmot;

	i = 0;
	nbmot = 0;
	if (s[0] != c && s[0] != '\0')
		nbmot++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nbmot++;
		i++;
	}
	return (nbmot);
}

static int	lenw(char *s, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c)
		j++;
	while (s[i] && j <= n)
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	j = 1;
	while (s[i] && s[i + 1] != c && s[i + 1] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static void	dupw(char *s, int n, char *dest, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	n++;
	if (s[0] != c)
		j++;
	while (s[i] && j < n)
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	j = 0;
	while (s[i + j] && s[i + j] != c)
	{
		dest[j] = s[i + j];
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	int			i;
	int			nbmot;

	i = 0;
	nbmot = numw((char *)s, c);
	dest = malloc((nbmot + 1) * sizeof(char *));
	if (!dest)
		return (0);
	while (i < nbmot)
	{
		dest[i] = malloc(lenw((char *)s, c, i) + 1);
		if (!dest[i])
		{
			while (i-- > 0)
				free(dest[i]);
			free(dest);
			return (0);
		}
		dupw((char *)s, i, dest[i], c);
		dest[i][lenw((char *)s, c, i)] = '\0';
		i++;
	}
	dest[nbmot] = NULL;
	return (dest);
}
/*
int	main()
{
	ft_split("  bonjour  bon jour ! ", ' ');
}
*/
