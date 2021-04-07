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
        if(all->map[all->ymap][all->xmap] == '1')
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

void	ft_texcal(t_all* all)
{
	if (all->side == 0 && all->rdirx < 0)
		all->side += 2;
	if (all->side == 1 && all->rdiry < 0 )
		all->side += 2;
}

void	ft_colplot(t_all *all)
{
	if (all->side == 0)
		all->wallx = all->ypos + all->walldist * all->rdiry;
	else
		all->wallx = all->xpos + all->walldist * all->rdirx;
	all->wallx -= floor((all->wallx));
	ft_texcal(all);
	all->xtex = (int)(all->wallx * (double)(all->text)[all->side].width);
	if (all->side % 2 == 0 && all->rdirx > 0)
		all->xtex = (double)(all->text)[all->side].width - all->xtex - 1;
	if (all->side % 2 == 1 && all->rdiry > 0)
		all->xtex = (double)(all->text)[all->side].width - all->xtex - 1;
	all->vertl = (int)(all->y_screen / (all->walldist + 0.00001));
	all->topline = all->y_screen / 2 - all->vertl / 2;
	if (all->topline < 0)
		all->topline = 0;
	all->botline = all->y_screen / 2 + all->vertl / 2;
	if (all->botline >= all->y_screen)
		all->botline = all->y_screen - 1;
	ft_colplot2(all);
}

void	ft_colplot2(t_all *all)
{
	int		i;

	i = 0;
	all->verstep = 1.0 * all->text[all->side].height / all->vertl;
	all->texpos = (all->topline + all->vertl / 2 - all->y_screen / 2)
	* all->verstep;
	while (i < all->topline)
	{
		my_mlx_pixel_put(all, all->col, i, all->ceil_rgb);
		i++;
	}
	while (i < all->botline)
	{
		all->ytex = (int)all->texpos & (all->text[all->side].height - 1);
		all->texpos += all->verstep;
		*(unsigned int *)(all->addr + (i * all->line_length + all->col * 4)) = 
		*(unsigned int *)(all->text[all->side].add +  all->ytex * 
		all->text[all->side].line_length + all->xtex * 4);
		i++;
	}
	while (i < all->y_screen)
	{
		my_mlx_pixel_put(all, all->col, i, all->floor_rgb);
		i++;
	}
}