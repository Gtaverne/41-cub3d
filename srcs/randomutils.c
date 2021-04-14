/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:41:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 14:41:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_initall(t_all *all)
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
	all->xcam = 0;
	all->ycam = 0;
	all->forward = 0;
	all->backward = 0;
	all->left = 0;
	all->right = 0;
	all->turn_left = 0;
	all->turn_right = 0;
	ft_initall2(all);
}

void		ft_initall2(t_all *all)
{
	all->escape = 0;
	all->save = 0;
	all->map[0] = NULL;
}

long int	ft_atoi(char *nptr, t_all *all)
{
	long long int		i;
	long long int		r;

	i = 0;
	r = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		all->isok += 1000;
		return (0);
	}
	while (nptr[i] != '\0')
	{
		if (is_insep(nptr[i], "0123456789"))
			r = r * 10 + nptr[i] - '0';
		else if (nptr[i] > '9' || nptr[i] < '0')
		{
			printf("Error\nNon numerical character in data parsing\n");
			all->isok += 1000;
		}
		i++;
	}
	return (r);
}

char		*ft_strdup(char *s)
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

void		ft_freesplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
