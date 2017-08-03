#include "ft_btree.h"

t_btree	*ft_btreenew(void *data, long long value)
{
	t_btree	*new;

	new = NULL;
	if ((new = (t_btree*)malloc(sizeof(t_btree))))
	{
		new->data = data;
		new->val = value;
		new->color = btree_r;
		new->prev = NULL;
		new->less = NULL;
		new->more = NULL;
	}
	return (new);
}
