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
# include <fcntl.h> //(open)
# include <math.h>

# define ABS(Value) (Value < 0) ? (-Value) : (Value)
# define SIZE_X 600
# define SIZE_Y 600


typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			nx;
	double 			ny;
	double			nz;
	struct s_point	*next;
}					t_point;

typedef struct		s_ptr
{
	int				fd;
	int				i;
	int				zoom;
	void			*mlx;
	void			*win;
	double			x;
	double 			y;
	double			a;
	double			b;
	double			Lz;
	double 			Lx;
	t_point 		*point;
}					t_ptr;

void 		addPoint(t_point **point, t_point *new);
t_point		*createPoint(int x, int y, char *z);
t_point 	*rotateMap(t_point *newp, t_ptr *p);
t_point 	*projectMap(t_point *point, t_ptr *p);

#endif

	// 