/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:23:38 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:40 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_map(t_ptr *p)
{
	t_point *ptr;

	ptr = p->point;
	while (ptr)
	{
		rotate_map(ptr, p);
		ptr = ptr->next;
	}
	draw_image(p);
}

static void		ft_change_color(t_ptr *p)
{
	if (p->color == 0xFFFFFF)
		p->color = 0xCC0000;
	else if (p->color == 0xCC0000)
		p->color = 0xFF6600;
	else if (p->color == 0xFF6600)
		p->color = 0xFFFF00;
	else if (p->color == 0xFFFF00)
		p->color = 0xBFFF00;
	else if (p->color == 0xBFFF00)
		p->color = 0x40FF00;
	else if (p->color == 0x40FF00)
		p->color = 0x4DD2FF;
	else if (p->color == 0x4DD2FF)
		p->color = 0x4D4DFF;
	else if (p->color == 0x4D4DFF)
		p->color = 0x7A00CC;
	else if (p->color == 0x7A00CC)
		p->color = 0xFF4DD2;
	else
		p->color = 0xFFFFFF;
}

int				handle_key(int keycode, t_ptr *p)
{
	(keycode == 123) ? p->lz += 0.2 : 0;
	(keycode == 124) ? p->lz -= 0.2 : 0;
	(keycode == 126) ? p->lx += 0.2 : 0;
	(keycode == 125) ? p->lx -= 0.2 : 0;
	(keycode == 0) ? p->size_x -= 10 : 0;
	(keycode == 2) ? p->size_x += 10 : 0;
	(keycode == 13) ? p->size_y += 10 : 0;
	(keycode == 1) ? p->size_y -= 10 : 0;
	(keycode == 49) ? initialize_ptr(p) : 0;
	(keycode == 27) ? p->zoom += 6 : 0;
	(keycode == 24) ? p->zoom -= 6 : 0;
	(keycode == 36) ? ft_change_color(p) : 0;
	(keycode == 121) ? p->z += 2 : 0;
	(keycode == 116) ? p->z -= 2 : 0;
	if (keycode == 35)
		p->perspective = p->perspective ? 0 : 1;
	(keycode == 53) ? exit_fdf(p) : 0;
	display_map(p);
	return (0);
}
