/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:23:27 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/29 16:34:17 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*mod_free(char *str, char *sav)
{
	*sav = '\0';
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	sav[BUFFER_SIZE + 1] = {};
	char		*line;
	int			isread;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (*sav != 0)
		line = mod_strjoin(line, sav, BUFFER_SIZE);
	isread = BUFFER_SIZE;
	while (isread == BUFFER_SIZE && ft_is_nl(sav) == 0)
	{
		isread = read(fd, sav, BUFFER_SIZE);
		if (isread == -1)
			return (mod_free(line, sav));
		sav[isread] = '\0';
		if (isread == 0)
			break ;
		line = mod_strjoin(line, sav, isread);
	}
	if (line == NULL || *line == 0)
		return (mod_free(line, sav));
	to_save(sav);
	return (to_line(line));
}

char	*to_line(char *str)
{
	int		i;
	char	*return_line;

	i = 0;
	if (!str)
		return (NULL);
	return_line = malloc(mod_strlen(str, '\n') + 2);
	if (!return_line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		return_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		return_line[i] = '\n';
		i++;
	}
	free(str);
	return_line[i] = '\0';
	return (return_line);
}

void	to_save(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}
