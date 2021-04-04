#include "../includes/cub3d.h"

void	ft_step(t_all *all)
{
	all->hit = 0;
	if (all->rdirx < 0)
	{
		all->stepx = -1;
		all->sidedistx = (all->xpos - all->xmap) * all->deltadistx;
	}
	else
	{
		all->stepx = 1;
		all->sidedistx = (all->xmap + 1.0 - all->xpos) * all->deltadistx;
	}
	if (all->rdiry < 0)
	{
		all->stepy = -1;
		all->sidedisty = (all->ypos - all->ymap) * all->deltadisty;
	}
	else
	{
		all->stepy = 1;
		all->sidedisty = (all->ymap + 1.0 - all->ypos) * all->deltadisty;
	}
	ft_hit(all);
}

void	ft_hit(t_all *all)
{
	while (all->hit == 0)
	{
		if(all->sidedistx < all->sidedisty)
		{
			all->sidedistx += all->deltadistx;
        	all->xmap += all->stepx;
        	all->side = 0;
        }
        else
        {
        	all->sidedisty += all->deltadisty;
        	all->ymap += all->stepy;
        	all->side = 1;
        }
        if(all->map[all->ymap][all->xmap] != '0')
			all->hit = 1;
	}
	if (all->side == 0)
		all->walldist = (all->xmap - all->xpos + (1 - all->stepx) / 2) 
		/ all->rdirx;
	else
		all->walldist = (all->ymap - all->ypos + (1 - all->stepy) / 2)
		/ all->rdiry;
	ft_colplot(all);
}

void	ft_colplot(t_all *all)
{
	int	i;
	int	bord;

	all->vertl = (int)(all->y_screen / (all->walldist + 0.00001));
	i = 0;
	bord = (all->y_screen - all->vertl);
	if (bord < 0)
		bord = 0;
	while (i < bord / 2)
	{
		my_mlx_pixel_put(all, all->col, i, all->floor_rgb);
		my_mlx_pixel_put(all, all->col, all->y_screen - i, all->ceil_rgb);		
		i++;
	}
	while (i < all->y_screen - bord / 2)
	{
		my_mlx_pixel_put(all, all->col, i, 60000 + all->side * 10000);
		i++;
	}
	if (i < all->y_screen)
		my_mlx_pixel_put(all, all->col, i, 60000 + all->side * 10000);
}