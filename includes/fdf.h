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
# include "get_next_line.h"
# include "mlx.h"
# include <stdio.h>

# define ABS(Value) (Value < 0) ? (-Value) : (Value)

typedef struct		s_ptr
{
	void			*mlx;
	void			*win;
}					t_ptr;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
	struct s_point	*prev;
}					t_point;

void 	ft_pointadd(t_point **point, t_point *new);
t_point		*ft_pointcreate(int x, int y, char *z);

#endif
