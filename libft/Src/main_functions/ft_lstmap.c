/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:43:34 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:53:04 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

static void	all_free(t_list **lst)
{
	t_list *space;

	while (lst)
	{
		space = (*lst)->next;
		free(lst);
		*lst = space;
	}
	(*lst) = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*slist;

	if (!lst || !f)
		return (NULL);
	nlist = ft_lstnew(NULL, 0);
	nlist = f(lst);
	if (nlist == NULL)
		return (NULL);
	slist = nlist;
	while (lst->next)
	{
		lst = lst->next;
		nlist->next = f(lst);
		if (nlist->next == NULL)
		{
			all_free(&slist);
			return (NULL);
		}
		nlist = nlist->next;
	}
	return (slist);
}
