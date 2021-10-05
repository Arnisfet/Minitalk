#include "includes/minitalk.h"

void	send_bit(int pid, char *message)
{
	int	i;
	int j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j != 0)
		{
			usleep(120);
			if (message[i] & j)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j = j >> 1;
		}
		if (message[i] == '\0')
		{
			ft_putstr_fd("Message was send\n", 1);
			break ;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Use the following: [PID] [MESSAGE]\n", 1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		send_bit(pid, av[2]);
	}
}
