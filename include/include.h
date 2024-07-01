#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <time.h>
# include "../lib/libft/libft.h"

# define SIZE_HALF_WIN 94

# define EN 1
# define FR 2
# define EN_DIC ""
# define FR_DIC "include/file.txt"
/*# define RULES "Le but est de trouver le mot en un minimum de coups sans dépasser 6 tentatives ou la partie est perdue. \
A chaque tentative, les lettres bien placées sont affiches en rouge et celles mal placées en jaune. \
Les mots mal orthographiés ou absents du dictionnaire apparaissent en minuscules."
*/
typedef struct s_list_str
{
	char				*line;
	struct s_list_str	*next;
}	t_list_str;

// Define a struct to hold each letter and its color
typedef struct s_key
{
	char	letter;
	char	color[8];
}	t_key;

typedef struct s_word
{
	char	*word;
	//int		index;
	int		nb_letter;
	char	first_letter;
}	t_word;

typedef struct s_data
{
	int			language;
	t_key		keyboard;
	char		*dic_path; // FR_DIC if FR EN_DIC if EN
	t_list_str	*dictionary;
	int			word_in_dic;
	t_word		word;
}	t_data;

#endif
