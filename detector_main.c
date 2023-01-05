#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;
	char	str[] = "que fue lo que paso\n que si que no";

	i = ft_detector(str);
	printf("%i\n", i);
	j = 0;
	while (j < i)
	{
		write(1, &str[j], 1);
		j++;
	}
	printf("\n");
	return (0);
}
