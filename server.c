#include <unistd.h>
#include <signal.h>
#include <ft_printf.h>

void bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
	{
		*c = (*c << 1) | 1;
	}
	else if (signum == SIGUSR2)
	{
		*c <<= 1;
	}
}

void sig_handler(int signum, siginfo_t *info, void *context)
{
	static char chr = 0;
	static int i = 0;

	bin_to_char(signum, &chr);
	if (i == 7)
	{
		i = 0;
		ft_printf("%c", chr);
		chr = 0;
		usleep(1000);
		kill(info->si_pid, SIGUSR1);
	}
	else
	{
		usleep(1000);
		kill(info->si_pid, SIGUSR2);
		i++;
	}
}

int main(void)
{
	struct sigaction sa;
	ft_printf("%d\n", getpid());

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
	{
		pause();
	}

	return (0);
}
