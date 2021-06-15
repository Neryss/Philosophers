#include "../includes/philo.h"

void	print_handler(t_handler *handler)
{
	printf("Handler :\nnumber of philos [%d]\n", handler->nb_philo);
	printf("time to die [%lld]\n", handler->time_to_die);
	printf("time to eat [%lld]\n", handler->time_to_eat);
	printf("time to sleep [%lld]\n", handler->time_to_sleep);
	printf("number of times they'll eat [%lld]\n", handler->nb_to_eat);
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
	free(tid);
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
		if (pthread_create(&tid[i], NULL, (void *)main_loop,
				&handler->philo[i]))
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
