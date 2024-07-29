#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <time.h>
# include "../lib/libft/libft.h"

// Terminal color codes
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define WHITE "\033[1;37m"
# define BLACK "\033[0;30m"
# define BLACK_ON_WHITE "\033[0;30;47m"
# define BOLD "\033[1m"

// Extended ASCII characters for borders
# define TOP_LEFT "\u250C"
# define TOP_RIGHT "\u2510"
# define BOTTOM_LEFT "\u2514"
# define BOTTOM_RIGHT "\u2518"
# define HORIZONTAL "\u2500"
# define VERTICAL "\u2502"
# define T_TOP "\u252C"
# define T_BOTTOM "\u2534"
# define T_LEFT "\u251C"
# define T_RIGHT "\u2524"
# define CROSS "\u253C"

# define SIZE_HALF_WIN 94

# define ATTEMPT 6

# define DICT_PATH "include/file.txt"

typedef enum e_incorrect_input
{
	ONLY_LETTER,
	NUMBER_LETTER,
	IN_DICTIONARY,
	FIRST_LETTER
}	t_incorrect_input;

typedef struct s_list_str
{
	char				*line;
	struct s_list_str	*next;
}	t_list_str;

typedef struct s_word
{
	char	*word;
	int		alpha[26];
	int		nb_letter;
	char	first_letter;
}	t_word;

typedef struct s_key
{
	char	letter;
	char	*color;
}	t_key;

typedef struct s_data
{
	int			language;
	char		*dic_path;
	t_list_str	*dictionary;
	t_key		*keyboard;
	int			word_in_dic;
	t_word		word;
	int			attempts;
	char		*last_input;
	char		*guesses[6];
	bool		win;
}	t_data;

//INIT
void		set_keyboard(t_data *data);
bool		get_file(t_data *data);
void		get_word(t_data	*data);
void		refill_alpha(t_data *data);

//DISPLAY
void		print_rules(void);
void		print_keyboard(t_data *data, t_key keyboard[]);
void		print_grid(t_data *data);

//LIST_UTILS
void		lststr_add_bk(t_list_str **lst, t_list_str *new);
t_list_str	*lststr_new(char *str);
void		free_list(t_list_str *list);
//void		print_list(t_list_str *list);

void		get_input(t_data *data);

#endif
