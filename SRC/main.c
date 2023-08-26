#include "so_long.h"
/*
Check if the word in long enough
Compare the last character of the word with .ber
*/
void check_extension (char *word)
{
	int word_length;

	word_length = ft_strlen(word);

	if (word_length >= 4 )
	{
		if (ft_strncmp(word + word_length - 4, ".ber", 4) == 0)
		{
			ft_printf("Correct extension\n");
		}
		else
		{
			ft_printf("Incorrect extension\n");
		}
	}
	else
	{
		ft_printf("Incorrect filename\n");
	}
}

int main (int argc, char *argv[])
{
	char *arg1 = argv[0];
	char *arg2 = argv[1];

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", arg1);
		return 1; 
	}
	check_extension(arg2);
}

