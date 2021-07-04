#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

# define FULL 0
# define NEED_FOOD 1
# define DEAD 2
# define DEFAULT 3

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*vilka_l;
	pthread_mutex_t	*vilka_r;
	pthread_mutex_t	*print_on;
	pthread_mutex_t	death;
	int				id;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	long			breaks;
	long			diff;
	long			philos_count;
	size_t			start_time;
	size_t			current_time;
	size_t			last_eat;
	size_t			eat_times;
	int				status;
}	t_philo;

typedef struct s_global
{
	int		status;
	int		breaksin;
	size_t	timee;
}	t_global;

typedef struct s_checkers
{
	pthread_t		fullchecker;
	pthread_t		deathchecker;
}	t_checkers;

int		ft_atoi(const char *str);
void	init_forks(t_philo *philos, pthread_mutex_t *forks, int i, int num);
t_philo	*initPhilos(t_philo *philos, int philos_count, char **argv,
			pthread_mutex_t *print_on);
size_t	my_time(void);
void	initGlobalStruct(int argc);
void	TakeForks(t_philo *myself);
void	DoRoutine(t_philo *myself);
void	*philo_business(void *arg);
void	PrintAction(t_philo *myself, const char *action);
void	upgrade_usleep(double msec);
int		malloc_essentials(t_philo **philos, pthread_mutex_t **forks, int num);
int		parse_args(int argc, char **argv);
int		CheckFull(t_philo *philo, int philo_count);
void	*isAllFull(void *arg);
int		CheckIsDead(t_philo *philos, int i);
void	*DeathChecker(void *arg);
size_t	my_time(void);

#endif
