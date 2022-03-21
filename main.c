
#include "push_swap.h"
int	main(int argc, char **argv)
{
	t_stack	*last;
	t_stack	*stacka;
	t_add	*add;
	int		i;
	int		size;
	int		pivot;

	stacka = NULL;
	add = NULL;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			stack_addback(&stacka, newstack(atoi(argv[i])));
			i++;
		}
	}
	ft_add_front(&add, ft_new_add(NULL));
	size = ft_stacksize_n(stacka, add->tail);
	pivot = find_median(stacka, size);
	printf("stack size is %d\n", pivot);
}