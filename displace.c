#include "fillit_funkcia.h"


int                displace(char *str, int sq, int tetr, int y)
{
    int     i;
    int     j;
    int        b;
    j = y + 1;
    while (str[j] != '0' && j < sq * sq)
        j++;
    i = 15;
    while (!(tetr & (1 << i)))
        i--;
    b = i++;
    while (i--)
        if (tetr & (1 << i))
        {
            if (j + b - i + (sq - 4) * (3 - i / 4) >= sq * sq)
                return (-2);
            else if ((j + b - i + (sq - 4) * (3 - i / 4))/sq - j / sq != 3 - i / 4)
            {
                j++;
                i = b + 1;
            }
        }
    return (j);
}
char            *abc(int tetr, char c, int sq, int y)
{
    int     i;
    int     j;
    static char    *str;
    int        b;
    j = 0;
    i = 15;
    if (y == -1 && !str)
    {
        str = ft_memalloc(sq * sq);
        str = ft_memset(str, '0', sq * sq);
    }
    while (!(tetr & (1 << i)))
        i--;
    b = i++;
    while (i-- > 2 && y > -1)
        if (j != 4 && tetr & (1 << i) && (str + (b - i) + (3 - i / 4) (sq - 4) + y) == '0')
            j++;
    i = 16;
    if (j == 4 && y >= 0)
        while (i-- > 2 && y != -1)
            if (tetr & (1 << i))
                (str + (b - i) + (3 - i / 4) (sq - 4) + y) = c;
    if (j != 4 && y >= -1)
    {
        y = displace(str, sq, tetr, y);
        abc(tetr, c, sq, y);
    }
    if (y == -2)
        str = NULL;
    return (str);
}
int                main(int argc, char **argv)
{
    t_tetr        tetr;
    char        c;
    int            y;
    int            sq;
    tetr = read_file(argv[1]);
    printf("%s \n", argv[1]);
    printf("%d \n", tetr.count);
    sq = square(tetr.count);
    y = -1;
    c = 'A';
    printf("%s \n", abc(tetr.tetr[1], c, sq, y));
    c++;
    y = 0;
    printf("%s \n", abc(tetr.tetr[2], c, sq, y));
    c++;
    printf("%s \n", abc(tetr.tetr[3], c, sq, y));
    c++;
    printf("%s \n", abc(tetr.tetr[3], c, sq, y));
    c++;
    printf("%s \n", abc(tetr.tetr[1], c, sq, y));
    c++;
    printf("%c \n", c);
    return(0);
}
