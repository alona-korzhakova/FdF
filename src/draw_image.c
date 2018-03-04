/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:23:24 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:26 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_line(int i, t_dot *d, t_point *ptr, t_ptr *p)
{
	d->x1 = ptr->next->nx;
	d->y1 = ptr->next->ny;
	if (i % (int)p->x != 0)
		connect_dots(d, p);
}

void	draw_vertical_line(t_dot *d, t_point *upper_dot, t_ptr *p)
{
	d->x1 = upper_dot->nx;
	d->y1 = upper_dot->ny;
	connect_dots(d, p);
}

void	create_image(t_ptr *p)
{
	int		i;
	t_dot	d;
	t_point	*ptr;
	t_point	*upper_dot;

	i = 0;
	ptr = p->point;
	upper_dot = p->point;
	while (ptr)
	{
		i++;
		d.x0 = ptr->nx;
		d.y0 = ptr->ny;
		draw_pixel(d.x0, d.y0, p);
		if (i > p->x)
		{
			draw_vertical_line(&d, upper_dot, p);
			upper_dot = upper_dot->next;
		}
		if (ptr->next)
			draw_horizontal_line(i, &d, ptr, p);
		ptr = ptr->next;
	}
}

void	draw_image(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, SIZE_X, SIZE_Y);
	p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->size_line), &(p->end));
	p->bpp /= 8;
	create_image(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}
