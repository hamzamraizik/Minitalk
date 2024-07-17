/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:32:04 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/20 21:32:05 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	handle_signal(int sig, siginfo_t *info, void *context);
void	send_char(pid_t pid, unsigned char c);

#endif //MINITALK_H