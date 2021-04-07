#include "../includes/cub3d.h"

void	ft_permusprite(t_all *all, int i, int j)
{
	double	temp;
	int		k;

	k = -1;
	while (++k < 3)
	{
		temp = all->spritab[i][k];
		all->spritab[i][k] = all->spritab[j][k];
		all->spritab[j][k] = temp;
	}
}

void	ft_spritri(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	while(++i < all->sprcount)
	{
		j = i;
		while(++j < all->sprcount)
		{
			if (all->spritab[i][2] < all->spritab[j][2])
				ft_permusprite(all, i, j);
		}
	}
}

void	ft_spritecol(t_all *all, int j)
{
	int		d;
	int		k;

	all->xtex = abs((256 * (j - (all->sprxscreen - all->sprwidth / 2)) 
	* all->text[4].width / all->sprwidth)/ 256);
	if (all->sprytrans > 0 && j > 0 && j < all->x_screen 
	&& all->sprytrans < all->bufferdist[j])
	{
		k = all->topline - 1;
		while (++k < all->botline)
		{
			d = k * 256 + 128 * all->sprheight - 128 * all->y_screen;
			all->ytex = abs(((d * all->text[4].height) / all->sprheight) / 256);

				if (*(unsigned int *)(all->text[4].add + 
				all->text[4].line_length * all->ytex + all->xtex * 4) != 1)
					*(unsigned int *)(all->addr + (k * all->line_length + j * 4))
					= *(unsigned int *)(all->text[4].add + all->text[4].line_length * all->ytex + all->xtex * 4);
		}
	}
}


void	ft_sprite2(t_all *all)
{
	int j;

	all->topline = -all->sprheight / 2 + all->y_screen / 2 ;
	if (all->topline < 0)
		all->topline = 0;
	all->botline = all->y_screen/ 2 + all->sprheight / 2;
	if (all->botline > all->y_screen)
		all->botline = all->y_screen - 1;
	all->sprwidth = (int)f_abs(all->y_screen / all->sprytrans);
	all->drawxstart = -all->sprwidth / 2 + all->sprxscreen;
	if (all->drawxstart < 0)
		all->drawxstart = 0;
	all->drawxend = all->sprxscreen + all->sprwidth / 2;
	if (all->drawxend > all->x_screen)
		all->drawxend = all->x_screen - 1;
	j = all->drawxstart - 1;
	while (++j < all->drawxend)
		ft_spritecol(all, j);
}

void	ft_sprite(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->sprcount)
	{
		all->spritab[i][2] = (all->spritab[i][1] - all->xpos) * (all->spritab[i][1] 
		- all->xpos) + (all->spritab[i][0] - all->ypos) * (all->spritab[i][0] - all->ypos);
	}
	ft_spritri(all);

	i = -1;
	while (++i < all->sprcount)
	{
		all->xspr = all->spritab[i][1] - all->xpos;
		all->yspr = all->spritab[i][0] - all->ypos;
		all->invdet = 1.0 / (all->xcam * all->ydir - all->ycam * all->xdir);
		all->sprxtrans = all->invdet *(all->ydir * all->xspr 
		- all->xdir * all->yspr);
		all->sprytrans = all->invdet * (-all->ycam * all->xspr 
		+ all->xcam * all->yspr);
		all->sprxscreen = (int)((all->x_screen / 2) * (1 +
		all->sprxtrans / all->sprytrans));
		all->sprheight = abs((int)(all->y_screen / all->sprytrans));
		ft_sprite2(all);
	}
}