#include "../include/include.h"
/*
// Function to print the Wordle interface
void print_interface(char guesses[][5], char results[][5], int wordLength)
{

	// Print the top border
	printf("%s", TOP_LEFT);
	for (int j = 0; j < wordLength; j++)
	{
		printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
		if (j < wordLength - 1)
			printf("%s", T_TOP);
	}
	printf("%s\n", TOP_RIGHT);

	// Print the Wordle grid
	for (int i = 0; i < ATTEMPT; i++)
	{
		// Print the row with guesses
		printf("%s", VERTICAL);
		for (int j = 0; j < wordLength; j++)
		{
			char result = results[i][j];
			char guess = guesses[i][j];

			if (result == 'G')
				printf(" %s%c%s ", RED, guess, RESET);  // Red for correct position
			else if (result == 'Y')
				printf(" %s%c%s ", YELLOW, guess, RESET); // Yellow for correct letter but wrong position
			else
			{
				if (guess == ' ')
					printf("%s _ %s", BLACK_ON_WHITE, RESET); // Empty box for no guess
				else
					printf(" %s%c%s ", WHITE, guess, RESET); // White for incorrect letter
			}
			printf("%s", VERTICAL);
		}
		printf("\n");

		// Print the border between rows
		if (i < ATTEMPT - 1)
		{
			printf("%s", T_LEFT);
			for (int j = 0; j < wordLength; j++)
			{
				printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
				if (j < wordLength - 1)
					printf("%s", CROSS);
			}
			printf("%s\n", T_RIGHT);
		}
	}

	// Print the bottom border
	printf("%s", BOTTOM_LEFT);
	for (int j = 0; j < wordLength; j++)
	{
		printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
		if (j < wordLength - 1)
			printf("%s", T_BOTTOM);
	}
	printf("%s\n", BOTTOM_RIGHT);
}

void	print_keyboard(t_key *keyboard)
{
	printf("\033[2J\033[H");
    // Iterate through each row
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            // Only print valid keys
            if (keyboard[i][j].letter != ' ') {
                // Print the letter with its color
                printf("%s%c\033[0m ", keyboard[i][j].color, keyboard[i][j].letter);
            } else {
                printf("   ");  // Print spaces for alignment
            }
        }
        printf("\n");
    }
}*/

void	print_rules(void)
{
	printf("\033[2J\033[H");
    // Print the rules
	printf("Bienvenue à Sutom !\n");
	printf("Règles du jeu :\n");
	printf("1. Vous avez 6 tentatives pour deviner un mot de 5 à 7 lettres.\n");
	printf("2. Chaque mot doit être un mot valide.\n");
	printf("3. Après chaque tentative, la couleur des cases changera pour montrer à quel point votre tentative était proche du mot.\n");
	printf("   - %sRouge%s : La lettre est dans le mot et à la bonne place.\n", RED, RESET);
	printf("   - %sJaune%s : La lettre est dans le mot mais à la mauvaise place.\n", YELLOW, RESET);
	printf("   - %sBlanc%s : La lettre n'est pas dans le mot.\n\n", WHITE, RESET);
	printf("Exemple :\n");
	printf("Deviner : ");
	printf("%s S %s %s U %s %s T %s %s O %s %s M %s\n", RED, RESET, YELLOW, RESET, WHITE, RESET, WHITE, RESET, YELLOW, RESET);
	printf("Explication : S est correct et à la bonne place (Rouge). U est correct mais à la mauvaise place (Jaune).\n");
	printf("T n'est pas dans le mot (Blanc). O n'est pas dans le mot (Blanc). M est correct mais à la mauvaise place (Jaune).\n");
	printf("Bonne chance et amusez-vous bien !\n\n");
}

/*
void	set_keyboard(t_key *keyboard)
{
	keyboard = {
        {{'Q', "\033[31m"}, {'W', "\033[32m"}, {'E', "\033[33m"}, {'R', "\033[34m"}, {'T', "\033[35m"},
         {'Y', "\033[36m"}, {'U', "\033[31m"}, {'I', "\033[32m"}, {'O', "\033[33m"}, {'P', "\033[34m"}},
        {{' ', ""}, {'A', "\033[35m"}, {'S', "\033[36m"}, {'D', "\033[31m"}, {'F', "\033[32m"},
         {'G', "\033[33m"}, {'H', "\033[34m"}, {'J', "\033[35m"}, {'K', "\033[36m"}, {'L', "\033[31m"}},
        {{' ', ""}, {' ', ""}, {'Z', "\033[32m"}, {'X', "\033[33m"}, {'C', "\033[34m"},
         {'V', "\033[35m"}, {'B', "\033[36m"}, {'N', "\033[31m"}, {'M', "\033[32m"}, {' ', ""}}
	};
}

*/
