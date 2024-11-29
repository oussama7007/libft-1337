/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:15:37 by oait-si-          #+#    #+#             */
/*   Updated: 2024/11/03 22:20:21 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}
