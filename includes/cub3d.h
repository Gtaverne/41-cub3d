/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:51:12 by gtaverne          #+#    #+#             */
/*   Updated: 2021/03/01 12:04:18 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_all
{
	/* D'abord, la map */
	int				isok;
	/* isok = XYZK is X > 0, error, Y = 1 if res ok,
	Z = 5 if all path are ok, K = 2 if rgb are ok*/
	unsigned short	x_screen;
	unsigned short	y_screen;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*s_path;
	int				floor_rgb;
	int				ceil_rgb;
	char			*map[2048];

	/* Puis, le reste */
}				t_all;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*ft_joinofgnl(char *s1, char *s2);
int		ft_hasnewline(char *str);
char	*ft_majtmp(char *tmp);
char	*ft_newline(char *tmp);

int		ft_parserdata(t_all all, int fd, char *line);
void	ft_initall(t_all all);
int		ft_atoi(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_strdup(char *s);

#endif
