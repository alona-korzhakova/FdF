/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:10:34 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 15:10:36 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(int x, int y, t_ptr *p)
{
	int		i;
	t_point	*ptr;

	ptr = p->point;
	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
	{
		i = x * p->bpp + y * p->size_line;
		p->addr[i] = p->color;
		p->addr[++i] = p->color >> 8;
		p->addr[++i] = p->color >> 16;
	}
}
