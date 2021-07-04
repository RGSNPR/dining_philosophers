#include "philo.h"

void	upgrade_usleep(double msec)
{
	size_t	start;

	start = my_time();
	while (my_time() - start < msec)
		usleep(100);
}
