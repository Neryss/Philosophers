#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int	id;
}				t_philo;

typedef struct s_handler
{
	int			nb_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	nb_to_eat;
	t_philo		*philo;
}				t_handler;

long long	ft_atol(const char *str);
void		*main_loop(void *pouet);
int			init_handler(int argc, char **argv, t_handler *handler);
void		init_philos(t_handler *handler);

#endif