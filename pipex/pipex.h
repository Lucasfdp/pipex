#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

char	*get_path_from_env(char **envp);
char	*try_paths(char **split_paths, char *cmd);
char	*get_cmd_path(char *cmd, char **envp);
void	exec_child(char *cmd, char **envp, int fd_input, int fd_output);
void	closing_stuff(int infile, int outfile, int pipe_fd[2]);
void	error_exit(const char *msg);
void	pipex(char **av, char **envp, int infile, int outfile);

#endif