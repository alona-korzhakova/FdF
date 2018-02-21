
#include "fdf.h"

t_point 	*projectMap(t_point *point, t_ptr *p)
{
	t_point *begin;
	double temp;

	begin = point;
	while (point)
	{
		temp = SIZE_Y / (p->zoom + point->nz)
		point->nx = point->nx * temp + SIZE_X / 2;
		point->ny = point->nx * temp + SIZE_Y / 2;
		point = point->next;
	}
	return (begin);
}