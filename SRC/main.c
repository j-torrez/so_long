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
	char *result;
	

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", arg1);
		return 1; 
	}
	check_extension(arg2);
	result = read_map(arg2);

// Test Map as a single String: 
	ft_printf("Map as one string: \n");
	ft_printf("%s\n", result);

// Test Map as a 2D array

	char **map_array;
	map_array = map_as_array(result);
	int i = 0;
	 while (map_array[i] != NULL) {
        printf("Map as array: %s\n", map_array[i]);
        free(map_array[i]); // Free the memory for each line
        i++;
    }
	free(map_array);
    
}

