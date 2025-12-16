#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ASCII characters
# define C_VERTICAL_BAR 124
# define C_LESS 60
# define C_GREAT 62
# define C_DOLLAR 36
# define C_ONE_QUOTE 39
# define C_TWO_QUOTE 34

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isquote(int c)
{
	if (c == C_ONE_QUOTE || c == C_TWO_QUOTE)
		return (1);
	return (0);
}

int	ft_is_one_quote(int c)
{
	if (c == C_ONE_QUOTE)
		return (1);
	return (0);
}

int	ft_is_two_quote(int c)
{
	if (c == C_TWO_QUOTE)
		return (1);
	return (0);
}

static int check_one_quote(char *str)
{
    int j;
    int count;
    
    j = 0;
    count = 0;
    while(str[j])
    {
        if(ft_is_one_quote(str[j]) == 1)
            count++;
        j++;
    }
    if (count % 2 != 0)
        return (1);
    return (0);
}

static int check_two_quote(char *str)
{
    int j;
    int count;
    
    j = 0;
    count = 0;
    while(str[j])
    {
        if(ft_is_two_quote(str[j]) == 1)
            count++;
        j++;
    }
    if (count % 2 != 0)
        return (1);
    return (0);
}

static int check_quote(char *str)
{
    int one_quote;
    int two_quote;

    one_quote = check_one_quote(str);
    two_quote = check_two_quote(str);
    if (one_quote == 1 || two_quote == 1)
        return (1);
    return (0);
}
//int tokenizer(char *str, t_lex **lex )
int tokenizer(char *str)
{
    //t_lex   *new;
    //int     i;

    if (check_quote(str) == 0)
        return (1);
    return (0);

    //i = 0;
    // while (str[i])
    // {

    // }
}

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
        exit(1);
    i = tokenizer(av[1]);
    printf("quote: %d\n ", i);
    return (0);

}