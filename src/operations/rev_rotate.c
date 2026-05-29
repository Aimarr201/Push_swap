
void	rra(t_stacks, *backpack)
{
	int	i;
	int	tmp;

	if (backpack->len_b < 2)
		return ;
	tmp = backpack->stack_a[backpack->len_a - 1];
	i = backpack->len_a - 1;
	while (i > 0)
	{
		backpack->stack_a[i] = backpack->stack_a[i - 1];
		i--;
	}
	backpack->stack_a[0] = tmp;
	ft_putstr("rra\n");
}

void	rrb(t_stacks, *backpack)
{
	int	i;
	int	tmp;

	if (backpack->len_b < 2)
		return ;
	tmp = backpack->stack_b[backpack->len_b - 1];
	i = backpack->len_b - 1;
	while (i > 0)
	{
		backpack->stack_b[i] = backpack->stack_b[i - 1];
		i--;
	}
	backpack->stack_b[0] = tmp;
	ft_putstr("rrb\n");
}

void	rrr(t_stacks, *backpack)
{
	int	i;
	int	tmp;

	if (backpack->len_a >= 2)
	{
		tmp = backpack->stack_a[backpack->len_a - 1];
		i = backpack->len_a;
		while (i > 0)
			backpack->stack_a[i] = backpack->stack_a[i - 1--];
		backpack->stack_a[0] = tmp;
	}
	if (backpack->len_b >= 2)
	{
		tmp = backpack->stack_b[backpack->len_b - 1];
		i = backpack->len_b;
		while (i > 0)
		{
			backpack->stack_b[i] = backpack->stack_b[i - 1];
			(--i);
		}
		backpack->stack_b[0] = tmp;
	}
	ft_putstr("rrr\n");
}

