/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 01:54:57 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/11 01:54:58 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char *cmd, char **envp, int fd_input, int fd_output)
{
	char	**args;
	char	*cmd_path;

	if (dup2(fd_input, STDIN_FILENO) == -1)
		error_exit("Failed input");
	close(fd_input);
	if (dup2(fd_output, STDOUT_FILENO) == -1)
		error_exit("Failed output");
	close(fd_output);
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		error_exit("Failed split or invalid command");
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
		error_exit("Command not found");
	execve(cmd_path, args, envp);
	error_exit("Executions Failed");
	free(cmd_path);
	free_array(args, -1);
	exit(1);
}

void	pipex(char **av, char **envp, int infile, int outfile)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fd) == -1)
		error_exit("Failed pipe");
	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipe_fd[0]);
		exec_child(av[2], envp, infile, pipe_fd[1]);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		exec_child(av[3], envp, pipe_fd[0], outfile);
	}
	closing_stuff(infile, outfile, pipe_fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char *av[], char **envp)
{
	int	infile;
	int	outfile;

	if (ac != 5)
		error_exit("Usage: ./pipex infile.txt 'cmd1' 'cmd2' outfile.txt");
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		error_exit("Failed infile");
	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("Failed outfile");
	pipex(av, envp, infile, outfile);
	return (0);
}
