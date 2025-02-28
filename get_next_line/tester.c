#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main()
{
    int     fd1 = open("file1", O_RDONLY);
    int     fd2 = open("file2", O_RDONLY);

    char    *str_from_file1;
    char    *str_from_file2;

    str_from_file1 = get_next_line(fd1);
    printf("line from file1 : %s", str_from_file1);
    free(str_from_file1);

    str_from_file2 = get_next_line(fd2);
    printf("line from file2 : %s", str_from_file2);
    free(str_from_file2);

    str_from_file1 = get_next_line(fd1);
    printf("line from file1 : %s", str_from_file1);
    free(str_from_file1);

    str_from_file1 = get_next_line(fd1);
    printf("line from file1 : %s", str_from_file1);
    free(str_from_file1);

    str_from_file1 = get_next_line(fd1);
    printf("line from file1 : %s", str_from_file1);
    free(str_from_file1);

    str_from_file2 = get_next_line(fd2);
    printf("line from file2 : %s", str_from_file2);
    free(str_from_file2);

    str_from_file2 = get_next_line(fd2);
    printf("line from file2 : %s", str_from_file2);
    free(str_from_file2);

    return (0);
}