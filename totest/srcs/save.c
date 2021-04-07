#include "../includes/cub3d.h"

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && --n && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

void	bmp_top_info(t_all *all, int fd)
{
	int buff;
	int i;

	write(fd, "BM", 2);
	buff = 14 + 40 + 4 * all->x_screen * all->y_screen;
	write(fd, &buff, 4);
	buff = 0;
	write(fd, &buff, 4);
	buff = 54;
	write(fd, &buff, 4);
	buff = 40;
	write(fd, &buff, 4);
	buff = all->x_screen;
	write(fd, &buff, 4);
	buff = all->y_screen;
	write(fd, &buff, 4);
	buff = 1;
	write(fd, &buff, 2);
	buff = all->bits_per_pixel;
	write(fd, &buff, 2);
	buff = 0;
	i = 0;
	while (i++ < 6)
		write(fd, &buff, 4);
}

void	screenshot(t_all *all)
{
	int fd;
	int	x;
	int	y;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR);
	bmp_top_info(all, fd);
	y = all->y_screen - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->x_screen)
		{
			write(fd, &all->addr[y * all->line_length + x * 4], 4);
			x++;
		}
		y--;
	}
}

void	ft_printframe(t_all *all)
{
	if (all->save == 1)
	{
		if ((MINIMAP + 2) * all->mapwdth <= all->x_screen &&
		(MINIMAP + 2) * all->ymap <= all->y_screen)
		{
			my_minimap(all);
			put_player(all);
		}
	}
}

int		ft_save(t_all *all, int argc, char **argv)
{
	all->save = 0;
	if (argc < 2 || argc > 3)
	{
		printf("Mauvais arguments, donnez le path d'une map et en option\
		'--save' \n");
		return (0);
	}
	if (argc == 2)
		return (1);
	else if (ft_strncmp(argv[3], "--save", 10) == 0)
	{
		all->save = 1;
		return (1);
	}
	else
		return (0);
}