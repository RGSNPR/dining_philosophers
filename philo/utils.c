#include "philo.h"

int	ft_atoi(const char *str)
{
	long	ret;
	int		pusmus;

	pusmus = 1;
	ret = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		pusmus = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		++str;
	}
	return (ret * pusmus);
}

size_t	my_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	malloc_essentials(t_philo **philos, pthread_mutex_t **forks, int num)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * (num + 1));
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!philos || !forks)
		return (0);
	return (1);
}

int	parse_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0)
	{
		printf("Incorrect input values\n");
		return (0);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
		{
			printf("Incorrect input values\n");
			return (0);
		}
	}
	return (1);
}
