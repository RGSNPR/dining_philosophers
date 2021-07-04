#include "philo.h"

extern t_global	g_data;

void	init_forks(t_philo *philos, pthread_mutex_t *forks, int i, int num)
{
	if (i == num - 1)
	{
		philos->vilka_l = &forks[0];
		philos->vilka_r = &forks[i];
	}
	else if (i == 0)
	{
		philos->vilka_l = &forks[0];
		philos->vilka_r = &forks[1];
	}
	else
	{
		philos->vilka_l = &forks[i + 1];
		philos->vilka_r = &forks[i];
	}
	return ;
}

t_philo	*initPhilos(t_philo *philos, int num, char **argv,
	 pthread_mutex_t *print_on)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philos[i].id = i + 1;
		philos[i].ttd = (long)ft_atoi(argv[2]);
		philos[i].tte = (long)ft_atoi(argv[3]);
		philos[i].tts = (long)ft_atoi(argv[4]);
		philos[i].status = NEED_FOOD;
		if (g_data.breaksin == 1)
			philos[i].breaks = (long)ft_atoi(argv[5]);
		else
			philos[i].breaks = 1;
		philos[i].print_on = print_on;
		philos[i].diff = 0;
		philos[i].last_eat = my_time();
		philos[i].start_time = my_time();
		philos[i].eat_times = 0;
		philos[i].philos_count = (long)ft_atoi(argv[1]);
		pthread_mutex_init(&philos[i].death, NULL);
		i++;
	}
	return (philos);
}

void	initGlobalStruct(int argc)
{
	g_data.status = DEFAULT;
	g_data.timee = my_time();
	if (argc == 5)
		g_data.breaksin = 0;
	else
		g_data.breaksin = 1;
}
