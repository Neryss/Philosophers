#include "../includes/philo.h"

int	wait_threads(pthread_t *tid, t_handler *handler)
{
	int	i;

	i = 0;
	while (i < handler->nb_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	free(tid);
	pthread_mutex_destroy(&handler->print);
	i = 0;
	while (i < handler->nb_philo)
		pthread_mutex_destroy(&handler->philo[i++].r_fork);
	free(handler->philo);
	return (0);
}

int	init_threads(t_handler *handler)
{
	pthread_t	*tid;
	int			i;

	i = 0;
	tid = malloc(sizeof(pthread_t) * handler->nb_philo);
	pthread_mutex_init(&handler->print, NULL);
	if (!tid)
		return (1);
	while (i < handler->nb_philo)
	{
		if (pthread_create(&tid[i], NULL, (void *)main_loop,
				&handler->philo[i]))
			return (1);
		usleep(10000);
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
	int				ret;

	ret = init_handler(argc, argv, &handler);
	if (ret)
	{
		if (ret == 2)
			ft_putstr(2, "Invalid number of arguments\n");
		else
			ft_putstr(2, "Invalid arguments\n");
		return (1);
	}
	if (init_threads(&handler))
	{
		ft_putstr(2, "Error during threads\n");
		return (1);
	}
	gettimeofday(&start, NULL);
	return (0);
}
