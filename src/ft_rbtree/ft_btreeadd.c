#include "ft_btree.h"

static void	add_node(t_btree *btree, t_btree **new, t_btree **current)
{
	t_btree	*tmp;

	tmp = *new;
	if (tmp->val < btree->val)
	{
		tmp->prev = btree;
		*current = tmp;
		btree->less = tmp;
		*current = btree->less;
	}
	else
	{
		tmp->prev = btree;
		*current = tmp;
		btree->more = tmp;
		*new = NULL;
	}
}

static void	uncle_black_r(/*t_btree *gparent, */t_btree *parent, t_btree *son)
{
	if (parent->less == son)
	{
		son->prev = parent->prev;
		parent->prev = son;
		parent->less = son->more;
		son->more = parent;
		if (son->prev && son->prev->less == parent)
			son->prev->less = son;
		else if (son->prev)
			son->prev->more = son;
//		parent = son;
//		son = parent->more;
	}
	else if (parent->more == son)
	{
		son->prev = parent->prev;
		parent->prev = son;
		parent->more = son->less;
		son->less = parent;
		if (son->prev && son->prev->less == parent)
			son->prev->less = son;
		else if (son->prev)
			son->prev->more = son;
//		parent = son;
//		son = parent->less;
	}
/*
	parent->prev = parent->prev->prev;
	gparent->prev = parent;
	gparent->more = parent->less;
	parent->less = gparent;
	parent->color = btree_b;
	gparent->color = btree_r;*/
}

static void	uncle_black_l(t_btree *gparent, t_btree *parent/*, t_btree *son*/)
{
/*	if (parent->more == son)
	{
		son->prev = parent->prev;
		parent->prev = son;
		parent->more = son->less;
		son->less = parent;
		parent = son;
		son = parent->less;
	}*/
	if (gparent->less == parent)
	{
	parent->prev = parent->prev->prev;
	gparent->prev = parent;
	gparent->less = parent->more;
	parent->more = gparent;
	parent->color = btree_b;
	gparent->color = btree_r;
	if (parent->prev && parent->prev->less == gparent)
		parent->prev->less = parent;
	else if (parent->prev)
		parent->prev->more = parent;
	}
	else if (gparent->more == parent)
	{
	parent->prev = parent->prev->prev;
	gparent->prev = parent;
	gparent->more = parent->less;
	parent->less = gparent;
	parent->color = btree_b;
	gparent->color = btree_r;
	if (parent->prev && parent->prev->less == gparent)
		parent->prev->less = parent;
	else if (parent->prev)
		parent->prev->more = parent;
	}
}

static void	balance_update(t_btree *current)
{
	t_btree	*gparent;
	t_btree	*parent;
	t_btree	*uncle;

	parent = current->prev;
	gparent = parent->prev;
	uncle = NULL;
	if (gparent)
		uncle = (parent->val < gparent->val) ? gparent->more : gparent->less;
	if (!(parent->prev))
		parent->color = btree_b;
	else if (uncle && uncle->color == btree_r)
	{
		parent->color = btree_b;
		uncle->color = btree_b;
		gparent->color = btree_r;
	//	if (gparent->prev && gparent->prev->color == btree_r)
	//		balance_update(gparent);
	}
//	else if (gparent->less == uncle)
	else
	{
		if ((gparent->less == parent && parent->more == current) || \
		(gparent->more == parent && parent->less == current))
		{
		uncle_black_r(/*gparent, */parent, current);
		parent = current;
		current = (parent->more == current) ? parent->less : parent->more;
		}
//	else if (gparent->more == uncle)
		uncle_black_l(gparent, parent/*, current*/);
	}
}

void		ft_btreeadd(t_btree **btree, t_btree *new)
{
	t_btree	*tmp;
	t_btree	*current;

	tmp = *btree;
	current = NULL;
	if (tmp && new)
	{
		while (new)
		{
			if (tmp->less && new->val < tmp->val)
				tmp = tmp->less;
			else if (tmp->more && new->val >= tmp->val)
				tmp = tmp->more;
			else
				add_node(tmp, &new, &current);
		}
		if (tmp->color == btree_r)
			balance_update(current);
	}
	else if (new)
		*btree = new;
	if (tmp)
	{
		while (tmp->prev)
		{
			tmp = tmp->prev;
//			ft_putendl((char *)tmp->data);
		}
//		ft_putendl("");
		*btree = tmp;
	}
}
