#include "../includes/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	else if (!s1 && !s2)
		return (0);
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

int	check_overflow(char *argv)
{
	char	*tmp;

	tmp = ft_ltoa(ft_atol(argv));
	if (*argv == '-')
	{
		argv++;
		while (*argv == '0' && ft_strlen(argv) > 1)
			argv++;
		if (*argv != '0')
		{
			argv--;
			*argv = '-';
		}
	}
	else
	{
		while (*argv == '0' && ft_strlen(argv) > 1)
			argv++;
	}
	if (ft_strcmp(argv, tmp))
		return (0);
	free(tmp);
	return (1);
}

bool	is_digits(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
