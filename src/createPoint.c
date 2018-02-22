
#include "fdf.h"

t_point		*createPoint(int x, int y, char *z)
{
	t_point	*point;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		return (0);
	point->x = x;
	point->y = y;
	point->z = -ft_atoi(z);
	point->next = NULL;
	return (point);
}
