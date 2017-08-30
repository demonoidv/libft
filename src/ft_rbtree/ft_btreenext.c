#include "ft_btree.h"

t_btree		*ft_btreenext(t_btree *start, t_btree *current)
{
	if (current && start)
	{
//			ft_putendl((char *)current->data);
		while (start && start != current)
		{
			start = (current->val < start->val) ? start->less : start->more;
		}
/*			ft_putendl((char *)start->data);
		if (start->prev->less == start)
			ft_putendl("less");
		else
			ft_putendl("more");
			ft_putendl((char *)start->prev->data);*/
		if (start == current)
		{
//		ft_putendl((char *)start->data);
//		if (start->more)
//		ft_putendl((char *)start->more->data);
			if (start->more)
				return (ft_btreenext(start->more, NULL));
			else if (start->prev && start->prev->less == start)
				return (start->prev);
			else
			while (start->prev && start->prev->more == start)
				start = start->prev;
			return (start->prev);
		}
		else
			return (NULL);
	}
	else if (start)
	{
		while (start->less)
		{
			start = start->less;
/*			ft_putendl((char *)start->data);
			if (start->prev)
			ft_putendl((char *)start->prev->data);
			if (start->prev->more)
			ft_putendl((char *)start->prev->more->data);
			if (start->prev->more && start->prev->more->more)
			ft_putendl((char *)start->prev->more->more->data);
			ft_putendl("");*/
		}
		return (start);
	}
	return (NULL);
}
