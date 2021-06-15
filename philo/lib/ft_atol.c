#include "../includes/philo.h"

static int	ft_check_white_spaces(char *str, int i)
{
	while (str[i] == '\r' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\n' || str[i] == ' ')
		i++;
	return (i);
}

static int	calcul_res(long long res, int neg, int pos)
{
	if (neg == 0)
		return (res);
	if (pos == 0 && neg == 1)
		return (-res);
	else
		return (0);
}

long long	ft_atol(const char *str)
{
	int			i;
	int			neg;
	int			pos;
	long long	res;

	neg = 0;
	pos = 0;
	res = 0;
	i = ft_check_white_spaces((char *)str, 0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			neg++;
		else
			pos++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((pos >= 0 && pos <= 1) && (neg >= 0 && neg <= 1))
		return (calcul_res(res, neg, pos));
	return (0);
}
