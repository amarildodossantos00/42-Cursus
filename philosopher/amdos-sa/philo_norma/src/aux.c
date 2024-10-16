

#include "../header/header.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		*str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	print_forks(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(philo->left);
		print_all_messagers(philo, FORK);
		pthread_mutex_lock(philo->right);
		print_all_messagers(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->right);
		print_all_messagers(philo, FORK);
		pthread_mutex_lock(philo->left);
		print_all_messagers(philo, FORK);
	}
}
