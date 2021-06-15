#include "../includes/philo.h"

void	print_handler(t_handler *handler)
{
	printf("Handler :\nnumber of philos [%d]\ntime to die [%lld]\ntime to eat [%lld]\ntime to sleep [%lld]\nnumber of times they'll eat [%lld]\n",
		handler->nb_philo, handler->time_to_die, handler->time_to_eat,
		handler->time_to_sleep, handler->nb_to_eat);
}

int	init_handler(int argc, char **argv, t_handler *handler)
{
	if (argc == 5 || argc == 6)
	{
		handler->nb_philo = ft_atol(argv[1]);
		handler->time_to_die = ft_atol(argv[2]);
		handler->time_to_eat = ft_atol(argv[3]);
		handler->time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			handler->nb_to_eat = ft_atol(argv[5]);
		else
			handler->nb_to_eat = -1;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_handler	handler;

	if (!init_handler(argc, argv, &handler))
		return (1);
	print_handler(&handler);
	return (0);
}