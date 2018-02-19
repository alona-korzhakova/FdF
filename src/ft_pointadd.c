
#include "fdf.h"

void 	ft_pointadd(t_point **point, t_point *new)
{
	if (*point)
	{
		(*point)->next = new;
		new->prev = *point;	
	}
	*point = new;
}