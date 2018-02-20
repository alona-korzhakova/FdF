
#include "fdf.h"

void 	addPoint(t_point **point, t_point *new)
{
	if (*point)
		(*point)->next = new;
	*point = new;
}
