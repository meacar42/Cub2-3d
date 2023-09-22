/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:46:18 by meacar            #+#    #+#             */
/*   Updated: 2022/08/19 15:02:44 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	tmp = (*lst);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
