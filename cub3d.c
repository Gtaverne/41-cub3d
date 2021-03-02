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

int	main (int argc, char **argv)
{
	int		fd;
	t_all	all;
	char	*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_parserdata(all, fd, line);
	return (1);
}