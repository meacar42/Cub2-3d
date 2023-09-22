/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:16:41 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:36:09 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "fcntl.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "math.h"
# include "mlx/mlx.h"
# include <stdio.h>

# define S 35
# define W 39
# define E 21
# define N 30

# define ESC 53
# define KW 13
# define KA 0
# define KS 1
# define KD 2
# define LEFT 123
# define RIGHT 124
# define M 46

# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_key
{
	int					w_key;
	int					s_key;
	int					d_key;
	int					a_key;
	int					esc_key;
	int					cam_left;
	int					cam_right;
	int					map_key;
}						t_key;

typedef struct s_map
{
	int					map_l;
	int					map_w;
	int					**i_map;
	char				**map;
	char				*we;
	char				*ea;
	char				*so;
	char				*no;
	int					*i_we;
	int					*i_ea;
	int					*i_so;
	int					*i_no;
	void				*n_o;
	void				*s_o;
	void				*w_e;
	void				*e_a;
	char				*f;
	char				*c;
}						t_map;

typedef struct s_rgb
{
	unsigned long long	r;
	unsigned long long	g;
	unsigned long long	b;
	unsigned long long	t;
}						t_rgb;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*addr;
	int					bpp;
	int					sl;
	int					end;
	int					m_w;
	int					m_h;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				raydirx;
	double				raydiry;
	double				old;
	double				old2;
	double				rotate_speed;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	double				wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	double				wall_y;
	double				wallx;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					mx;
	int					my;
	double				pixel_cal;
	double				pixel_nbr;
	double				move_speed;
	int					colour;
	char				player_direction;
	double				x_loc_p;
	double				y_loc_p;
}						t_game;

typedef struct s_data
{
	t_key				key;
	t_game				game;
	t_map				map;
	t_rgb				floor;
	t_rgb				sky;
	char				*tmp;
	char				**tmpf;
	char				**tmpc;
	int					counter;
	int					fd;
	int					i;
	int					j;
}						t_data;

void					filecheck(t_data *bm, char **ag);
int						set_check_args(t_data *bm, int flag);
int						set_arg(t_data *bm, char *str);
void					check_arg(t_data *bm, char *str);
int						check_wall(char *tmp);
void					check_tmp(char *tmp);
void					error(void);
int						map_count(char **ag);
void					check_map(t_data *bm);
void					map_convert(t_data *bm);
int						ft_wmaplen(char *tmp);
void					i_map_set(t_data *bm);
void					map_checker(t_data *bm);
int						check_wall_player(t_data *bm);
void					find_loc_player(t_data *bm);
void					check_cub(char **ag);
char					*path_ret(char *tmp);
void					location_path_check(t_data *bm);
void					path_check(t_data *bm);
void					trim_nline(char *tmp);
void					check_xpm(t_data *bm);
void					color_val_check(t_data *bm);
void					comma_check(t_data *bm);
void					color_extra_check(t_data *bm);
void					color_set(t_data *bm);
int						color_max_min(int i);
void					cam_left(t_data *bm);
void					cam_right(t_data *bm);
int						close_window(t_data *bm);
void					start_val(t_data *bm);
int						screen_fill(t_data *bm);
void					draw_image(t_data *bm, int i);
void					game_image(t_data *bm);
void					set_image_values(t_data *bm);
void					get_dist(t_data *bm);
void					hitcheck(t_data *bm);
void					wallcheck(t_data *bm);
void					set_data(t_data *bm, int width);
void					color_painting(t_data *bm);
void					get_color(t_data *bm);
void					start(t_data *bm);
void					move_func(t_data *bm);
void					move_left(t_data *bm);
void					move_right(t_data *bm);
int						move_1(int key, t_data *bm);
int						move_2(int key, t_data *bm);
void					move_forward(t_data *bm);
void					move_backward(t_data *bm);

#endif