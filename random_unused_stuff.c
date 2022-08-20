// char	*ft_findcmd(char *cmd, char **env)
// {
// 	int		i;
// 	char	**paths;

// 	i = 0;
// 	while (env[i][0])
// 	{
// 		if (ft_substr(env[i], 0, 4) == "PATH")
// 			break;
// 		i++;
// 	}
// 	if (env[i] == NULL)
// 	{
// 		ft_printf("Command not found. Exiting.");
// 		exit(0);
// 	}
// 	paths = ft_split(env[i][5], ':');
// 	while (paths[i])
// 	{
// 		i++;
// 	}
// }


// argsize = ft_strlen(argv[1]) + ft_strlen(argv[2]) + 2;
// 	args = (char *) malloc (argsize * sizeof(char));
// 	ft_strlcpy(args, argv[1], ft_strlen(argv[1]) + 1);
// 	ft_strlcat(args, " ", argsize);
// 	ft_strlcat(args, argv[2], argsize);
// 	ft_printf("test %d %s\n", ft_strlen(args), args);

///**
// * @brief parses through the arguments to get command and its file path, then
// * 			calls "execve()" to run the said command with provided args
// * 
// * @param infile name of infile
// * @param args arguments for the cmd
// * @param env environment variable
// */
//void	ft_parse(char *file, char *args, char **env, int flag)
//{
//	char		*cmdpath;
//	int			fd[2];
//	int			stdoutcpy;
//	int			temp;
//	char		**cmd;

//	cmd = ft_split(args, ' ');
//	pipe(fd);
//	stdoutcpy = dup(STDOUT_FILENO);
//	dup2(fd[WRITE], STDOUT_FILENO);
//	cmdpath = ft_findcmd(cmd[0], env, fd);
//	if (flag == 0)
//	{
//		dup2(open(file, O_RDONLY), STDIN_FILENO);
//		unlink("temp.txt");
//		temp = open("temp.txt", O_CREAT | O_WRONLY, 0666);
//		dup2(temp, STDOUT_FILENO);
//	}
//	else if (flag == 2)
//	{
//		dup2(open("temp.txt", O_RDONLY), STDIN_FILENO);
//		unlink(file);
//		temp = open(file, O_CREAT | O_WRONLY, 0666);
//		dup2(temp, STDOUT_FILENO);
//	}
//	ft_execute(cmdpath, cmd, env);
//	close(fd[READ]);
//	close(fd[WRITE]);
//	close(temp);
//	free(cmdpath);
//}

unlink("outfile");
		int x = open("outfile", O_CREAT | O_WRONLY, 0777);
		close(fd[WRITE]);
		dup2(x, STDOUT_FILENO);
		close(x);