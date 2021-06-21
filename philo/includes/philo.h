#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_monitor
{
	pthread_t		pthread;
	struct s_philo	*philo;
}				t_monitor;

typedef struct s_philo
{
	int					id;
	int					nb_eat;
	t_monitor			monitor;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		r_fork;
	struct s_philo		*prev_philo;
	struct s_philo		*next_philo;
	struct s_handler	*handler;
	long long			timestamp;
	long long			last_eat;
	bool				is_dead;
}				t_philo;

typedef struct s_handler
{
	int				nb_philo;
	int				nb_forks;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		nb_to_eat;
	pthread_mutex_t	print;
	t_philo			*philo;
	bool			dead;
}				t_handler;

long long	ft_atol(const char *str);
void		*main_loop(void *pouet);
int			init_handler(int argc, char **argv, t_handler *handler);
void		init_philos(t_handler *handler);
void		print_handler(t_handler *handler);
void		print_philos(t_handler *handler);
long long	get_time();
void		philo_action(char *action, t_philo *philo);
void		*monitor_philo(void *v_philo);

#endif