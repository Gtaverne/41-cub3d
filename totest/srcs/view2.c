#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		raycasting(t_all *all)
{
	/*
	mlx_put_image_to_window(mlx, mlx_win, all->img, 0, 0);
	la fonction à mettre dans une boucle
	Faire la minimap
	*/
	all->isok *=10000;
	return (0);
}

int		ft_testview(t_all *all)
{
	//int 	i;

	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->x_screen, all->y_screen, "Dudule forever");
	//Raycasting, ma fonction appelée à chaque tour. 
	//mlx_loop_hook(mlx, rayacasting, all);
	all->img = mlx_new_image(all->mlx, all->x_screen, all->y_screen);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length,
								 &all->endian);
		mlx_loop(all->mlx);
	all->img = all->img + 0;
	all->isok +=10000;
	return(0);
}

