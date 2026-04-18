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
	if (strcmp(line, "env") == 0)
		return("/bin/env");
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
		execute_cd(line);
		return ;
	}
	if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' && line[3] == 'o' && line[4] == 32 && line[5] == '-' && line[6] == 'n' && line[7] == 32)
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
		handle_env(path);
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
}







