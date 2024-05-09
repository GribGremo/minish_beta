/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:17:50 by sylabbe           #+#    #+#             */
/*   Updated: 2024/02/15 16:46:19 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	islinefeed(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*mem_create(char *temp)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = malloc (i + 2 * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (j <= i)
	{
		line[j] = temp[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (temp[i + j] != '\0')
	{
		temp[j] = temp[i + j + 1];
		j++;
	}
	temp[j] = '\0';
	return (line);
}

char	*get_read(char *temp, char *mem, int fd)
{
	int	size;

	size = BUFFER_SIZE;
	while (islinefeed(temp) && size == BUFFER_SIZE)
	{
		mem = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (mem == NULL)
			return (NULL);
		size = read(fd, mem, BUFFER_SIZE);
		if (size < 0)
		{
			free(temp);
			free(mem);
			return (NULL);
		}
		mem[size] = '\0';
		temp = ft_strjoin_f(temp, mem);
		if (temp == NULL || temp[0] == '\0')
		{
			free(temp);
			temp = NULL;
			return (temp);
		}
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*mem;
	static char	*temp;

	mem = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (temp == NULL)
	{
		temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (temp == NULL)
			return (NULL);
		temp[0] = '\0';
	}
	temp = get_read(temp, mem, fd);
	if (temp == NULL)
		return (NULL);
	mem = mem_create(temp);
	if (temp[0] == '\0')
	{
		free (temp);
		temp = NULL;
	}
	return (mem);
}
