/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:24:05 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:24:08 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map(t_point *ptr, t_ptr *p)
{
	double y;
	double z;

	if (ptr->z == p->minz)
		z = ptr->z;
	else
	{
		z = ptr->z + p->z;
		if (z > p->minz)
			z = p->minz;
	}
	ptr->nx = ptr->x * cos(p->lz) - ptr->y * sin(p->lz);
	ptr->ny = ptr->x * sin(p->lz) + ptr->y * cos(p->lz);
	y = ptr->ny * cos(p->lx) + z * sin(p->lx);
	ptr->nz = -(ptr->ny) * sin(p->lx) + z * cos(p->lx);
	ptr->ny = y;
	project_map(ptr, p);
}
