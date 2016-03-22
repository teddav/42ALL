#include "push_swap.h"

void	push_a(t_pushswap *data)
{
	int		*new_pile_a;

	if (data->length_b > 0)
	{
		new_pile_a = (int *)ft_memalloc(sizeof(int) * (data->length_a + 1));
		ft_memcpy(new_pile_a, data->pile_a, sizeof(int) * data->length_a);
		ft_memdel((void **)&(data->pile_a));
		new_pile_a[data->length_a] = data->pile_b[data->length_b - 1];
		data->pile_a = new_pile_a;
		data->length_a += 1;
		data->length_b -= 1;
		if (data->pile_a[data->length_a - 1] <= data->smallest_a)
		{
			data->smallest_a = data->pile_a[data->length_a - 1];
			data->pos_smallest_a = data->length_a - 1;
		}
		if (data->verbose)
			print_state(data);
		data->sequence = ft_strjoin(data->sequence, "pa ");
	}
}

void	push_b(t_pushswap *data)
{
	int		*new_pile_b;
	int		i;

	if (data->length_a > 0)
	{
		new_pile_b = (int *)ft_memalloc(sizeof(int) * (data->length_b + 1));
		ft_memcpy(new_pile_b, data->pile_b, sizeof(int) * data->length_b);
		ft_memdel((void **)&(data->pile_b));
		new_pile_b[data->length_b] = data->pile_a[data->length_a - 1];
		data->pile_b = new_pile_b;
		data->length_b += 1;
		data->length_a -= 1;
		if (data->pile_b[data->length_b - 1] == data->smallest_a)
		{
			i = 0;
			data->smallest_a = data->pile_a[0];
			data->pos_smallest_a = 0;
			while (i < data->length_a)
			{
				if (data->pile_a[i] <= data->smallest_a)
				{
					data->smallest_a = data->pile_a[i];
					data->pos_smallest_a = i;
				}
				i++;
			}
		}
		if (data->verbose)
			print_state(data);
		data->sequence = ft_strjoin(data->sequence, "pb ");
	}
}
