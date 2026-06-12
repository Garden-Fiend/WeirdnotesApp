#include <stdio.h>
#include <string.h>

int main() {
    char textContent[1000];
    char line[100];

    int text_i = 0;
    int line_i = 0;

    int input;
    int mode = 0; 
    // 0 = writing
    // 1 = command

    printf("Start typing...\n");

    while ((input = getchar()) != EOF) {

        // ----------------------------
        // BUILD CURRENT LINE
        // ----------------------------
        if (input != '\n') {
            line[line_i++] = input;
        }

        // ----------------------------
        // END OF LINE → DECIDE STATE
        // ----------------------------
        if (input == '\n') {
            line[line_i] = '\0';

            // ---- STATE TRANSITION ----
            if (strcmp(line, "/") == 0) {
                mode = 1;  // enter command mode
            } 
            else if (mode == 1) {
                // command mode processing
                if (strcmp(line, "fin") == 0) {
                    break;
                }

                printf("Unknown command: %s\n", line);
                mode = 0;
            } 
            else {
                // writing mode: store full line
                int len = strlen(line);
                for (int i = 0; i < len; i++) {
                    textContent[text_i++] = line[i];
                }
                textContent[text_i++] = '\n';
            }

            // reset line buffer every newline
            line_i = 0;

            continue;
        }

        // optional live feedback
        if (mode == 0) {
            printf("writing...\n");
        } else {
            printf("command mode...\n");
        }
    }

    textContent[text_i] = '\0';

    printf("\n--- FINAL OUTPUT ---\n%s\n", textContent);

    return 0;
}