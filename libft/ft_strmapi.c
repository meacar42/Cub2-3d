/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:57:47 by meacar            #+#    #+#             */
/*   Updated: 2022/08/19 15:07:02 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	if (s == NULL)
		return ((char *)s);
	i = 0;
	string = ft_strdup(s);
	if (string == NULL)
		return (NULL);
	while (string[i])
	{
		string[i] = f(i, string[i]);
		i++;
	}
	return (string);
}
