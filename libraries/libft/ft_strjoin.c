/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdiks <cdiks@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 16:12:21 by rkoper        #+#    #+#                 */
/*   Updated: 2022/06/03 14:44:21 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*safe_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		write(2, "failed to allocate memory\n", 27);
		exit(1);
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = safe_calloc(len1 + len2 + 1, sizeof(char));
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		s3[i + j] = s2[j];
		j++;
	}
	return (s3);
}
