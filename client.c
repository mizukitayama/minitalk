#include <unistd.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
#include <ft_printf.h>

int response = 0;

void sig_handler(int signum, siginfo_t *info, void *context)
{
	static int i = 0;
	response = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
	{
		i = 0;
	}
}

void char_to_byte(int pid, char c)
{
	int bit_i;
	int itr;
	bit_i = 7;

	while (bit_i >= 0) {
		itr = 0;
		ft_printf("bit_i = %d\n", bit_i);
		if ((c >> bit_i) & 1) {
			kill(pid, SIGUSR1);
		}
		else {
			kill(pid, SIGUSR2);
		}
		while (response == 0) {
			usleep(100);
			if (itr == 5000) {
				exit(1);
			}
			itr++;
		}
		response = 0;
		bit_i--;
	}
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	size_t argv_i;

	argv_i = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3) {
		return 0;
	}
	while (argv[2][argv_i]) {
		ft_printf("%c",argv[2][argv_i]);
		char_to_byte(atoi(argv[1]), argv[2][argv_i]);
		argv_i++;
	}
	char_to_byte(atoi(argv[1]), '\0');
}
