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
# include "../mlx-linux/mlx.h"
# include <math.h>

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
	int				mapwdth;
	int				initpos[3];

	/* Puis, le reste */

    void		*mlx;
	void        *img;
	void		*win;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_all;

/*cub3d*/
void	ft_printall(t_all all);
int		main (int argc, char **argv);

/* gnl & gn_utils*/
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_joinofgnl(char *s1, char *s2);
int		ft_hasnewline(char *str);
char	*ft_majtmp(char *tmp);
char	*ft_newline(char *tmp);

/*parserdata*/
int		ft_parserdata(t_all *all, int fd, char *line);
void	ft_ispath(t_all *all, char **words);

/*parsermap*/
void	ft_firstmapline (t_all *all, int fd, char *line);
int		ft_validmap(t_all *all);
void	ft_spacepad(t_all *all);
int		ft_parsermap(t_all *all, int fd, char *line);
void	ft_mempos(t_all *all, int i, int j);
int		ft_testpos(t_all *all, int i, int j);

/*split*/
char	**ft_split(char *str, char *charset);
int		is_insep(char c, char *sep);

/*randomutils*/
void	ft_initall(t_all *all);
int		ft_atoi(char *str);
char	*ft_strdup(char *s);
void	ft_freesplit(char **str);
void	ft_finalcheck(t_all *all);

/*view*/
int 	ft_view(t_all *all);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*view2*/
int		ft_testview(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);




/*Clean exit*/
void	ft_cleanstruct(t_all *all);

#endif
