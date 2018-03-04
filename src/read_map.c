/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:23:55 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:57 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*ft_create_first_elem(t_ptr *p, char **arr)
{
	t_point *begin;

	add_point(&p->point, create_point(p->x++, p->y, arr[p->i], p));
	begin = p->point;
	p->minz = begin->z;
	ft_strdel(&arr[p->i++]);
	return (begin);
}

int				read_map(char *map, t_ptr *p)
{
	char	*line;
	char	**arr;
	t_point	*begin;

	p->fd = open(map, O_RDONLY);
	while (get_next_line(p->fd, &line) > 0 && (arr = ft_strsplit(line, ' ')))
	{
		p->i = 0;
		p->x = 0;
		if (!*arr)
			return (0);
		(!p->y) ? begin = ft_create_first_elem(p, arr) : 0;
		while (arr[p->i])
		{
			add_point(&p->point, create_point(p->x++, p->y, arr[p->i], p));
			ft_strdel(&arr[p->i++]);
		}
		ft_strdel(&line);
		ft_memdel((void **)&arr);
		p->y++;
	}
	if (!p->i)
		return (0);
	p->point = begin;
	return (1);
}
