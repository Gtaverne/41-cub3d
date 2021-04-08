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

# define MINIMAP 10
# define MVSPEED 4
# define ANGLE 1
# define FOV 0.5
# define PACE 100
# define PLYR 16000000

# ifndef BONUS
#  define BONUS 0
# endif

/*azerty linux*/
# ifdef __linux
#  define KEY_FORWARD 122
#  define KEY_BACKWARD 115
#  define KEY_LEFT 113
#  define KEY_RIGHT 100
#  define KEY_TURN_LEFT 65361
#  define KEY_TURN_RIGHT 65363
#  define KEY_ESCAPE 65307
# endif

/*qwerty MAC*/
# ifdef __APPLE__
#  define KEY_FORWARD 13
#  define KEY_BACKWARD 1
#  define KEY_LEFT 0
#  define KEY_RIGHT 2
#  define KEY_TURN_LEFT 123
#  define KEY_TURN_RIGHT 124
#  define KEY_ESCAPE 65307
# endif

typedef struct	s_xtur {
//	char	*path;
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_xtur;

typedef struct	s_all
{
	t_xtur			text[10];
	int				save;
	double			spritab[500][3];
	double			bufferdist[10000];
	int				isok;
	unsigned short	x_screen;
	unsigned short	y_screen;
	char			*no_path;
	char			*ea_path;
	char			*so_path;
	char			*we_path;
	char			*s_path;
	int				floor_rgb;
	int				ceil_rgb;
	char			*map[2048];
	int				mapwdth;
	int				mapheight;
	double			xpos;
	double			ypos;
	double			xdir;
	double			ydir;
	double			xcam;
	double			ycam;
	double			xspr;
	double			yspr;
	double			sprxtrans;
	double			sprytrans;
	int				sprxscreen;
	int				spryscreen;
	int				sprheight;
	int				sprwidth;
	int				sprcount;
	int				drawxstart;
	int				drawxend;
	double			invdet;

	/* Puis, le reste */

    void		*mlx;
	void        *img;
	void		*win;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			turn_left;
	int 		turn_right;
	int			escape;
	double		rdirx;
	double		rdiry;
	double		xc;
	int			xmap;
	int			ymap;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		walldist;
	double		wallx;
	int			xtex;
	int			ytex;
	int			side;
	int			stepx;
	int			stepy;
	int			hit;
	int			vertl;
	double		verstep;
	double		texpos;
	int			botline;
	int			topline;
	int			col;
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
void	ft_spritestock(t_all *all);

/*split*/
char	**ft_split(char *str, char *charset);
int		is_insep(char c, char *sep);

/*randomutils*/
void	ft_initall(t_all *all);
void	ft_initall2(t_all *all);
int		ft_atoi(char *str);
char	*ft_strdup(char *s);
void	ft_freesplit(char **str);
void	ft_finalcheck(t_all *all);
double	f_abs(double d);

/*view*/
void	ft_initext(t_all *all);

/*view2*/
int		ft_testview(t_all *all);
int		raycasting(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
void	put_player(t_all *all);
void	put_mapsquare(t_all *all, int i, int j, int color);
void	my_minimap(t_all *all);


void	ft_step(t_all *all);
void	ft_hit(t_all *all);
void	ft_colplot(t_all *all);
void	ft_colplot2(t_all *all);

/*sprite*/
void	ft_sprite(t_all *all);

/*hook*/
int     ft_key_hook(int n, t_all *all);
int     ft_key_unhook(int n, t_all *all);

/*mvmts*/
void    ft_forward(t_all *all);
void    ft_side(t_all *all);
void    ft_back(t_all *all);
void    ft_turn(t_all *all);
void    ft_mvt(t_all *all);

/*Save*/
int		ft_save(t_all *all, int argc, char **argv);
void	ft_printframe(t_all *all);

/*Clean exit*/
int		ft_cleanstruct(t_all *all);

#endif
