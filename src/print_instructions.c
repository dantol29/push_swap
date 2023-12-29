#include "../includes/push_swap.h"

void    print_instructions(t_stack *a)
{
    int i;
    int count;

    i = 0;
    count = 0;
    printf("%d size\n", a->instructions_size);
    while (a->instructions[i])
    {
        if (a->instructions[i][0] == 'r' && a->instructions[i][1] == 'a'\
        && a->instructions[i + 1][0] == 'r' && a->instructions[i + 1][1] == 'b')
        {
            printf("rr\n");
            i++;
            count++;
        }
        else if (a->instructions[i][0] == 'r' && a->instructions[i][1] == 'r' && a->instructions[i][2] == 'a'\
        && a->instructions[i + 1][0] == 'r' && a->instructions[i + 1][1] == 'r' && a->instructions[i + 1][2] == 'b')
        {
            printf("rrr\n");
            i++;
            count++;
        }
        else
            printf("%s\n", a->instructions[i]);
        i++;
            
    }
    printf("%d count\n", count);
}