/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:28 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/07 11:18:24 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*alloc(int len)
{
	char	*ch;

	ch = (char *)malloc((len + 1) * sizeof(char));
	return (ch);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	n2;
	char		*ch;

	if (n == 0)
		return (ft_strdup("0"));
	len = count(n);
	ch = alloc(len);
	if (!ch)
		return (NULL);
	ch[len] = '\0';
	if (n < 0)
		n2 = -(long int)n;
	else
		n2 = n;
	while (len > 0)
	{
		ch[--len] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	if (n < 0)
		ch[0] = '-';
	return (ch);
}
/*
int	main()
{
	char *ch;
	int		n;

	n = -2147483648;
	printf("n = %d\n", n);
	ch = ft_itoa(n);

	printf(" &ch = %p, ch = %p  char = %s *ch = %c\n",&ch,ch, ch, ch[0]);
	printf("ch[0] = %c, &ch[0] = %s\n", ch[0], &ch[0]);

	return (0);
}
*/
