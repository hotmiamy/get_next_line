/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:07:38 by llopes-n          #+#    #+#             */
/*   Updated: 2021/10/11 16:20:57 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == (unsigned char)c)
			return ((char *)string);
		string++;
	}
	if (*string == (unsigned char)c)
		return ((char *)string);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *str)
{
	int		strlen;
	char	*alloc_str;
	int		index;

	strlen = ft_strlen(str) + 1;
	alloc_str = (char *)malloc(strlen * sizeof(char));
	if (!alloc_str)
		return (NULL);
	index = 0;
	while (index < strlen)
	{
		alloc_str[index] = str[index];
		index++;
	}
	return (alloc_str);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str_conca;
	int		str_concalen;
	int		index;
	int		index2;

	if (!str1 || !str2)
		return (NULL);
	str_concalen = ft_strlen(str1) + ft_strlen(str2) + 1;
	str_conca = (char *)malloc(str_concalen * sizeof(char));
	if (!str_conca)
		return (0);
	index = 0;
	while (str1[index])
	{
		str_conca[index] = str1[index];
		index++;
	}
	index2 = 0;
	while (str2[index2])
	{
		str_conca[index + index2] = str2[index2];
		index2++;
	}
	str_conca[index + index2] = '\0';
	return (str_conca);
}

char	*ft_substr(char const *str, unsigned int start, size_t sub_str_len)
{
	size_t		strlen;
	char		*substr;
	size_t		index;

	if (!str)
		return (0);
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	else if (strlen <= sub_str_len)
		sub_str_len = strlen - start;
	substr = (char *)malloc(sub_str_len + 1);
	if (!substr)
		return (0);
	index = 0;
	while (str[index + start] && index < sub_str_len)
	{
		substr[index] = str[index + start];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
