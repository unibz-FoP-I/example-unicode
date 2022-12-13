#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t read_lines(FILE const *fp, char *(**lines));
void printLines(char **lines, size_t size);
void printUTFLines(char **lines, size_t size);
void sortLines(char **lines, size_t size);
void sortUTFLines(char **lines, size_t size);

int main(int argc, char const *argv[])
{
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
    }

    char **lines = NULL;
    size_t size = read_lines(fp, &lines);
    if (fp != stdin)
        fclose(fp);

    puts("-------- Lines read: ----------");
    printUTFLines(lines, size);

    char **linesCopy = malloc(size * sizeof(char*));
    if (linesCopy)
    {
        memcpy(linesCopy, lines, size * sizeof(char*));
    }
    

    sortUTFLines(lines, size);
    puts("-------- Sorted lines (UTF): ----------");
    printUTFLines(lines, size);

    if (linesCopy) {
        sortLines(linesCopy, size);
        puts("-------- Sorted lines (chars): ----------");
        printUTFLines(linesCopy, size);
    }


    return EXIT_SUCCESS;
}
