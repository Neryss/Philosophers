#include "../includes/philo.h"

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
		
		i++;
	}
	return (NULL);
}
