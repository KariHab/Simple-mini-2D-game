
#include "../Headers/so_long.h"

void	free_data(map *data)
{
	free(data);
}


void	ft_freeall(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}
