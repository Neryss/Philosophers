#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define	_DEFAULT			"\033[1;39m"
# define	_RED				"\033[1;31m"
# define	_GREEN				"\033[1;32m"
# define	_YELLOW				"\033[1;33m"
# define	_BLUE				"\033[1;34m"
# define	_MAGENTA			"\033[1;35m"
# define	_CYAN				"\033[1;36m"
# define	_LIGHTGRAY			"\033[1;37m"
# define	_DARKGRAY			"\033[1;90m"
# define	_LIGHTRED			"\033[1;91m"
# define	_LIGHTGREEN			"\033[1;92m"
# define	_LIGHTYELLOW		"\033[1;93m"
# define	_LIGHTBLUE			"\033[1;94m"
# define	_LIGHTMAGENTA		"\033[1;95m"
# define	_LIGHTCYAN			"\033[1;96m"
# define	_WHITE				"\033[1;97m"

# define	_END				"\033[1;0m"

# define FORK					1
# define EAT					2
# define SLEEP					3
# define THINK					4
# define DIED					5

# define PRINT_COLORS			0

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
long long	ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);
void		ft_putstr(int fd, char *str);
void		ft_putchar(int fd, char c);
void		ft_putnbr(int fd, long long nb);
size_t		ft_nblen(long long nb);
size_t		ft_strlen(char *str);
char		*ft_ltoa(long long n);
void		ft_putcolor(int fd, char *str, char *color);
bool		is_digits(char *str);
int			init_handler(int argc, char **argv, t_handler *handler);
void		init_philos(t_handler *handler);
void		*main_loop(void *pouet);
void		*monitor_philo(void *v_philo);
long long	get_time(void);
void		print_action(int type, t_philo *philo);
int			check_overflow(char *argv);
void		print_handler(t_handler *handler);
void		print_philos(t_handler *handler);

#endif