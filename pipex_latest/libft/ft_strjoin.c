/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:49:07 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/09 22:48:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;

	if (!s1 || !s2)
		return (NULL);
	joint_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joint_str)
		return (NULL);
	ft_memmove(joint_str, s1, ft_strlen(s1));
	ft_memmove(joint_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (joint_str);
}

char	*ft_strjoin_pipex(char *s1, char *s2)
{
	char	*joint_str;

	if (!s1 || !s2)
		return (NULL);
	joint_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joint_str)
		return (NULL);
	ft_memmove(joint_str, s1, ft_strlen(s1));
	ft_memmove(joint_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (joint_str);
}

// int	main(void)
// {
// 	char	str1[] = "General ";
// 	char	str2[] = "Kenobi";
// 	char	*join = ft_strjoin(str1, str2);
// 	printf("%s", join);
// 	free(join);
// 	return (0);
// }