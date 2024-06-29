/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:45:21 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/24 21:54:14 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len - 1]))
		len--;
	s2 = ft_substr(s1, i, len - i);
	if (!s2)
		return (0);
	return (s2);
}

/*int	main()
{
	printf("%s\n", ft_strtrim("ooooooftftftoooooo", "oooooo"));
}*/
