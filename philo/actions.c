#include "philo.h"

extern t_global	g_data;

void	PrintAction(t_philo *myself, const char *action)
{
	if (pthread_mutex_lock(myself->print_on) != 0)
		return ;
	if (g_data.status == DEFAULT)
	{
		printf("%ld %d %s\n", my_time() - myself->start_time,
			 myself->id, action);
		pthread_mutex_unlock(myself->print_on);
	}
	else
		printf("%ld %d %s\n", my_time() - myself->start_time,
			 myself->id, action);
	return ;
}

void	TakeForks(t_philo *myself)
{
	pthread_mutex_lock(myself->vilka_l);
	PrintAction(myself, "has taken a fork");
	pthread_mutex_lock(myself->vilka_r);
	PrintAction(myself, "has taken a fork");
}

void	DoRoutine(t_philo *myself)
{
	PrintAction(myself, "is eating");
	upgrade_usleep(myself->tte);
	myself->eat_times++;
	if (myself->eat_times == (size_t)myself->breaks
		&& g_data.breaksin == 1)
		myself->status = FULL;
	pthread_mutex_unlock(myself->vilka_l);
	pthread_mutex_unlock(myself->vilka_r);
	PrintAction(myself, "is sleeping");
	upgrade_usleep(myself->tts);
	PrintAction(myself, "is thinking");
}

void	*philo_business(void *arg)
{
	t_philo	*myself;
	int		i;

	myself = (t_philo *)arg;
	if (myself->id % 2 == 0)
		usleep(70);
	myself->last_eat = my_time();
	i = 0;
	while (i < myself->breaks)
	{
		TakeForks(myself);
		myself->last_eat = my_time();
		DoRoutine(myself);
		if (g_data.breaksin == 1)
			i++;
	}
	usleep(100);
	return (0);
}
