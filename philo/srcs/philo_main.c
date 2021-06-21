#include "../includes/philo.h"

static void	philo_eat(t_philo *philo)
{
	long long	start_eat;

	pthread_mutex_lock(philo->l_fork);
	philo_action(FORK, philo);
	pthread_mutex_lock(&philo->r_fork);
	philo_action(FORK, philo);
	start_eat = get_time();
	philo_action(EAT, philo);
	usleep(philo->handler->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	philo->last_eat = get_time();
}

void	*main_loop(void *pouet)
{
	t_philo			*philo;

	philo = pouet;
	philo->timestamp = get_time();
	philo->last_eat = get_time();
	pthread_create(&philo->monitor.pthread, NULL, monitor_philo, philo);
	while (!philo->is_dead && !philo->handler->dead)
	{
		philo_eat(philo);
		philo_action(THINK, philo);
	}
	pthread_join(philo->monitor.pthread, NULL);
	return (NULL);
}
