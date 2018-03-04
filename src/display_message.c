/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:23:13 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:15 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(void)
{
	ft_putstr("error: invalid or empty file\n");
	return (-1);
}

int		ft_usage(void)
{
	ft_putstr("usage: fdf input_file\n");
	return (-1);
}

int		exit_fdf(t_ptr *p)
{
	close(p->fd);
	ft_putstr("FdF has been closed.\n");
	exit(0);
	return (0);
}
