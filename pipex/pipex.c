#include "pipex.h"

void	closing_stuff(int infile, int outfile, int pipe_fd[2])
{
	if (infile >= 0)
		close(infile);
	if (outfile >= 0)
		close(outfile);
	if (pipe_fd[0] >= 0)
		close(pipe_fd[0]);
	if (pipe_fd[1] >= 0)
		close(pipe_fd[1]);
}

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*get_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

// char	*get_cmd_path(char *cmd, char **envp)
// {
// 	char	*path;
// 	char	**split_paths;
// 	char	*full_path;
// 	int		i;
// 	char	*tmp;

// 	i = 0;
// 	if (ft_strchr(cmd, '/'))
// 	{
// 		if (access(cmd, X_OK) == 0)
// 			return (ft_strdup(cmd));
// 		return (NULL);
// 	}
// 	path = get_path_from_env(envp);
// 	split_paths = ft_split(path, ':');
// 	while (split_paths[i])
// 	{
// 		tmp = ft_strjoin_pipex(split_paths[i], "/");
// 		full_path = ft_strjoin_pipex(tmp, cmd);
// 		free(tmp);
// 		if (access(full_path, X_OK) == 0)
// 		{
// 			free_array(split_paths, -1);
// 			return (full_path);
// 		}
// 		free(full_path);
// 		i++;
// 	}
// 	free_array(split_paths, -1);
// 	return (NULL);
// }

char	*try_paths(char **split_paths, char *cmd)
{
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	while (split_paths[i])
	{
		tmp = ft_strjoin_pipex(split_paths[i], "/");
		full_path = ft_strjoin_pipex(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**split_paths;
	char	*path;
	char	*result;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path = get_path_from_env(envp);
	if (!path)
		return (NULL);
	split_paths = ft_split(path, ':');
	if (!split_paths)
		return (NULL);
	result = try_paths(split_paths, cmd);
	free_array(split_paths, -1);
	return (result);
}
