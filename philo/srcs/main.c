#include "../includes/philo.h"

int	init_handler(int argc, char **argv, t_handler *handler)
{
	if (argc == 4 || argc == 5)
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_handler	handler;


	(void)argc;
	(void)argv;
	printf("salut\n");
	return (0);
}