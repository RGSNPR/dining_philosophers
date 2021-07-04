#include "philo.h"

t_global	g_data;

void	CreateThreads(int philos_count, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos_count)
	{
		pthread_create(&philos[i].philo, NULL, philo_business, &philos[i]);
		i++;
	}
}

void	ForksOperations(int philos_count, t_philo *philos,
	 pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philos_count)
	{
		init_forks(&philos[i], forks, i, philos_count);
		i++;
	}
	i = 0;
	while (i < philos_count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	print_on;
	t_philo			*philos;
	t_checkers		checkers;
	pthread_mutex_t	*forks;
	int				philos_count;

	if (parse_args(argc, argv) == 0)
		return (0);
	initGlobalStruct(argc);
	pthread_mutex_init(&print_on, NULL);
	philos_count = ft_atoi(argv[1]);
	if (malloc_essentials(&philos, &forks, philos_count) == 0)
		return (0);
	philos = initPhilos(philos, philos_count, argv, &print_on);
	ForksOperations(philos_count, philos, forks);
	CreateThreads(philos_count, philos);
	pthread_create(&checkers.fullchecker, NULL, isAllFull, philos);
	pthread_create(&checkers.deathchecker, NULL, DeathChecker, philos);
	pthread_join(checkers.deathchecker, NULL);
	return (0);
}
