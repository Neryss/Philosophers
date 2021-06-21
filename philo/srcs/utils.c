#include "../includes/philo.h"

void	print_handler(t_handler *handler)
{
	printf("Handler :\nnumber of philos [%d]\n", handler->nb_philo);
	printf("time to die [%lld]\n", handler->time_to_die);
	printf("time to eat [%lld]\n", handler->time_to_eat);
	printf("time to sleep [%lld]\n", handler->time_to_sleep);
	printf("number of times they'll eat [%lld]\n", handler->nb_to_eat);
}

void	print_philos(t_handler *handler)
{
	int	i;

	i = 0;
	while (i < handler->nb_philo)
	{
		if (i)
			printf("Prev philo id : %d\n", handler->philo[i].prev_philo->id);
		printf("next philo id : %d\n", handler->philo[i].next_philo->id);
		printf("currently dead : %d\n", handler->philo[i].is_dead);
		i++;
	}
}

long long	get_time()
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (actual.tv_sec * 1000 + actual.tv_usec / 1000);
}

void	philo_action(char *action, t_philo *philo)
{
	pthread_mutex_lock(&philo->handler->print);
	printf("%lld %d %s\n", get_time() - philo->timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->handler->print);
}