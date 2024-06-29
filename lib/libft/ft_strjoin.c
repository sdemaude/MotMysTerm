/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:05:48 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 11:24:55 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	ss1;
	size_t	ss2;

	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	if (!s1 || !s2)
	{
		dest = malloc(1);
		return (dest);
	}
	dest = malloc(ss1 + ss2 + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, ss1 + 1);
	ft_strlcat(dest, s2, ss1 + ss2 + 1);
	return (dest);
}
/*
int	main()
{
	printf("%s", ft_strjoin("Hello ", "World !"));
}
*/
