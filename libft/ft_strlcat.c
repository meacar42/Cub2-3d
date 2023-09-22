/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:52:05 by meacar            #+#    #+#             */
/*   Updated: 2022/08/19 15:06:49 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	destlen = 0;
	while (dest[destlen])
		destlen++;
	i = 0;
	while (src[i] && destlen + i < (dstsize - 1))
	{
		dest[i + destlen] = src[i];
		i++;
	}
	if (i < dstsize)
		dest[destlen + i] = '\0';
	if (destlen > dstsize)
		return (srclen + dstsize);
	return (destlen + srclen);
}
