/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:02:13 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/29 10:48:38 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// int main(void){
// 	char n;
// 	scanf("%c", &n);
// 	printf("isalpha   : %d\n", ft_isalpha(n));
// 	printf("isdigit   : %d\n", ft_isdigit(n));
// 	printf("isalnum   : %d\n", ft_isalnum(n));
// 	printf("isascii   : %d\n", ft_isascii(n));
// 	printf("isprint   : %d\n", ft_isprint(n));

// 	char str[100], buff_str[100];
// 	scanf("%s", str);
// 	strcpy(buff_str, str);
// 	size_t cnt = ft_strlen(str);
// 	printf("strlen    : %zu\n", cnt);
// 	ft_memset(str, 97, cnt);
// 	printf("ft_memset : %s -> %s\n", buff_str, str);
// 	strcpy(buff_str, str);
// 	ft_bzero(str, cnt);
// 	printf("ft_bzero  : %s -> %s\n", buff_str, str);
// 	return (0);
// }

// memcpy
// int	main(void)
// {
// 	char dst[10] = "1234";
// 	char src[10];
// 	printf("%p\n", ft_memcpy(NULL, NULL, 0));
// 	printf("%p\n", ft_memcpy(NULL, NULL, 1));
// 	printf("%p\n", ft_memcpy(dst, NULL, 0));
// 	// printf("%p\n", ft_memcpy(dst, NULL, 1));
// 	printf("%p\n", ft_memcpy(NULL, src, 0));
// 	// printf("%p\n", ft_memcpy(NULL, src, 1));

// 	printf("%p\n", memcpy(NULL, NULL, 0));
// 	printf("%p\n", memcpy(NULL, NULL, 1));
// 	printf("%p\n", memcpy(dst, NULL, 0));
// 	// printf("%p\n", memcpy(dst, NULL, 1));
// 	printf("%p\n", memcpy(NULL, src, 0));
// 	//  printf("%p\n", memcpy(NULL, src, 1));
// }

// memmove
// int	main(void)
// {
// 	char dst[10] = "123";
// 	char src[10] = "abcde";
// 	printf("%s\n", (char *)memmove(dst, src, 3));
// 	// printf("%s\n", (char *)ft_memmove(dst, src, 5));

// 	printf("%p\n", ft_memmove(NULL, NULL, 0));
// 	printf("%p\n", ft_memmove(NULL, NULL, 1));
// 	printf("%p\n", ft_memmove(dst, NULL, 0));
// 	// printf("%p\n", ft_memmove(dst, NULL, 1));
// 	printf("%p\n", ft_memmove(NULL, src, 0));
// 	// printf("%p\n", ft_memmove(NULL, src, 1));

// 	printf("%p\n", memmove(NULL, NULL, 0));
// 	printf("%p\n", memmove(NULL, NULL, 1));
// 	printf("%p\n", memmove(dst, NULL, 0));
// 	// printf("%p\n", memmove(dst, NULL, 1));
// 	printf("%p\n", memmove(NULL, src, 0));
// 	//  printf("%p\n", memmove(NULL, src, 1));


// 	char	buff[10];
// 	int		i1;

// 	for (i1 = 0; i1 < 10; i1++)
// 		buff[i1] = i1;
// 	printf("1.");
// 	for (i1 = 0; i1 < 10; i1++)
// 		printf("[%d]", buff[i1]);
// 	printf("\n2.");
// 	ft_memcpy(buff + 1, buff, 9);
// 	for (i1 = 0; i1 < 10; i1++)
// 		printf("[%d]", buff[i1]);

// 	for (i1 = 0; i1 < 10; i1++)
// 		buff[i1] = i1;
// 	printf("\n\n1.");
// 	for (i1 = 0; i1 < 10; i1++)
// 		printf("[%d]", buff[i1]);
// 	printf("\n2.");
// 	ft_memmove(buff + 1, buff, 9);
// 	for (i1 = 0; i1 < 10; i1++)
// 		printf("[%d]", buff[i1]);
// }

// strlcpy
// int	main(void)
// {
// 	char dst[10] = "1234";
// 	char src[10];
// 	// ft_strlcpy(NULL, NULL, 0);
// 	// ft_strlcpy(NULL, NULL, 1);
// 	// ft_strlcpy(dst, NULL, sizeof dst);
// 	// ft_strlcpy(dst, NULL, 0);
// 	// ft_strlcpy(NULL, src, sizeof dst);
// 	ft_strlcpy(NULL, src, 0);

// 	// strlcpy(NULL, NULL, 0);
// 	// strlcpy(NULL, NULL, 1);
// 	// strlcpy(dst, NULL, sizeof dst);
// 	// strlcpy(dst, NULL, 0);
// 	// strlcpy(NULL, src, sizeof dst);
// 	strlcpy(NULL, src, 0);
// }

// strncmp
// int	main(void)
// {
// 	char s1[10] = "1234";
// 	char s2[10] = "1233";
// 	(void)s1;
// 	(void)s2;
// 	// ft_strncmp(NULL, NULL, 0);
// 	// ft_strncmp(NULL, NULL, 1);
// 	// ft_strncmp(s1, NULL, 0);
// 	// ft_strncmp(s1, NULL, 1);
// 	// ft_strncmp(NULL, s2, 0);
// 	// ft_strncmp(NULL, s2, 1);

// 	// strncmp(NULL, NULL, 0);
// 	// strncmp(NULL, NULL, 1);
// 	// strncmp(s1, NULL, 0);
// 	// strncmp(s1, NULL, 1);
// 	// strncmp(NULL, s2, 0);
// 	// strncmp(NULL, s2, 1);
// }

//memcmp
// int	main(void)
// {
// 	char s1[10] = "1234";
// 	char s2[10] = "1233";
// 	printf("%d\n", ft_memcmp(NULL, NULL, 0));
// 	// printf("%d\n", ft_memcmp(NULL, NULL, 1));
// 	printf("%d\n", ft_memcmp(s1, NULL, 0));
// 	// printf("%d\n", ft_memcmp(s1, NULL, 1));
// 	printf("%d\n", ft_memcmp(NULL, s2, 0));
// 	// printf("%d\n", ft_memcmp(NULL, s2, 1));

// 	printf("%d\n", memcmp(NULL, NULL, 0));
// 	// printf("%d\n", memcmp(NULL, NULL, 1));
// 	printf("%d\n", memcmp(s1, NULL, 0));
// 	// printf("%d\n", memcmp(s1, NULL, 1));
// 	printf("%d\n", memcmp(NULL, s2, 0));
// 	// printf("%d\n", memcmp(NULL, s2, 1));
// }

// strnstr
// int	main(void)
// {
// 	char haystack[10] = "123456";
// 	char needle[10] = "3";
// 	// ft_strnstr(NULL, NULL, 0);
// 	// ft_strnstr(NULL, NULL, 1);
// 	// ft_strnstr(haystack, NULL, 0);
// 	// ft_strnstr(haystack, NULL, 0);
// 	ft_strnstr(NULL, needle, 0);
// 	// ft_strnstr(NULL, needle, 1);

// 	// strnstr(NULL, NULL, 0);
// 	// strnstr(NULL, NULL, 1);
// 	// strnstr(haystack, NULL, 0);
// 	// strnstr(haystack, NULL, 0);
// 	strnstr(NULL, needle, 0);
// 	// strnstr(NULL, needle, 1);
// }

// int main(void){
// 	char str[] = "    12334     1231  asd as2 ";
// 	char **pp = ft_split(str, ' ');
// 	printf("%s\n", pp[0]);
// 	printf("%s\n", pp[1]);
// 	printf("%s\n", pp[2]);
// 	printf("%s\n", pp[3]);
// }

#include <stdio.h>

int main(void){
	// printf("%ld\n", ft_strtol("18446744073709551614"));
	printf("%d\n", ft_atoi("18446744073709551614"));
	return (0);
}
