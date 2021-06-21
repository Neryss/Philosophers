#include "../includes/philo.h"

static void	philo_eat(t_philo *philo)
{
	long long	start_eat;

	pthread_mutex_lock(philo->l_fork);
	philo_action("has taken a fork", philo);
	pthread_mutex_lock(&philo->r_fork);
	philo_action("has taken a fork", philo);
	start_eat = get_time();
	philo_action("eating", philo);
	usleep(philo->handler->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	philo->last_eat = get_time();
}

void	*main_loop(void *pouet)
{
	int				i;
	t_philo			*philo;

	i = 0;
	philo = pouet;
	philo->timestamp = get_time();
	philo->last_eat = get_time();
	// pthread_mutex_init(&philo->r_fork, NULL);
	while (!philo->is_dead)
	{
		philo_eat(philo);
		i++;
	}
	return (NULL);
}
