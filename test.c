// version 1: this ass implementation is shist

#include <stdio.h>
#include <string.h>

int main()
{

    int buffer = 1000;
    int i = 0;
    int input;
    char textContent[buffer];
    char selection[5];
    int mode = 0;

    while ((input = getchar()) != EOF)

    {

        textContent[i] = input;

        if (textContent[i] == '/')
        {
            mode = 1;
        }

        if (mode == 0)
        {
            printf("\033[H\033[J");
            printf("current iteration: %d \n", i);
            printf("%s", textContent);
        }
        else if (mode == 1)
        {

            printf("/fin -> end writing \n /con -> proceed to write\n");
            scanf("%s", &selection);

            if (strcmp(selection, "/fin") == 0)
            {
                break;
            }
            else

            {
                mode = 0;

                printf("\033[H\033[J");
            }
        }

        i++;
    }
    printf("-------------------------------------------------");

    printf("\t\n%s", textContent);

    return 0;
}