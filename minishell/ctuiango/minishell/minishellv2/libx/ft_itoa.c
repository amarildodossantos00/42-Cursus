#include "../header/header.h"

char	*ft_itoa(int nbr)
{
	int n = nbr;
	int len = 0;
	char *c;

	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	c = malloc(sizeof(char) * (len + 1));
	c[len] = '\0';
	if (nbr == 0)
	{
		c[0] = '0';
		return (c);
	}
	if (nbr < 0)
	{
		c[0] = '-';
		nbr *= -1;
	}
	while (nbr != '\0')
	{
		c[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (c);
}