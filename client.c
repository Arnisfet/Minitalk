#include "includes/minitalk.h"

void	send_bit(int pid, char *message)
{
	int	i;

	i = 0;
	if (message[i])
	{
		kill(pid, SIGUSR1);
	}
	else
	{
		kill(pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Use the following: [PID] [MESSAGE]\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_bit(pid, av[2]);
	return 0;
}
