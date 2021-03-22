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

void	ft_mempos(t_all *all, int i, int j)
{
	if (all->initpos[0] != 0)
	{
		all->isok += 1000;
		return;
	}
	if (all->map[i][j] == 'N')
		all->initpos[0] = 1;
	if (all->map[i][j] == 'E')
		all->initpos[0] = 2;
	if (all->map[i][j] == 'S')
		all->initpos[0] = 3;
	if (all->map[i][j] == 'W')
		all->initpos[0] = 4;
	all->initpos[1] = i;
	all->initpos[2] = j;
	all->map[i][j] = '0';
	all->isok += 100;
}

int		ft_testpos(t_all *all, int i, int j)
{
	if (i == 0 || j == 0 || j == all->mapwdth || !(all->map[i+1]))
	{
		printf("Invalid map, 0 on an edge, lin: %d col: %d\n", i, j);
		all->isok += 1000;
		return (0);
	}
	if (all->map[i - 1][j - 1] == ' ' || all->map[i - 1][j] == ' ' || \
	all->map[i - 1][j + 1] == ' ' || all->map[i][j - 1] == ' ' ||\
	all->map[i][j + 1] == ' ' || all->map[i + 1][j - 1] == ' ' ||\
	all->map[i + 1][j] == ' ' || all->map[i + 1][j + 1] == ' ')
	{
		printf("Invalid map, 0 on an edge, lin: %d col: %d\n", i, j);
		all->isok += 1000;
		return (0);
	}	
	return (1);
}
