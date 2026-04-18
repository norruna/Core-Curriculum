#include "minishell.h"

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
	return (NULL);
}


//end of block

void	run_command(char *line)
{
	pid_t	pid;
	int		status;
	char	*path;
	char	*args[2];

	if (strcmp(line,"exit") == 0)
	{
		free(line);
		exit(0);
	}
	if (line[0] == 'c' && line[1] == 'd' && line[2] == 32)
        {
            cd_path(line);
            return ;
        }
	if (strcmp(line,"cd ..") == 0 || strcmp(line, "cd .") == 0 || strcmp(line, "cd") == 0)
	{	
		execute_cd(path);
		return ;
	}
	
	path = get_path(line);
	
	
	if (!path)
	{
		printf("command not found: %s\n", line);
		return;
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
}







