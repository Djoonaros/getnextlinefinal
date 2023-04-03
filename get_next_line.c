#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*filetostatic(int fd, char *therest)
{
	int		cntr;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	cntr = 1;
	while (!ft_strchr(therest, '\n') && cntr != 0)
	{
		cntr = read(fd, buffer, BUFFER_SIZE);
		if (cntr == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[cntr] = '\0';
		therest = ft_strjoin(therest, buffer);
	}
	free(buffer);
	return (therest);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*therest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	therest = filetostatic(fd, therest);
	if (!therest)
		return (NULL);
	ret = ft_linegetter(therest);
	therest = ft_therest(therest);
	return (ret);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;

// 	fd1 = open("test.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	return (0);
// }