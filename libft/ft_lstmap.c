/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:28:03 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 11:34:46 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*p;

	out = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		p = ft_lstnew(f(lst->content));
		if (p == NULL)
		{
			ft_lstclear(&p, (*del));
			return (NULL);
		}
		ft_lstadd_back(&out, p);
		lst = lst->next;
	}
	return (out);
}
