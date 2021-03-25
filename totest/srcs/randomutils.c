#include "../includes/cub3d.h"

void	ft_initall(t_all *all)
{
	all->isok = 0;
	all->x_screen = -1;
	all->y_screen = -1;
	all->mapwdth = -1;
	all->mapheight = 0;
	all->floor_rgb = -1;
	all->ceil_rgb = -1;
	all->no_path = 0;
	all->ea_path = 0;
	all->so_path = 0;
	all->we_path = 0;
	all->s_path = 0;
	all->xpos = -1;
	all->ypos = -1;
	all->xdir = 0;
	all->ydir = 0;
	all->forward = 0;
	all->backward = 0;
	all->left = 0;
	all->right = 0;
	all->turn_left = 0;
	all->turn_right = 0;
	ft_initall2(all);
}

void	ft_initall2(t_all *all)
{
	(void)all;
}

int	ft_atoi(char *nptr)
{
	long long int		i;
	long long int		r;
	long long int		s;

	i = 0;
	r = 0;
	s = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			r = r * 10 + nptr[i] - '0';
		else
			break ;
		i++;
	}
	return (s * r);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
	i++;
	}
	free (str);
}