#include "../includes/philo.h"

void	init_philos(t_handler *handler)
{
	int	i;

	i = 0;
	handler->philo = malloc(sizeof(t_philo) * handler->nb_philo);
	while (i < handler->nb_philo)
	{
		handler->philo[i].id = i;
		i++;
	}
}

int	init_handler(int argc, char **argv, t_handler *handler)
{
	if (argc == 5 || argc == 6)
	{
		handler->nb_philo = ft_atol(argv[1]);
		handler->time_to_die = ft_atol(argv[2]);
		handler->time_to_eat = ft_atol(argv[3]);
		handler->time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			handler->nb_to_eat = ft_atol(argv[5]);
		else
			handler->nb_to_eat = -1;
		init_philos(handler);
		return (0);
	}
	return (1);
}
