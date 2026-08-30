/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:14:08 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/30 15:39:42 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*remove;

	if (lst == NULL || del == NULL)
		return ;
	p = *lst;
	while (p != NULL)
	{
		remove = p;
		p = p->next;
		(*del)(remove->content);
		free(remove);
	}
	*lst = NULL;
}
