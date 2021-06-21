#include "../includes/philo.h"

static void	*philo_die(t_philo *philo, bool n_print)
{
	if (n_print)
	{
		print_action(DIED, philo);
		philo->handler->dead = true;
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	philo->is_dead = true;
	if (n_print)
		pthread_mutex_unlock(&philo->handler->print);
	return (NULL);
}

void	*monitor_philo(void *v_philo)
{
	t_philo	*philo;
	bool	how_long;
	bool	eat;

	philo = v_philo;
	while (1)
	{
		how_long = get_time() - philo->last_eat < philo->handler->time_to_die;
		eat = (philo->handler->nb_to_eat == -1
				|| philo->nb_eat < philo->handler->nb_to_eat);
		if (!how_long)
			return (philo_die(philo, true));
		else if (!eat)
			return (philo_die(philo, false));
		usleep(100);
	}
}
