/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouis <mmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:25:49 by mmouis            #+#    #+#             */
/*   Updated: 2025/10/28 14:25:49 by mmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	red_byte(char *buf, int fd)
{
	int	byte;

	byte = read(fd, buf, BUFFER_SIZE);
	if (byte < 0)
		return (-1);
	buf[byte] = '\0';
	return (byte);
}

char	*extract_line(char **box, char *nwl)
{
	char	*left;
	char	*line;

	if (nwl)
	{
		line = ft_substr(*box, 0, (nwl - *box + 1));
		left = ft_strdup(*box + (nwl - *box + 1));
		if (!left || left[0] == '\0')
			return (free(left), free(*box), *box = NULL, line);
		else
		{
			free(*box);
			*box = left;
		}
	}
	else
	{
		line = ft_strdup(*box);
		if (!line)
			return (NULL);
		return (free(*box), *box = NULL, line);
	}
	return (line);
}

char	*ft_check(char *buf, int fd)
{
	static char	*box[1024];
	char		*tmp;
	char		*nwl;

	nwl = ft_strchr(box[fd], '\n');
	while (nwl == NULL && red_byte(buf, fd) > 0)
	{
		if (!box[fd])
		{
			box[fd] = ft_strdup(buf);
			if (!box[fd])
				return (free(buf), NULL);
		}
		else
		{
			tmp = ft_strjoin(box[fd], buf);
			if (!tmp)
				return (free(buf), NULL);
			free(box[fd]);
			box[fd] = tmp;
		}
		nwl = ft_strchr(box[fd], '\n');
	}
	return (free(buf), extract_line(&box[fd], nwl));
}

char	*get_next_line(int fd)
{
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	return (ft_check(buf, fd));
}
