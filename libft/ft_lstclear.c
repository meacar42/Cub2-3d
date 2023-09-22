/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:46:52 by meacar            #+#    #+#             */
/*   Updated: 2022/08/19 15:03:08 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*tmp;

	a = (*lst);
	while (a != NULL)
	{
		tmp = a->next;
		ft_lstdelone(a, del);
		a = tmp;
	}
	(*lst) = NULL;
}
