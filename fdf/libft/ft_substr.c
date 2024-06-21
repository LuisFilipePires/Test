/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:03:40 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/05 10:08:42 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *) ft_calloc((len + 1), sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *original = "Exemplo de substring";
    unsigned int start = 8; // Índice inicial
    size_t length = 7;     // Tamanho da substring desejada

    char *substring = ft_substr(original, start, length);

    if (substring)
    {
        printf("String original: %s\n", original);
        printf("Substring: %s\n", substring);

        // Certifique-se de liberar a memória alocada pela ft_substr
        free(substring);
    }
    else
    {
        printf("Erro ao criar a substring.\n");
    }

    return 0;
}
*/
