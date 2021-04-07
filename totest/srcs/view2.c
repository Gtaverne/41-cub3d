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
			my_mlx_pixel_put(all, MINIMAP * (j + 1) + k, MINIMAP * (i + 1) + l, color);
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
	while (i < MINIMAP)
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
	if (all->mapheight * (MINIMAP + 3) > all->y_screen || all->mapwdth * (MINIMAP + 3) > all->x_screen)
		return ;
	while (i < all->mapheight)
	{
		j = 0;
		while (j < all->mapwdth)
		{
			if (all->map[i][j] == '0')
				put_mapsquare(all, i, j, 0);
			else if (all->map[i][j] == '1')
				put_mapsquare(all, i, j, 10000);
			else if (all->map[i][j] == '2')
				put_mapsquare(all, i, j, 110000);
			j++;
		}
		i++;
	}

}

int		raycasting(t_all *all)
{
	all->col = 0;
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	while (all->col < all->x_screen)
	{
		all->xc = - 2 * all->col / (double)all->x_screen + 1;
		all->xmap = (int)all->xpos;
		all->ymap = (int)all->ypos;
		all->rdirx = all->xdir + all->xcam * all->xc;
		all->rdiry = all->ydir + all->ycam * all->xc;
		if (all->rdirx == 0)
			all->deltadistx = 10000000;
		else
			all->deltadistx = f_abs(1 / all->rdirx);
		if (all->rdiry == 0)
			all->deltadisty = 10000000;
		else
			all->deltadisty = f_abs(1 / all->rdiry);
		ft_step(all);
		all->bufferdist[all->col] = all->walldist;
		all->col++;
	}
	my_minimap(all);
	ft_mvt(all);
	put_player(all);
	ft_sprite(all);
	return (0);
}


