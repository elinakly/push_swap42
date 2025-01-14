#include "push_swap.h"

int	checkdigit(char *argv);
int	checkduplicates(int num, char **argv, int i);

int	validinput(int argc, char **argv)
{
	int		i;
	long	num;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (ft_printf("split problem\n"), 0);
	}
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if ((!checkdigit(args[i]) || !checkduplicates(num, args, i))
			&& (num > 2147483647 || num < -2147483648))
			return (ft_printf("frong int\n"), 0);
		i++;
	}
	free_argv(args);
	return (1);
}

int	checkdigit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+'))
		{
			i++;
			if (!argv[i])
				return (printf("invalid inpxxut\n"), 0);
		}
		if (!ft_isdigit(argv[i]))
			return (printf("invalid inputdigtt\n"), 0);
		i++;
	}
	return (1);
}

int	checkduplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (num == ft_atoi(argv[i]))
			return (ft_printf("invalid input\n"), 0);
		i++;
	}
	return (1);
}
