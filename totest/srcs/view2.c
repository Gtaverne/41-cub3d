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
			my_mlx_pixel_put(all, MINIMAP * (i + 1) + k, MINIMAP * (j + 1) + l, color);
			l++;
		}
		k++;
	}
}

void	my_minimap(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	if (all->mapheight * (MINIMAP + 3) > all->y_screen || all->mapwdth * (MINIMAP + 3) > all->x_screen)
		return ;
	while (i < all->mapwdth)
	{
		j = 0;
		while (j < all->mapheight)
		{
			if (all->map[j][i] == '0')
				put_mapsquare(all, i, j, 0);
			else if (all->map[j][i] == '1')
				put_mapsquare(all, i, j, 10000);
			else if (all->map[j][i] == '2')
				put_mapsquare(all, i, j, 110000);
			j++;
		}
		i++;
	}
	put_mapsquare(all, (int)all->xpos, (int)all->ypos, 16711680);
}

int		raycasting(t_all *all)
{
	my_minimap(all);

	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	/*
	la fonction à mettre dans une boucle
	Faire la minimap
	*/
	all->isok +=10000;
	return (0);
}

int		ft_testview(t_all *all)
{
	//int 	i;

	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->x_screen, all->y_screen, "Dudule forever");
	//Raycasting, ma fonction appelée à chaque tour. 
	mlx_loop_hook(all->mlx, raycasting, all);
	mlx_hook(all->win, 2, 1L << 0, ft_key_hook, all);
        mlx_hook(all->win, 3, 1L << 1, ft_key_unhook, all);
	all->img = mlx_new_image(all->mlx, all->x_screen, all->y_screen);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length,
								 &all->endian);
		mlx_loop(all->mlx);
	all->img = all->img + 0;
	all->isok +=10000;
	return(0);
}

