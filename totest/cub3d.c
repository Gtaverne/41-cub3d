/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:47:55 by gtaverne          #+#    #+#             */
/*   Updated: 2021/03/01 12:47:59 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_printall(t_all all)
{
	int i;

	i = 0;
	printf("\nPrint all_______________\n");
	printf("All is ok ? %d\n", all.isok);
	printf("Res x: %d y: %d\n", all.x_screen, all.y_screen);
	printf("RGB Ceil: %d RGBFloor: %d\n", all.ceil_rgb, all.floor_rgb);
	printf("Addresses:\n%s\n%s\n%s\n%s\n%s\n", all.no_path, all.so_path,
	all.we_path, all.ea_path, all.s_path);
	while (all.map[i])
	{
		printf("%s\n", all.map[i]);
		i++;
	}
	printf("initpos: %f %f %f %f\n", all.xdir, all.ydir, all.xpos,
	all.ypos);
	printf("Width: %d  Height: %d \n", all.mapwdth, all.mapheight);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_all	all;
	char	*line;

	if (ft_save(&all, argc, argv) == 0)
		return (0);
	line = NULL;
	ft_initall(&all);
	fd = open(argv[1], O_RDONLY);
	if (ft_parserdata(&all, fd, line) && ft_parsermap(&all, fd, line))
		printf("Successful parsing\n");
	else
	{
		printf("Wrong map file\n");
		ft_cleanstruct(&all);
		return (0);
	}
	ft_printall(all);
	ft_testview(&all);
	ft_cleanstruct(&all);
	return (1);
}
