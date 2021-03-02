#include "../includes/cub3d.h"

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str != 0 && str[i] < '0' && str[i] > '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_initall(t_all all)
{
	all.isok = 0;
	all.x_screen = 10;
	all.y_screen = 10;
}