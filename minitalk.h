/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:32:04 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/29 18:38:16 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX_PID  99998

int		ft_atoi(const char *str);
int		usage(const char *s);
void	put_nbr(long nbr);

#endif //MINITALK_H