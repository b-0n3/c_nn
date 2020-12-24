
static int	ft_isspace_p(char c)
{
	if (c == '\n' || c == '\f' || c == ' ' ||
			c == '\r' || c == '\v' || c == '\t' || c == '0')
		return (1);
	return (0);
}

int			ft_atoi_p(char **str)
{
	int				i;
	int				n;
	int				signe;

	n = 0;
	i = 0;
	signe = 1;
	while (ft_isspace_p(*(*str)))
		*str += 1;
	if (*(*str) == '-' || *(*str) == '+')
	{
		if (**str == '-')
			signe = -1;
	}
	while (*(*str) >= '0' && (*(*str) <= '9') && *(*str) != '\0')
	{
		if (((unsigned long)n > 9223372036854775807 / 10) ||
				(((unsigned long)n == 9223372036854775807 / 10) &&
				((unsigned long)n % 10) > 7))
			return ((signe > 0 ? -1 : 0));
		n = n * 10 + *(*str) - '0';
		*str += 1;
	}
	return (n * signe);
}