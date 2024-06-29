/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:25:30 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/29 16:33:56 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40000

# endif

char	*get_next_line(int fd);
char	*to_line(char *str);
int		ft_is_nl(char *str);
size_t	mod_strlen(const char *str, char c);
char	*mod_strjoin(char const *s1, char const *s2, long long ir);
void	to_save(char *str);

#endif
