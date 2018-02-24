
#include "fdf.h"

void 	rotateMap(t_point *ptr, t_ptr *p)
{
	double y;
	double z;

	if (ptr->z == 0)
		z = ptr->z;
	else
	{
		z = ptr->z + p->z;
		if (z > 0)
			z = 0;
	}
	ptr->nx = ptr->x * cos(p->Lz) - ptr->y * sin(p->Lz);
	ptr->ny = ptr->x * sin(p->Lz) + ptr->y * cos(p->Lz);
	y = ptr->ny * cos(p->Lx) + z * sin(p->Lx);
	ptr->nz = -(ptr->ny) * sin(p->Lx) + z * cos(p->Lx);
	ptr->ny = y;
	projectMap(ptr, p);
}