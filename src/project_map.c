/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:23:46 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:48 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_map(t_point *ptr, t_ptr *p)
{
	double temp;

	if (p->perspective)
	{
		temp = SIZE_Y / (p->zoom + ptr->nz);
		ptr->nx = ptr->nx * temp + p->size_x;
		ptr->ny = ptr->ny * temp + p->size_y;
	}
	else
	{
		temp = SIZE_Y / (p->zoom);
		ptr->nx = ptr->nx * temp + p->size_x;
		ptr->ny = ptr->ny * temp + p->size_y - ptr->nz;
	}
}
