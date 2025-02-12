/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:27 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:50 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words(const char *s, char c)
{
	int	i;
	int	wordscount;

	i = 0;
	wordscount = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wordscount++;
		i++;
	}
	return (wordscount);
}

static char	**ft_free(char **words, int j)
{
	while (j)
	{
		free(words[j - 1]);
		j--;
	}
	free(words);
	return (NULL);
}

static char	**ft_words_alloc(const char *s, char c, char **words)
{
	int	j;
	int	i;
	int	len;

	j = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			words[j] = ft_substr(s, (i - len), len);
			if (words[j] == NULL)
				return (ft_free(words, j));
			j++;
		}
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int		words_count;
	char	**words;

	if (s == NULL)
		return (NULL);
	words_count = ft_words(s, c);
	if (words_count == 0)
		return (NULL);
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	words[words_count] = NULL;
	words = ft_words_alloc(s, c, words);
	return (words);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	of;
	int		sign;
	long	result;
	int		found_result;

	(1) && (i = 0, sign = 1, result = 0, found_result = 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] == '+' || str[i] == '-')
		return (3000000000);
	while (str[i] >= '0' && str[i] <= '9')
	{
		found_result = 1;
		of = result * 10 + (str[i] - 48);
		if (of < result)
			return (3000000000);
		result = 10 * result + (str[i++] - 48);
	}
	if (str[i] || !found_result)
		return (3000000000);
	return (result * sign);
}
