/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:48:14 by sdemaude          #+#    #+#             */
/*   Updated: 2023/10/24 14:22:05 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_total(long n)
{
	long	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	long	i;
	long	j;
	long	nb;

	nb = n;
	i = ft_total(nb);
	j = 0;
	num = malloc(i + 1);
	if (!num)
		return (0);
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
		j++;
	}
	num[i] = '\0';
	while (i > j)
	{
		i--;
		num[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (num);
}

/*int     main()
{
        char    *str = ft_itoa(-21);
        printf("%s", str);
        free(str);
}*/
