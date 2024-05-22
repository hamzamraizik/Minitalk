/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:31:59 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/22 20:34:05 by hmraizik         ###   ########.fr       */
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
			{
				perror("kill");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("kill");
				exit(EXIT_FAILURE);
			}
		}
		i++;
		usleep(500);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	long	i;
	char	*message;
	pid_t	server_pid;

	i = 0;
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
		return (1);
	}
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	message = argv[2];
	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}
