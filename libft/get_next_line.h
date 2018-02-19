/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:49:06 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/29 14:49:09 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h> //for main (open)

# define BUFF_SIZE 1024

typedef struct		s_dlist
{
	char			*buff;
	int				fd;	
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int		get_next_line(const int fd, char **line);

#endif
