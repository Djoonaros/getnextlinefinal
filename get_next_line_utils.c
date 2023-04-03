
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *therest, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!therest)
	{
		therest = (char *)malloc(1 * sizeof(char));
		therest[0] = '\0';
	}
	if (!therest || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(therest) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (therest)
		while (therest[++i] != '\0')
			str[i] = therest[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(therest) + ft_strlen(buff)] = '\0';
	free(therest);
	return (str);
}

char	*ft_linegetter(char *therest)
{
	int		i;
	char	*str;

	i = 0;
	if (!therest[i])
		return (NULL);
	while (therest[i] && therest[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (therest[i] && therest[i] != '\n')
	{
		str[i] = therest[i];
		i++;
	}
	if (therest[i] == '\n')
	{
		str[i] = therest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_therest(char *therest)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (therest[i] && therest[i] != '\n')
		i++;
	if (!therest[i])
	{
		free(therest);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(therest) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (therest[i])
		str[j++] = therest[i++];
	str[j] = '\0';
	free(therest);
	return (str);
}
