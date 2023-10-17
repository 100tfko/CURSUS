/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:06:09 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/05 12:21:56 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != 0 && (size_t)i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (size_t)i + j < len)
		{
			j += 1;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i += 1;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[50] = "aa bb aaaaaaa";
	char	to_find[] = "bb";
	char	*ret;
	int		len;

	len = 5;	
	ret = ft_strnstr(str, to_find, len);
	printf ("%s\n", ret);
	return (0);
}
Hay un error adicional cuando len pasa  ser negativo porque size_t 
no puede ser negativo. Puedo usar un int normal como equivalente y ya esta
pero entonces da otros leaks
*/
