/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_dots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:08:06 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 15:08:08 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_high_angle_line(t_dot *d, t_ptr *p)
{
	int x;
	int y;
	int i;

	i = 1;
	d->d = (d->dx << 1) - d->dy;
	d->d1 = d->dx << 1;
	d->d2 = (d->dx - d->dy) << 1;
	x = d->x0;
	y = d->y0 + d->sy;
	while (i <= d->dy)
	{
		if (d->d > 0)
		{
			d->d += d->d2;
			x += d->sx;
		}
		else
			d->d += d->d1;
		draw_pixel(x, y, p);
		i++;
		y += d->sy;
	}
}

void	draw_low_angle_line(t_dot *d, t_ptr *p)
{
	int x;
	int y;
	int i;

	i = 1;
	d->d = (d->dy << 1) - d->dx;
	d->d1 = d->dy << 1;
	d->d2 = (d->dy - d->dx) << 1;
	x = d->x0 + d->sx;
	y = d->y0;
	while (i <= d->dx)
	{
		if (d->d > 0)
		{
			d->d += d->d2;
			y += d->sy;
		}
		else
			d->d += d->d1;
		draw_pixel(x, y, p);
		i++;
		x += d->sx;
	}
}

void	connect_dots(t_dot *d, t_ptr *p)
{
	d->dx = fabs(d->x1 - d->x0);
	d->dy = fabs(d->y1 - d->y0);
	d->sx = (d->x1 >= d->x0) ? 1 : -1;
	d->sy = (d->y1 >= d->y0) ? 1 : -1;
	if (d->dy <= d->dx)
		draw_low_angle_line(d, p);
	else
		draw_high_angle_line(d, p);
}
