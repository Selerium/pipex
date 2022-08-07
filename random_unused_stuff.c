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