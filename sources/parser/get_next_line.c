/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelle <lelle@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:04:19 by lelle             #+#    #+#             */
/*   Updated: 2021/12/04 17:04:22 by lelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static char	*ft_movetemp(char *s1, char c)
{
	int		i;
	int		j;
	char	*s2;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (s1[j] != c && s1[j] != '\0')
		j++;
	if (s1[j] == c)
		j++;
	len = ft_strlen(&s1[j]);
	s2 = (char *)malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
		s2[i++] = s1[j++];
	s2[i] = '\0';
	free(s1);
	s1 = NULL;
	return (s2);
}

static int	ft_writeline(char **line, char **temp)
{
	*line = ft_strdupc(*temp, '\n');
	if (line == NULL)
		return (-1);
	*temp = ft_movetemp(*temp, '\n');
	if (*temp == NULL)
		return (-1);
	if (!**temp)
	{
		free(*temp);
		*temp = NULL;
	}
	return (1);
}

static char	*ft_strjoin_gnl(char *temp, char const *buff)
{
	char	*con;
	size_t	len;
	char	*pcon;
	char	*ptemp;

	if (temp == NULL && buff == NULL)
		return (NULL);
	ptemp = temp;
	len = ft_strlen(ptemp) + ft_strlen(buff);
	con = (char *)malloc(len + 1);
	if (con == NULL)
		return (NULL);
	pcon = con;
	while (*ptemp)
		*pcon++ = *ptemp++;
	while (*buff)
		*pcon++ = *buff++;
	*pcon = '\0';
	free(temp);
	temp = NULL;
	return (con);
}

static int	ft_readwrite(int fd, char **line, char *buff, char **temp)
{
	int	res_fd;

	while (1)
	{
		res_fd = read(fd, buff, BUFFER_SIZE);
		if (res_fd < 0)
			return (-1);
		buff[res_fd] = '\0';
		if (*temp)
			*temp = ft_strjoin_gnl(*temp, buff);
		if (!*temp)
			*temp = ft_strdupc(buff, '\0');
		if (*temp == NULL)
			return (-1);
		if (ft_strchr(buff, '\n') != NULL)
			return (ft_writeline(line, temp));
		if (res_fd < BUFFER_SIZE && ft_strchr(buff, '\n') == NULL)
		{
			if (ft_writeline(line, temp) == 1)
				return (0);
			else
				return (-1);
			return (0);
		}
	}
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*temp;

	if (BUFFER_SIZE < 1 || fd < 0 || line == 0)
		return (-1);
	if (temp && ft_strchr(temp, '\n') != NULL)
		return (ft_writeline(line, &temp));
	else
		return (ft_readwrite(fd, line, buff, &temp));
}
