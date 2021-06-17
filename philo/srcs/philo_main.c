#include "../includes/philo.h"

void	*main_loop(void *pouet)
{
	int		i;
	t_philo	*philo;

	philo = pouet;
	pthread_mutex_init(&philo->fork, NULL);
	i = 0;
	while (i < 50)
	{
		printf("yo les potes [%d]\n", philo->id);
		i++;
	}
	return (NULL);
}
