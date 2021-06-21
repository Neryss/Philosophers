#include "../includes/philo.h"

void	*monitor_philo(void *v_philo)
{
	t_philo	*philo;
	bool	how_long;

	philo = v_philo;
	while (1)
	{
		how_long = get_time() - philo->last_eat < philo->handler->time_to_die;
		if (!how_long)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(&philo->r_fork);
			philo->is_dead = true;
			philo->handler->dead = true;
			philo_action(DIE, philo);
			pthread_mutex_lock(&philo->handler->print);
			return (NULL);
		}
		usleep(100);
	}
}