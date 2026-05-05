#include "minishell.h"

/*ignore spaces to be more bash-like*/
char	*ignore_spaces(char *line)
{
	int		i = 0;
	char	*result;
	int		j = 0;
	int		space = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!result)
		return (0);
	while (line[i])
	{
		while (line [i] && line[i] == 32)
			i++;
		while( line [i] && line[i] != 32)
		{
			result[j] =line[i];
			j++;
			i++;
		}
		if (line[i + 1] && line[i] == 32)
		{
			result[j] = line[i];
			space = 1;
			j++;
			i++;
		}
		while (line[i] && space == 1)
			

	}
	result[j] = '\0';
	return (result);
}


/*running commands ls cat and pwd
dont forget to replace strcmp with ft_strcmp*/
//beginning of block


static char	*get_path(char *line)
{
        
	if (strcmp(line, "ls") == 0)
		return ("/bin/ls");
	if (strcmp(line, "pwd") == 0)
		return ("/bin/pwd");
	if (strcmp(line, "cat") == 0)
		return ("/bin/cat");
	if (strcmp(line, "env") == 0)
		return("/bin/env");
	return (NULL);
}


//end of block

void	run_command(char *line, char **envp)
{
	pid_t	pid;
	int		status;
	char	*path;
	char	*args[2];
	char	*new_line;
	new_line = ignore_spaces(line);
	if (strcmp(line,"exit") == 0)
	{
		free(line);
		exit(0);
	}
	if (line[0] == 'c' && line[1] == 'd' && line[2] == 32)
    {
		line = ignore_spaces(line);
		if (strcmp(line,"..") == 0 || strcmp(line, ".") == 0 || strcmp(line, "cd") == 0)
		{	
			execute_cd(line);
			return ;
		}
        cd_path(line);
        return ;
        }
	
	if (strncmp(line,"echo -n",7) == 0)
	{
		int i = 8;
		while (line[i])
		{
			write(1,&line[i], 1);
			i++;
		}
		return ;
	}
	path = get_path(line);
	if (!path)
	{
		printf("command not found: %s\n", line);
		return ;
	}

	if (strcmp(path ,"/bin/env") == 0)
	{
		handle_env(envp);
		return ;
	}	
	
	args[0] = path;
	args[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		execve(path, args, NULL);
		perror("execve");
		exit(1);
	}
	waitpid(pid, &status, 0);
	free(new_line);
}







