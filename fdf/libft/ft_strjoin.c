/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:09:38 by luis-fif          #+#    #+#             */
/*   Updated: 2024/03/05 10:43:35 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rez = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!rez)
		return (NULL);
	while (s1[j] != '\0')
	{
		rez[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		rez[j] = s2[i];
		j++;
		i++;
	}
	rez[j] = '\0';
	return (rez);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len_s1);
	ft_memcpy(result + len_s1, s2, len_s2);
	return (result);	
}
*/
/*
int main(void) {
    const char *str1 = "12345";
    const char *str2 = "678910";

    // Chamada da função ft_strjoin para concatenar as duas strings
    char *result = ft_strjoin(str1, str2);

    if (result != NULL) {
        // Imprime o resultado
        printf("Resultado da concatenação: %s\n", result);

        // Libera a memória alocada pela ft_strjoin
        free(result);
    } else {
        printf("Falha na concatenação\n");
    }

    return (0);
}
*/
