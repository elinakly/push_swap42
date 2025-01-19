#include "push_swap.h"

int	checkdigit(char *argv);
int	checkduplicates(int num, char **argv, int i);

int	validinput(int argc, char **args)
{
	int		i;
	long	num;

	i = 1;
	if (argc == 2)
		i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (!num && args[i][0] != '0')
			return (0);
		if (ft_strlen(args[i]) > 11)
			return (0);
		if (!checkdigit(args[i]))
			return (0);
		if (!checkduplicates(num, args, i))
			return (0);
		i++;
	}
	return (1);
}

int	checkdigit(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+'))
			return (0);
		if (!ft_isdigit(argv[i]))
			return (0);
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
			return (0);
		i++;
	}
	return (1);
}
