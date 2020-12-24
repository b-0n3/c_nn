int     ft_iswhitespace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r')
        return 1;
	return (0);
}