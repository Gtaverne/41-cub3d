#include "../includes/cub3d.h"

int		is_insep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_wrdlen(char *str, char *sep)
{
	int i;

	i = 0;
	while (!(is_insep(str[i], sep)) && str[i])
		i++;
	return (i);
}

int		ft_wcount(char *str, char *sep)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!is_insep(str[i], sep) && (i == 0 ||
					is_insep(str[i - 1], sep)))
			res++;
		i++;
	}
	return (res);
}

char	*ft_wrdcpy(char *src, int wlen)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(*tmp) * (wlen + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < wlen)
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[wlen] = 0;
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	char	**tab;

	tab = malloc(sizeof(*tab) * (1 + ft_wcount(str, charset)));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!(is_insep(str[i], charset)) && ft_wrdlen(&str[i], charset))
		{
			tab[k] = ft_wrdcpy(&str[i], ft_wrdlen(&str[i], charset));
			k++;
			i = i + ft_wrdlen(&str[i], charset);
		}
		else
			i++;
	}
	tab[k] = 0;
	return (tab);
}