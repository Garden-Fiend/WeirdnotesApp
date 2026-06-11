//version 1: this ass implementation is shist

#include <stdio.h>
#include <string.h>

int main()
{

    int buffer = 1000;
    int i = 0;
    int input;
    char textContent[buffer];
    char selection[5];

    while ((input = getchar()) != EOF)
    {

        textContent[i] = input;

        if (textContent[i] == '/')
        {
            printf("/fin -> end writing \n /con -> proceed to write\n");
            scanf("%s", &selection);

            if (strcmp(selection,"/fin") == 0)
            {
                break;
            }
            else

            {
                continue;
            }
        }

        i++;
    }
    printf("-------------------------------------------------");

    printf("\t\n%s", textContent);

    return 0;
}