/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:31:59 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/29 19:07:13 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR1) == -1)
				usage("sending Error!");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				usage("sending Error!");
		}
		i++;
		usleep(600);
	}
}

void	handle_signal(int seg)
{
	if (seg == SIGUSR1)
		write(1, "message sended successfully\n", 28);
}

int	main(int argc, char **argv)
{
	long				i;
	char				*message;
	pid_t				server_pid;
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (argc != 3)
		usage("Usage: %s <server_pid> <string>");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > MAX_PID)
		usage("invalid Pid!");
	message = argv[2];
	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}
