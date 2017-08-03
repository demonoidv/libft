#ifndef FT_BTREE_H
# define FT_BTREE_H

# include "libft.h"

enum				e_btcolor
{
	btree_r,
	btree_b,
	btree_bb
};

typedef struct		s_btree
{
	void			*data;
	long long		val;
	struct s_btree	*prev;
	struct s_btree	*less;
	struct s_btree	*more;
	enum e_btcolor	color;
}					t_btree;

t_btree	*ft_btreenew(void *data, long long value);
t_btree	*ft_btreenext(t_btree *start, t_btree *current);
void	ft_btreeadd(t_btree **btree, t_btree *new);
void	ft_btreedel(t_btree *todel);

#endif
