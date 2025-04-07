
#include <limits.h>
#include "libft.h" // Replace with actual header if needed

void test_char_functions() {
    printf("\n=== CHAR FUNCTIONS ===\n");
    char test[] = {'a', 'Z', '5', '\0', ' ', '\n', 127, -1};
    for (int i = 0; i < sizeof(test); i++) {
        printf("Char: %c (%d) => isalpha: %d, isdigit: %d, isalnum: %d, isascii: %d, isprint: %d\n",
               test[i], test[i], ft_isalpha(test[i]), ft_isdigit(test[i]), ft_isalnum(test[i]),
               ft_isascii(test[i]), ft_isprint(test[i]));
    }
}

void test_string_functions() {
    printf("\n=== STRING FUNCTIONS ===\n");
    char *s = "Hello World";
    char *empty = "";

    printf("ft_strlen(\"Hello World\"): %zu\n", ft_strlen(s));
    printf("ft_strlen(\"\"): %zu\n", ft_strlen(empty));

    char buffer[20];
    ft_memset(buffer, 'A', 10);
    buffer[10] = '\0';
    printf("ft_memset to 'A' for 10 bytes: %s\n", buffer);

    ft_bzero(buffer, 5);
    printf("After ft_bzero for 5 bytes: %s\n", buffer);

    char src[] = "1234567890";
    ft_memcpy(buffer, src, 10);
    printf("After ft_memcpy: %s\n", buffer);

    ft_memmove(buffer + 2, buffer, 8); // test overlap
    printf("After ft_memmove overlap: %s\n", buffer);

    char dest1[20] = "Hello ";
    ft_strlcpy(dest1, "42", sizeof(dest1));
    printf("ft_strlcpy: %s\n", dest1);

    char dest2[20] = "Hello ";
    ft_strlcat(dest2, "World", sizeof(dest2));
    printf("ft_strlcat: %s\n", dest2);

    printf("toupper('a'): %c\n", ft_toupper('a'));
    printf("tolower('Z'): %c\n", ft_tolower('Z'));

    printf("strchr('Hello', 'e'): %s\n", ft_strchr("Hello", 'e'));
    printf("strrchr('Hello', 'l'): %s\n", ft_strrchr("Hello", 'l'));
    printf("strncmp('abc', 'abd', 2): %d\n", ft_strncmp("abc", "abd", 2));

    char *found = ft_memchr("abc\0def", 'd', 7);
    printf("memchr in 'abc\\0def' for 'd': %s\n", found ? found : "NULL");

    printf("strnstr('FooBarBaz', 'Bar', 9): %s\n", ft_strnstr("FooBarBaz", "Bar", 9));

    printf("atoi('   -42abc'): %d\n", ft_atoi("   -42abc"));

    char *mem = ft_calloc(4, sizeof(int));
    if (mem) {
        printf("ft_calloc 4 * sizeof(int): success\n");
        free(mem);
    }

    char *dup = ft_strdup("Libft");
    printf("ft_strdup: %s\n", dup);
    free(dup);

    char *sub = ft_substr("Hello World", 6, 5);
    printf("ft_substr: %s\n", sub);
    free(sub);

    char *joined = ft_strjoin("Hello", "42");
    printf("ft_strjoin: %s\n", joined);
    free(joined);

    char *trimmed = ft_strtrim("  \tHello World\n  ", " \t\n");
    printf("ft_strtrim: %s\n", trimmed);
    free(trimmed);

    char **split = ft_split("one,two,,three", ',');
    printf("ft_split: ");
    for (int i = 0; split && split[i]; i++) {
        printf("[%s] ", split[i]);
        free(split[i]);
    }
    free(split);
    printf("\n");

    char *itoa_result = ft_itoa(-2147483648);
    printf("ft_itoa: %s\n", itoa_result);
    free(itoa_result);

    char *mapi_result = ft_strmapi("abc", [](unsigned int i, char c) -> char {
        return c + i;
    });
    printf("ft_strmapi: %s\n", mapi_result);
    free(mapi_result);

    char striteri_buf[] = "abc";
    ft_striteri(striteri_buf, [](unsigned int i, char *c) {
        *c += i;
    });
    printf("ft_striteri: %s\n", striteri_buf);
}

void test_fd_functions() {
    printf("\n=== FD FUNCTIONS ===\n");
    ft_putchar_fd('A', 1);
    write(1, "\n", 1);
    ft_putstr_fd("Hello\n", 1);
    ft_putendl_fd("World", 1);
    ft_putnbr_fd(12345, 1);
    write(1, "\n", 1);
}

void test_list_functions() {
    printf("\n=== BONUS LIST FUNCTIONS ===\n");
    t_list *a = ft_lstnew(strdup("one"));
    t_list *b = ft_lstnew(strdup("two"));
    t_list *c = ft_lstnew(strdup("three"));

    ft_lstadd_front(&a, b);
    ft_lstadd_back(&a, c);

    printf("List size: %d\n", ft_lstsize(a));
    printf("Last element: %s\n", (char *)ft_lstlast(a)->content);

    ft_lstdelone(b, free);
    ft_lstclear(&a, free);
    printf("List cleared.\n");

    t_list *map_test = ft_lstnew(strdup("a"));
    ft_lstadd_back(&map_test, ft_lstnew(strdup("b")));
    t_list *mapped = ft_lstmap(map_test, [](void *s) -> void * {
        char *str = strdup((char *)s);
        str[0] += 1;
        return str;
    }, free);

    printf("Mapped list: ");
    for (t_list *cur = mapped; cur; cur = cur->next) {
        printf("%s ", (char *)cur->content);
    }
    printf("\n");
    ft_lstclear(&map_test, free);
    ft_lstclear(&mapped, free);
}

int main(void) {
    test_char_functions();
    test_string_functions();
    test_fd_functions();
    test_list_functions();
    return 0;
}
