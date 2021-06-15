#include "../includes/philo.h"

void	print_handler(t_handler *handler)
{
	printf("Handler :\nnumber of philos [%d]\ntime to die [%lld]\ntime to eat [%lld]\ntime to sleep [%lld]\nnumber of times they'll eat [%lld]\n",
		handler->nb_philo, handler->time_to_die, handler->time_to_eat,
		handler->time_to_sleep, handler->nb_to_eat);
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
		return (0);
	}
	return (1);
}

int	wait_threads(pthread_t *tid, t_handler *handler)
{
	int	i;

	i = 0;
	while (i < handler->nb_philo)
	{
		pthread_join(tid[i], NULL);
		printf("thread joined\n");
		i++;
	}
	return (0);
}

int	init_threads(t_handler *handler)
{
	pthread_t	*tid;
	int			i;

	i = 0;
	tid = malloc(sizeof(pthread_t) * handler->nb_philo);
	if (!tid)
		return (1);
	while (i < handler->nb_philo)
	{
		if (pthread_create(&tid[i], NULL, (void *)main_loop, NULL))
			return (1);
		i++;
	}
	if (wait_threads(tid, handler))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_handler	handler;

	if (init_handler(argc, argv, &handler))
		return (1);
	if (init_threads(&handler))
		return (1);
	print_handler(&handler);
	return (0);
}