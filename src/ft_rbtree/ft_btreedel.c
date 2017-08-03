#include "ft_btree.h"

static void	del_node(t_btree **todel, t_btree *next)
{
	t_btree	*parent;
	t_btree	*tmp;

	tmp = *todel;
	parent = tmp->prev;
	if ((tmp->less && !tmp->more) || (tmp->more && !tmp->less))
	{
		next->color += tmp->color;
		if (parent->less == tmp)
			parent->less = next;
		else
			parent->more = next;
		next->prev = parent;
		free(tmp);
	}
	else if (!tmp->more && !tmp->less)
	{
		if (parent->less == tmp)
			parent->less = NULL;
		else
			parent->more = NULL;
		free(tmp);
	}
	*todel = next;
}

static void	rotation_tree(t_btree *current, t_btree *parent, char c)
{
	t_btree	*brother;

	brother = NULL;
	if (parent)
		brother = (parent->less == current) ? parent->more : parent->less;
	if (c == 'l')
	{
		brother->prev = parent->prev;
		parent->more = brother->less;
		brother->less = parent;
		parent->prev = brother;
		brother->color = parent->color;
		parent->color = btree_r;
	}
	else if (c == 'r')
	{
		brother->prev = parent->prev;
		parent->less = brother->more;
		brother->more = parent;
		parent->prev = brother;
		brother->color = parent->color;
		parent->color = btree_r;
	}
}

static void	brother_black(t_btree *current, t_btree *parent, t_btree *brother)
{
	if (brother && (!brother->more || brother->more->color == btree_b) && \
	brother->less && brother->less->color == btree_r && brother == \
	parent->more)
	{
		rotation_tree(brother->more, brother, 'r');
/*		brother->less->prev = parent;
		brother->prev = brother->more;
		brother->less = brother->less->more;
		brother->prev->more = brother;
		brother->prev->color = btree_b;
		brother->color = btree_r;*/
	}
	else if (brother && (!brother->more || brother->more->color == \
	btree_b) && brother->less && brother->less->color == btree_r)
	{
		rotation_tree(brother->less, brother, 'l');
	}
	brother = (parent->less == current) ? parent->more : parent->less;
	if (brother && parent->more == brother && brother->more && \
	brother->more->color == btree_r)
		rotation_tree(current, parent, 'l');
	else if (brother && parent->less == brother && brother->less && \
	brother->less->color == btree_r)
		rotation_tree(current, parent, 'r');
	else if (brother && (!brother->less || brother->less->color == btree_b) \
	&& (!brother->more || brother->more->color >= btree_b))
	{
		parent->color += (current->color = btree_b);
		brother->color = btree_r;
	}
}

static void	balance_update(t_btree *current, t_btree *parent, t_btree *brother)
{
	if (parent)
		brother = (parent->less == current) ? parent->more : parent->less;
	if (!parent)
		current->color = btree_b;
	else if (brother && brother->color == btree_r && parent->more == brother)
	{
		rotation_tree(current, parent, 'l');
/*		brother->prev = parent->prev;
		parent->more = brother->less;
		brother->less = parent;
		parent->prev = brother;
		brother->color = btree_b;
		parent->color = btree_r;*/
	}
	else if (brother && brother->color == btree_r && parent->less == brother)
	{
		rotation_tree(current, parent, 'r');
/*		brother->prev = parent->prev;
		parent->less = brother->more;
		brother->more = parent;
		parent->prev = brother;
		brother->color = btree_b;
		parent->color = btree_r;*/
	}
	if (parent && parent->less == current)
		brother_black(current, parent, parent->more);
	else if (parent)
		brother_black(current, parent, parent->less);
	if (current->prev && current->prev->color > btree_b)
		balance_update(current->prev, current->prev->prev, NULL);
}

void		ft_btreedel(t_btree *todel)
{
	t_btree	*parent;
	t_btree	*next;

	if (todel)
	{
		parent = todel->prev;
		next = (todel->less && !todel->more) ? todel->less : todel->more;
		if (todel->less && todel->more)
		{
			todel->data = next->data;
			todel->val = next->val;
			while (next->less)
			{
				next->data = next->less->data;
				next->val = next->less->val;
				next = next->less;
			}
			todel = next;
			next = todel->more;
		}
		del_node(&todel, next);
		if (todel && todel->color > btree_b)
			balance_update(todel, todel->prev, NULL);
	}
}
