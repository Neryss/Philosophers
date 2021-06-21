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

long long	get_time(void)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (actual.tv_sec * 1000 + actual.tv_usec / 1000);
}

void	print_action(int type, t_philo *philo)
{
	if (philo->handler->dead || philo->is_dead)
		return ;
	pthread_mutex_lock(&philo->handler->print);
	if (philo->handler->dead)
	{
		pthread_mutex_unlock(&philo->handler->print);
		return ;
	}
	ft_putnbr(1, get_time() - philo->timestamp);
	ft_putstr(1, " ");
	ft_putnbr(1, philo->id);
	if (type == FORK)
		ft_putcolor(1, " has taken a fork\n", _YELLOW);
	else if (type == EAT)
		ft_putcolor(1, " is eating\n", _GREEN);
	else if (type == SLEEP)
		ft_putcolor(1, " is sleeping\n", _BLUE);
	else if (type == THINK)
		ft_putcolor(1, " is thinking\n", _MAGENTA);
	else if (type == DIED)
		ft_putcolor(1, " died\n", _RED);
	if (type != DIED)
		pthread_mutex_unlock(&philo->handler->print);
}
