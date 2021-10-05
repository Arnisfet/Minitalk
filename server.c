#include "includes/minitalk.h"

void	handler(int bit)
{
	if (bit == SIGUSR1)
		write(1, "1", 1);
	if (bit == SIGUSR2)
		write(1, "2", 1);
}

int main(void)
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