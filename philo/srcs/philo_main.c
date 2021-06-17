#include "../includes/philo.h"

void	*main_loop(void *pouet)
{
	int				i;
	t_philo			*philo;

	i = 0;
	philo = pouet;
	philo->timestamp = get_time();
	pthread_mutex_init(&philo->r_fork, NULL);
	while (!philo->is_dead)
	{
		printf("yo les potes [%d]\n", philo->id);
		i++;
		if (i % 100)
			philo_action("EAT", philo);
	}
	return (NULL);
}
