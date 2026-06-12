// version 1: this ass implementation is shist

#include <stdio.h>
#include <string.h>

int main()
{

    int buffer = 1000;
    int text_i = 0;
    int ii = 0;
    int buffer_i = 0;
    int input;
    char textContent[buffer];
    char selection[5];
    char lineBuffer[100];
    char filename[200];
    int mode = 0;
    char fileAns;
    char line[200] = "\n----------------------------------------------------------------\n";

    printf("\tREALLY BADLY BUILT NOTES APP\n");
    printf("\n\t Press Enter to Start....");
    printf("%s",line);


    while ((input = getchar()) != EOF)

    {
        lineBuffer[buffer_i] = input;

        if (input == '\n')
        {
            lineBuffer[buffer_i] = '\0';
            buffer_i = 0;

            if ((strcmp(lineBuffer, "/")) == 0)
            {
                mode = 1;
            }
            else if (mode == 1)
            {
                printf("CM:\n");
                printf("\tPress Enter twice coz this program is stupid\n");
                printf("\t/fin -> finish writing \n\t/con -> continue writing\n");
                if ((strcmp(lineBuffer, "/fin")) == 0)
                {
                    break;
                }
                else if ((strcmp(lineBuffer, "/con")) == 0)
                {
                    mode = 0;
                    continue;
                }
                else
                {

                    continue;
                }
            }
            else
            {
                printf("WM:");
                int len = strlen(lineBuffer);
                for (int i = 0; i < len; i++)
                {
                    textContent[text_i++] = lineBuffer[i];
                }
            }

            continue;
        }

        buffer_i++;
    }
    printf("%s",line);
    textContent[text_i] = '\0';


    do{
        printf("Enter a file name: \n");
        scanf("%s",filename);

        if(filename == NULL){
            printf("Would you like to cancel ?: \n Y | N");
            scanf("%c",&fileAns);
        }


    }while(filename == NULL || fileAns == 'N' || fileAns == 'n');

    FILE *file = fopen(filename,"w");

    if(file == NULL){
        printf("File Error: Cannot be Opened\n");
        return 1;
    }

    fprintf(file,"%s", textContent);

    fclose(file);
    printf("Files is saved");



    return 0;
}
