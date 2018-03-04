/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:16:49 by akorzhak          #+#    #+#             */
/*   Updated: 2018/02/18 14:16:51 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SIZE_X 1700
# define SIZE_Y 1200

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			nx;
	double			ny;
	double			nz;
	struct s_point	*next;
}					t_point;

typedef struct		s_ptr
{
	void			*mlx;
	void			*win;
	void			*img;
	int				fd;
	int				i;
	int				zoom;
	int				bpp;
	int				size_line;
	int				end;
	int				size_x;
	int				size_y;
	int				color;
	char			*addr;
	double			x;
	double			y;
	double			a;
	double			b;
	double			lz;
	double			lx;
	char			perspective;
	double			z;
	double			minz;
	t_point			*point;
}					t_ptr;

typedef struct		s_dot
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	double			x0;
	double			y0;
	double			x1;
	double			y1;

}					t_dot;

int					read_map(char *map, t_ptr *p);
int					ft_error(void);
int					ft_usage(void);
void				initialize_ptr(t_ptr *p);
void				add_point(t_point **point, t_point *new);
t_point				*create_point(int x, int y, char *z, t_ptr *p);
void				center_map(t_ptr *p);
void				rotate_map(t_point *ptr, t_ptr *p);
void				project_map(t_point *ptr, t_ptr *p);
void				draw_image(t_ptr *p);
void				connect_dots(t_dot *d, t_ptr *p);
void				draw_pixel(int x, int y, t_ptr *p);
int					handle_key(int keycode, t_ptr *p);
int					exit_fdf(t_ptr *p);

#endif
