#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	r_fork;
	struct s_philo	*prev_philo;
	struct s_philo	*next_philo;
	long long		timestamp;
	bool			is_dead;
}				t_philo;

typedef struct s_handler
{
	int			nb_philo;
	int			nb_forks;
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
void		print_handler(t_handler *handler);
void		print_philos(t_handler *handler);

#endif