/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:21:33 by user42            #+#    #+#             */
/*   Updated: 2021/03/08 23:21:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mempos2(t_all *all, int i, int j)
{
	if (all->map[i][j] == 'N')
	{
		all->ydir = -1;
		all->xcam = tan(FOV);
	}
	if (all->map[i][j] == 'E')
	{
		all->xdir = 1;
		all->ycam = tan(FOV);
	}
	if (all->map[i][j] == 'S')
	{
		all->ydir = 1;
		all->xcam = -tan(FOV);
	}
	if (all->map[i][j] == 'W')
	{
		all->xdir = -1;
		all->ycam = -tan(FOV);
	}
	all->xpos = (double)j + 0.5;
	all->ypos = (double)i + 0.5;
	all->map[i][j] = '0';
	all->isok += 100;
}

int		ft_testpos(t_all *all, int i, int j)
{
	if (i == 0 || j == 0 || j == all->mapwdth || !(all->map[i + 1]))
	{
		printf("Error\nWrong character on a map edge\n\
		lin: %d col: %d\n", i, j);
		all->isok += 1000;
		return (0);
	}
	if (all->map[i - 1][j - 1] == ' ' || all->map[i - 1][j] == ' ' || \
	all->map[i - 1][j + 1] == ' ' || all->map[i][j - 1] == ' ' ||\
	all->map[i][j + 1] == ' ' || all->map[i + 1][j - 1] == ' ' ||\
	all->map[i + 1][j] == ' ' || all->map[i + 1][j + 1] == ' ')
	{
		printf("Error\nWrong character on a map edge\n\
		lin: %d col: %d\n", i, j);
		all->isok += 1000;
		return (0);
	}
	return (1);
}

void	ft_mempos(t_all *all, int i, int j)
{
	if (all->xpos != -1 || all->ypos != -1)
	{
		all->isok += 1000;
		return ;
	}
	else
		ft_mempos2(all, i, j);
}

void	ft_spritestock(t_all *all)
{
	int	i;
	int	j;
	int k;

	i = -1;
	k = 0;
	while (++i < all->mapheight)
	{
		j = -1;
		while (++j < all->mapwdth)
		{
			if (!all->map[i][j])
				return ;
			if (all->map[i][j] == '2')
			{
				if (k == 500)
					printf("Exit, too many sprites\n");
				all->spritab[k][0] = i + 0.5;
				all->spritab[k][1] = j + 0.5;
				k++;
			}
		}
	}
	all->sprcount = k;
}

void	ft_invalidcharacter(t_all *all, int i, int j)
{
	all->isok += 1000;
	printf("Error\nInvalid character in map \n\
	lin: %d col: %d char: %c\n", i, j, all->map[i][j]);
	ft_cleanstruct(all);
}
