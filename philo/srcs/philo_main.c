#include "../includes/philo.h"

void	*main_loop(void *pouet)
{
	int		i;
	t_philo	*philo;

	philo = pouet;
	pthread_mutex_init(&philo->r_fork, NULL);
	i = 0;
	while (!philo->is_dead)
	{
		printf("yo les potes [%d]\n", philo->id);
		i++;
	}
	return (NULL);
}
