/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:22:19 by keulee            #+#    #+#             */
/*   Updated: 2021/05/17 18:22:24 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(copy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] != '\0' && 0 < len)
	{
		copy[j++] = s[start++];
		len--;
	}
	copy[j] = '\0';
	return (copy);
}
