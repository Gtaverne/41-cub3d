/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:42:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 14:42:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_mapsquare(t_all *all, int i, int j, int color)
{
	int	k;
	int	l;

	k = 0;
	while (k < MINIMAP)
	{
		l = 0;
		while (l < MINIMAP)
		{
			my_mlx_pixel_put(all, MINIMAP * (j + 1) + k,
			MINIMAP * (i + 1) + l, color);
			l++;
		}
		k++;
	}
}

void	put_player(t_all *all)
{
	int	i;

	i = 0;
	my_mlx_pixel_put(all, (int)(MINIMAP * (all->xpos + 1)),
	(int)(MINIMAP * (all->ypos + 1)), PLYR);
	while (i < 3 * MINIMAP / 2)
	{
		my_mlx_pixel_put(all, (int)(MINIMAP * (1 + all->xpos) + i *
		(cos(FOV) * all->xdir - sin(FOV) * all->ydir)),
		(int)(MINIMAP * (1 + all->ypos) + i *
		(sin(FOV) * all->xdir + cos(FOV) * all->ydir)), PLYR);
		my_mlx_pixel_put(all, (int)(MINIMAP * (1 + all->xpos) + i *
		(cos(-FOV) * all->xdir - sin(-FOV) * all->ydir)),
		(int)(MINIMAP * (1 + all->ypos) + i *
		(sin(-FOV) * all->xdir + cos(-FOV) * all->ydir)), PLYR);
		i++;
	}
}

void	my_minimap(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	if (all->mapheight * (MINIMAP + 3) > all->y_screen ||
	all->mapwdth * (MINIMAP + 3) > all->x_screen)
		return ;
	while (i < all->mapheight)
	{
		j = 0;
		while (j < all->mapwdth)
		{
			if (all->map[i][j] == '0')
				put_mapsquare(all, i, j, 0);
			else if (all->map[i][j] == '1')
				put_mapsquare(all, i, j, 255 * 255);
			else if (all->map[i][j] == '2')
				put_mapsquare(all, i, j, 110000);
			j++;
		}
		i++;
	}
}

int		raycasting2(t_all *all)
{
	ft_mvt(all);
	ft_sprite(all);
	my_minimap(all);
	put_player(all);
	ft_printframe(all);
	return (0);
}
