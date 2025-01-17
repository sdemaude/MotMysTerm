#ifndef INCLUDE_H
# define INCLUDE_H

// Standard libraries
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <time.h>

# include "../lib/libft/libft.h"

// Terminal color codes
# define RED 			"\033[1;31m"
# define GREEN 			"\033[1;32m"
# define YELLOW 		"\033[1;33m"
# define RESET 			"\033[0m"
# define WHITE 			"\033[1;37m"
# define BLACK 			"\033[0;30m"
# define BLACK_ON_WHITE "\033[0;30;47m"
# define BOLD 			"\033[1m"

// Extended ASCII characters for borders
# define TOP_LEFT 		"\u250C"
# define TOP_RIGHT 		"\u2510"
# define BOTTOM_LEFT 	"\u2514"
# define BOTTOM_RIGHT 	"\u2518"
# define HORIZONTAL 	"\u2500"
# define VERTICAL 		"\u2502"
# define T_TOP 			"\u252C"
# define T_BOTTOM 		"\u2534"
# define T_LEFT 		"\u251C"
# define T_RIGHT 		"\u2524"
# define CROSS 			"\u253C"

// Bad input messages TODO
# define ERR_ONLY_LETTER	"Le mot ne peut être composé que de lettres\n"
# define ERR_NUMBER_LETTER	"Ce mot n'a pas le bon nombre de lettres\n"
# define ERR_IN_DICTIONARY	"Ce mot n'est pas dans le dictionnaire du jeu\n"
# define ERR_FIRST_LETTER	"Le mot doit commencer par la lettre %c\n"

// Game settings
# define ATTEMPT	6
# define DICT_PATH	"include/file.txt"

// Error messages
typedef enum e_incorrect_input {
	ONLY_LETTER,
	NUMBER_LETTER,
	IN_DICTIONARY,
	FIRST_LETTER
}	t_incorrect_input;

// Data structures
typedef struct	s_list_str {
	char				*line;
	struct s_list_str	*next;
}	t_list_str;

typedef struct	s_word {
	char				*word;
	int					alpha[26];
	int					nb_letter;
	char				first_letter;
}	t_word;

typedef struct	s_key {
	char				letter;
	char				*color;
}	t_key;

typedef struct	s_data {
	int					language;
	char				*dic_path;
	t_list_str			*dictionary;
	t_key				*keyboard;
	int					word_in_dic;
	t_word				word;
	int					attempts;
	char				*last_input;
	t_key				*guesses_color[ATTEMPT];
	bool				win;
}	t_data;

//DISPLAY
void		print_grid(t_data *data);
void		print_keyboard(t_data *data, t_key *keyboard);
void		print_rules(void);
void		display_interface(t_data *data);
void		display_result(t_data *data);

// GAME_LOGIC
void 		set_keyboard_color(t_key *keyboard, char letter, char *color);
void		refill_alpha(t_data *data);
void		update_guesses(t_data *data);
void		update_next_guess(t_data *data);

//INIT
bool		get_file(t_data *data);
void		get_word(t_data	*data);
void		init_keyboard(t_data *data);
void		init_guesses(t_data *data);

//INPUT
bool		is_to_find(t_data *data);
bool		is_in_dict(t_data *data, char *input);
bool		is_input_correct(t_data *data);

//LIST_UTILS
void		lststr_add_front(t_list_str **lst, t_list_str *new);
t_list_str	*lststr_new(char *str);
void		free_list(t_list_str *list);

#endif
