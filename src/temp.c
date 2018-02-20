int		main(int argc, char **argv)
{
	int fd;
	char *line;
	char **arr;
	t_point *point = NULL;
	int x;
	int y = 0;
	int i;
	int a;
	int b;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			i = 0;
			x = 0;
			arr = ft_strsplit(line, ' ');
			while (arr[i])
				ft_pointadd(&point, ft_pointcreate(x++, y, arr[i++]));
			ft_strdel(&line);
			ft_strdel(arr);
			y++;
		}
		a = x; //the number of columns
		b = y; //the number of rows
		while (point->prev)
			point = point->prev;
		while (point)
		{
			printf("%d\n", point->z);
			point = point->next;
		}
	}
	return (0);
}

void 	ft_pointadd(t_point **point, t_point *new)
{
	if (*point)
	{
		(*point)->next = new;
		new->prev = *point;	
	}
	*point = new;
}

t_point		*ft_pointcreate(int x, int y, char *z)
{
	t_point	*point;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		return (0);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(z);
	point->prev = NULL;
	point->next = NULL;
	return (point);
}