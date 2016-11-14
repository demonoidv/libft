#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	**tmp;
	t_list	*buf;

	tmp = alst;
	while (*alst)
	{
		buf = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = buf;
	}
	alst = NULL;
}
