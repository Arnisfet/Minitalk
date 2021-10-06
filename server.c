#include "includes/minitalk.h"

void	printer(int c)
{
	if (c != 0)
		write(1, &c, 1);
	else
		write(1, "\n", 1);
}

void	handler(int bit)
{
	static int	c;
	static int	i;
	static int	j;

	if (j == 0)
		j = 128;
	if (bit == SIGUSR1)
	{
		j /= 2;
		i++;
	}
	else if (bit == SIGUSR2)
	{
		c += j;
		j /= 2;
		i++;
	}
	if (i == 8)
	{
		printer(c);
		i = 0;
		j = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
