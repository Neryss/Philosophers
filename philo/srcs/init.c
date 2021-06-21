#include "../includes/philo.h"

void	init_philos(t_handler *handler)
{
	int	i;

	i = 0;
	handler->philo = malloc(sizeof(t_philo) * handler->nb_philo);
	while (i < handler->nb_philo)
	{
		if (i)
		{
			handler->philo[i].prev_philo = &handler->philo[i - 1];
			handler->philo[i].l_fork = &handler->philo[i - 1].r_fork;
		}
		handler->philo[i].next_philo = &handler->philo[i + 1];
		handler->philo[i].id = i;
		handler->philo[i].nb_eat = 0;
		pthread_mutex_init(&handler->philo[i].r_fork, NULL);
		i++;
	}
	handler->philo[i - 1].next_philo = &handler->philo[0];
	handler->philo[0].prev_philo = &handler->philo[i - 1];
	handler->philo[0].l_fork = &handler->philo[i - 1].r_fork;
}

int	init_handler(int argc, char **argv, t_handler *handler)
{
	if (argc == 5 || argc == 6)
	{
		handler->nb_philo = ft_atol(argv[1]);
		handler->nb_forks = handler->nb_philo;
		handler->time_to_die = ft_atol(argv[2]);
		handler->time_to_eat = ft_atol(argv[3]);
		handler->time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			handler->nb_to_eat = ft_atol(argv[5]);
		else
			handler->nb_to_eat = -1;
		init_philos(handler);
		print_philos(handler);
		return (0);
	}
	return (1);
}
