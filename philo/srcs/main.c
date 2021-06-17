#include "../includes/philo.h"

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
	t_handler		handler;
	struct timeval	start;

	if (init_handler(argc, argv, &handler))
		return (1);
	if (init_threads(&handler))
		return (1);
	gettimeofday(&start, NULL);
	printf("Starting time : %ld\n", start.tv_sec * 1000 + start.tv_usec / 1000);
	print_handler(&handler);
	return (0);
}
