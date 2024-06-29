/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:47:45 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/02 11:54:11 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*dest;

	dest = malloc(size * nmeb);
	if (dest == 0)
		return (0);
	ft_bzero(dest, size * nmeb);
	return ((char *)dest);
}
