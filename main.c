#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef HOGE_H
# define TEST_SUCCESS printf("Success\n")
# define TEST_FAILED printf("Failed\n")
# define TEST_KO printf("KO\n")
#endif

static int		test_ft_memccpy(void)
{
	printf("--------------------------| ft_memccpy |--------------------------\n");
	char str[] = "aaaaaaa";
	char dst[7];

	ft_memccpy(dst, str, 'c', 5);
	printf("%s\n", dst);
	printf("==========================| end |==========================\n");
	return (0);
}

static int		test_ft_strlcpy(void)
{
	char str[] = "lkjfsd";
	char dst[0];

	ft_strlcpy(dst, str, 0);
	printf("%s", dst);
	return (0);
}

static int		test_ft_memmove(void)
{
	printf("--------------------------| ft_memmve |--------------------------\n");
	char str1[] = "Geeks"; // Array of size 100
	char str2[] = "Quiz"; // Array of size 5

	puts("str1 before memmove ");
	puts(str1);

	memmove(str1, str2, sizeof(str2));

	puts("\nstr1 after memmove ");
	puts(str1);

	char str3[] = "Geeks";
	char str4[] = "Quiz";

	puts("\n\nstr1 before ft_memmove ");
	puts(str3);

	ft_memmove(str3, str4, sizeof(str4));

	puts("\nstr1 after ft_memmove ");
	puts(str3);
	printf("==========================| end |==========================\n");

	return (0);
}

//static int	test_ft_memchr()
//{
//	printf("--------------------------| ft_memchr |--------------------------\n");
//	char str1[] = "Geeks";
//
//	printf("libc:	%s", memchr(str1, 'd', sizeof(str1)));
//
//	printf("==========================| end |==========================\n");
//	return (0);
//}

static int	test_ft_strlcat()
{
	printf("--------------------------| ft_memchr |--------------------------\n");
	char dst[10] = "Tom && ";
	char *src = "Jerry";

	strlcat(dst, src, 10);
	printf("libc:  %s\n", dst);

	char ft_dst[10] = "Tom && ";
	char *ft_src = "Jerry";

	ft_strlcat(ft_dst, ft_src, 10);
	printf("libft:   %s\n", ft_dst);


	printf("==========================| end |==========================\n");
	return (0);
}

void	sample_strlcat(void)
{
	char dst[30] = "Dragon"; //bufsize 7
	char src[] = "Quest";
	printf("dst strlen: %d\n", (int)strlen(dst));
	printf("src strlen: %d\n", (int)strlen(src));
	//printf("return value: %d\n", (int)strlcat(dst, src, 10));
	printf("return value: %d\n", (int)ft_strlcat(dst, src, 20));
	printf("result: %s\n", dst);
}

void	 sample_ft_strrchr(void)
{
	char *string = "42tokyo";
	printf("%s\n", ft_strrchr(string, '\0'));
}

void	test_ft_strnstr(void)
{
	char *big = "abcdef";
	char *little = "abcdefghijklmnop";
	size_t max = strlen(big);
	char *s1 = strnstr(big, little, max);
	char *s2 = ft_strnstr(big, little, max);

	if (s1 == s2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
}

void	test_ft_strncmp(void)
{
	char *big = "abcdef";
	char *little = "abcdefghijklmnop";
	size_t size = 6;
	int i1 = ((strncmp(big, little, size) > 0) ? 1 : ((strncmp(big, little, size) < 0) ? -1 : 0));
	int i2 = ((ft_strncmp(big, little, size) > 0) ? 1 : ((ft_strncmp(big, little, size) < 0) ? -1 : 0));
	printf("%d\n", i1);
	printf("%d\n", i2);
	if (i1 == i2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
}

void	test_ft_atoi(void)
{
	char n[40] = "-99999999999999999999999999";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);

	if (i1 == i2)
		exit(TEST_SUCCESS);
	exit(TEST_KO);
}

void	test_ft_strtrim(void)
{
	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");

	if (!strcmp(ret, s2))
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
}

void	test_ft_split(void)
{

	char **test1;
	char **test2;
	char **test3;
	int i;

	test1 = ft_split("abcde", 'a');
	//                 i
	//                    j
	i = 0;
	while (test1[i] != 0)
	{
		printf("%s\n", test1[i]);
		i++;
	}
	printf("============\n");

	//                0    5   9
	//                    4   8     15
	test2 = ft_split("one42two2theere4", '2');
	//                     i
	//                ++++    j
	i = 0;
	while (test2[i] != 0)
	{
		printf("%s\n", test2[i]);
		i++;
	}
	printf("============\n");


	test3 = ft_split("abcde", '\0');
	i = 0;
	while (test3[i] != 0)
	{
		printf("%s\n", test3[i]);
		i++;
	}
	printf("============\n");
}

char			f_strmapi(unsigned i, char c) { return (i + c); }
void	test_ft_strmapi()
{
	char *str = "42tokyo";
	char *dst;
	dst = ft_strmapi(str, f_strmapi);
	printf("%s\n", dst);
}

void	test_ft_lstnew()
{
	t_list *ptr;
	ptr = ft_lstnew("There is content");
	printf("\ncurrent : %p\n\tcontent : %s\n\tnext : %p\n", ptr, (char *)ptr->content, ptr->next);
}

void	test_ft_lstadd_front()
{
	t_list	**lst;
	t_list	*ptr;

	lst = malloc(sizeof(t_list *) * 2);
	*lst = ft_lstnew("initial content");
	ft_lstadd_front(lst, ft_lstnew("2nd content"));
	printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
			*lst,
			(char *)((*lst)->content),
			(*lst)->next
		  );
	ptr = (*lst)->next;
	printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
			ptr,
			(char *)(ptr->content),
			ptr->next
		  );
}

void	test_ft_lstsize()
{
	t_list	**lst;
	int	i = 5;
	lst = malloc(sizeof(t_list *) * (i + 10));
	*lst = ft_lstnew("initial content");
	while (i > 0)
		ft_lstadd_front(lst, ft_lstnew(ft_itoa(i--)));
	printf("\nsize\t: %d\n",
			(int)(ft_lstsize(*lst))
		  );

	while (*lst)
	{
		printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
				*lst,
				(char *)((*lst)->content),
				(*lst)->next
			  );
		*lst = (*lst)->next;
	}
}

void	test_ft_lstlast()
{
	t_list	**lst;
	t_list	*ptr;

	int	i = 5;
	lst = malloc(sizeof(t_list *) * (i + 10));
	*lst = ft_lstnew("initial content");
	while (i > 0)
		ft_lstadd_front(lst, ft_lstnew(ft_itoa(i--)));
	ptr = ft_lstlast(*lst);

	printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
			ptr,
			(char *)(ptr->content),
			ptr->next
		  );
}

void	test_ft_lstadd_back(void)
{
	t_list	**lst;
	int	i = 5;
	lst = malloc(sizeof(t_list *) * (i + 10));
	*lst = ft_lstnew("initial content");
	while (i > 0)
		ft_lstadd_back(lst, ft_lstnew(ft_itoa(i--)));
	printf("\nsize\t: %d\n",
			(int)(ft_lstsize(*lst))
		  );

	while (*lst)
	{
		printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
				*lst,
				(char *)((*lst)->content),
				(*lst)->next
			  );
		*lst = (*lst)->next;
	}
}

static void del(void *ptr)
{
	printf("%p\n", ptr);
}

void	test_ft_lstdelone(void)
{
	t_list	**ptr;
	t_list	**lst;
	int	i = 5;
	lst = malloc(sizeof(t_list *) * (i + 10));
	*lst = ft_lstnew("initial content");
	while (i > 0) // add elements
		ft_lstadd_back(lst, ft_lstnew(ft_itoa(i--)));
	ptr = lst;
	printf("\nsize\t: %d\n",
			(int)(ft_lstsize(*lst))
		  );
	//------------------------------------ from here
	ft_lstdelone(lst[3], del);
	while (*lst) // Just output
	{
		printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
				*lst,
				(char *)((*lst)->content),
				(*lst)->next
			  );
		*lst = (*lst)->next;
	}
	//while (*lst)
	//{
	//	printf("\ncurrent : %p\n\tcontent\t: %s\n\tnext\t: %p\n",
	//			*lst,
	//			(char *)((*lst)->content),
	//			(*lst)->next
	//		  );
	//	*lst = (*lst)->next;
	//}
}

void test_ft_lstmap(void)
{

}

int	main(void)
{
	//test_ft_memccpy();
	//test_ft_memmove();
	//test_ft_strlcpy();
	//test_ft_memchr();
	//test_ft_strlcat();
	//sample_strlcat();
	//sample_ft_strrchr();
	test_ft_strnstr();
	//test_ft_strncmp();
	//test_ft_atoi();
	//test_ft_strtrim();
	//test_ft_split();
	//test_ft_strmapi();

	//test_ft_lstnew();
	//test_ft_lstadd_front();
	//test_ft_lstsize();
	//test_ft_lstlast();
	//test_ft_lstadd_back();

	//-------------------- よーわからん--------------------------------
	//test_ft_lstdelone();
	//test_ft_lstmap();
}
