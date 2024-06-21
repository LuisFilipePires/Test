/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:36:00 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/04 15:44:10 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
#include <stdio.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hella";

    int result = ft_strncmp(str1, str2, 4);

    if (result == 0) {
        printf("As primeiras 4 letras são iguais.\n");
    } else if (result < 0) {
        printf("A string str1 é menor que str2.\n");
    } else {
        printf("A string str1 é maior que str2.\n");
    }

    return 0;
}
*/
