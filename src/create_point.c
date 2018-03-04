/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:23:00 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:02 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*create_point(int x, int y, char *z, t_ptr *p)
{
	t_point	*point;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		return (0);
	point->x = x;
	point->y = y;
	point->z = -ft_atoi(z);
	if (point->z > p->minz)
		p->minz = point->z;
	point->next = NULL;
	return (point);
}
