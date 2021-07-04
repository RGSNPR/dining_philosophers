#include "philo.h"

extern t_global	g_data;

int	CheckFull(t_philo *philo, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		if (philo[i].status != FULL)
			return (0);
		i++;
	}
	return (1);
}

void	*isAllFull(void *arg)
{
	t_philo	*myself;

	myself = (t_philo *)arg;
	while (1)
	{
		if (CheckFull(myself, myself->philos_count) == 0)
			continue ;
		else
		{
			pthread_mutex_lock(myself->print_on);
			break ;
		}
	}
	g_data.status = FULL;
	return (0);
}

int	CheckIsDead(t_philo *philos, int i)
{
	if (my_time() - philos[i].last_eat > philos[i].ttd)
	{
		if (my_time() - philos[i].last_eat > philos[i].ttd)
		{
			if (pthread_mutex_lock(&philos[i].death) == 0)
			{
				PrintAction(&philos[i], "died");
				pthread_mutex_destroy(philos[i].print_on);
				g_data.status = DEAD;
			}
			return (1);
		}
	}
	else if (g_data.status == FULL)
	{
		pthread_mutex_destroy(philos[i].print_on);
		return (0);
	}
	return (2);
}

void	*DeathChecker(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	i = 0;
	while (g_data.status == DEFAULT)
	{
		i = 0;
		while (i < philos[i].philos_count)
		{
			if (CheckIsDead(philos, i) == 1)
				break ;
			else if (CheckIsDead(philos, i) == 0)
				return (0);
			i++;
		}
	}
	return (0);
}
