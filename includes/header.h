/*
** header.h for myftp in /home/rootkid/rendu/psu/PSU_2016_myftp
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Tue May  9 14:16:44 2017 theo champion
** Last update Sun May 21 22:00:41 2017 theo champion
*/

#ifndef HEADER_H_
#define HEADER_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <signal.h>
#include <libgen.h>

#define CMD_SIZE 1024
#define BLOCK_SIZE 1024
#define SP ' '
#define CR '\r'
#define LF '\n'
#define USER "Anonymous"
#define INFO 0
#define ERROR 1
#define DEBUG 2
#define HELP "USER\tPASS\tQUIT\tCWD\tCDUP\nPWD\tPORT\tPASV\t\
STOR\tRETR\nLIST\tDELE\tHELP\tNOOP"
#define LOGGED 2
#define QUEUE_SIZE 5
#define LS_CMD "/bin/ls -l"

typedef struct	s_handle
{
  int		ctrl_fd;
  int		data_fd;
  int		pasv_fd;
  unsigned long	local_ip;
  char		*home;
  char		*wd;
  int		cmd_nb;
  char		*cmd_arg;
  int		login_status;
  bool		quit;
}		t_handle;

typedef bool (*cmd_ptr)(t_handle *);

int	create_s_socket(struct sockaddr_in *sock, int port);
int	create_c_socket(struct sockaddr_in *sock, uint32_t ip, int port);
bool	reply(t_handle *hdl, int code, const char *fmt, ...);
void	handle_client(t_handle *hdl);
bool	cmd_user(t_handle *hdl);
bool	cmd_pass(t_handle *hdl);
bool	cmd_quit(t_handle *hdl);
bool	cmd_help(t_handle *hdl);
bool	cmd_noop(t_handle *hdl);
bool	cmd_cwd(t_handle *hdl);
bool	cmd_cdup(t_handle *hdl);
bool	cmd_pwd(t_handle *hdl);
bool	cmd_list(t_handle *hdl);
bool	cmd_stor(t_handle *hdl);
bool	cmd_retr(t_handle *hdl);
bool	cmd_dele(t_handle *hdl);
bool	cmd_port(t_handle *hdl);
bool	cmd_pasv(t_handle *hdl);
bool	cmd_type(t_handle *hdl);
void	log_msg(int mode, const char *fmt, ...);
char	*resolve_path(t_handle *hdl, char *path);
FILE	*open_file(t_handle *hdl, char *filename, char *mode);
FILE	*open_cmd_stream(t_handle *hdl, char *arg);
int	create_s_socket(struct sockaddr_in *sock, int port);
int	create_c_socket(struct sockaddr_in *sock, uint32_t ip, int port);
int	accept_con(int socket);

#endif /* !HEADER_H_ */
