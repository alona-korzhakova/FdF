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

# define ABS(Value) (Value < 0) ? (-Value) : (Value)

typedef struct		s_flags
{
	char			min;
	char			plus;
	char			space;
	char			sharp;
	char			zero;
	int				wd;
	char			dot;
	int				prc;
	char			hh;
	char			ll;
	char			h;
	char			l;
	char			j;
	char			z;
}					t_flags;

#endif
