#include <stdio.h>
#include <string.h>

int main()
{

    char destination[100];
    char source[100] = "value";
    char destinationWithValue[100] = "old value";

    strncpy(destination, source, 5);
    printf("%s\n", destination);

    strncpy(destinationWithValue, source, 5);
    printf("%s", destinationWithValue);

    return 0;
}