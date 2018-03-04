/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:22:49 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:22:52 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_ptr *p)
{
	t_point *temp;

	p->a = p->x / 2;
	p->b = p->y / 2;
	temp = p->point;
	while (temp)
	{
		temp->x = temp->x - p->a;
		temp->y = temp->y - p->b;
		rotate_map(temp, p);
		temp = temp->next;
	}
}
