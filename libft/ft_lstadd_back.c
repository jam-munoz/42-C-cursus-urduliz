/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 22:58:20 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/29 23:01:53 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *p;

	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new;
}
