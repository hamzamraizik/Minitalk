#ifndef MINITLK_H
# define MINITLK_H

#include <libc.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(int sig);
void send_char(pid_t pid, unsigned char c);

#endif