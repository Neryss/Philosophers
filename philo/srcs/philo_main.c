#include "../includes/philo.h"

int		init_philo(t_philo *philo)
{
	philo->f_left = false;
	philo->f_right = false;
	philo->is_dead = false;
	return (0);
}

void	*main_loop(void *pouet)
{
	int		i;
	t_philo	*philo;

	philo = pouet;
	i = 0;
	while (i < 50)
	{
		printf("yo les potes [%d]\n", philo->id);
		i++;
	}
	return (NULL);
}
