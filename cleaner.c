#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main() {
    char c, next;
    FILE *fp = fopen("code.c", "r");
    FILE *out = fopen("clean.c", "w");

    if (fp == NULL) {
        printf("Input file not opened\n");
        return 1;
    }
    if (out == NULL) {
        printf("Output file not opened\n");
        fclose(fp);
        return 1;
    }

    printf("files opened: reading code.c, writing clean.c\n");

    c = fgetc(fp);
    while (c != EOF) {
        next = fgetc(fp);

        // detect block comment /* ... */ 
        if (c == '/' && next == '*') {
            do {
                c = fgetc(fp);
                next = fgetc(fp);
            } while (!(c == '*' && next == '/') && c != EOF && next != EOF);
            c = fgetc(fp); // move forward after '*/'
            continue;
        }

        //  detect line comment 
        if (c == '/' && next == '/') {
            // skip until newline or EOF
            while ((c = fgetc(fp)) != '\n' && c != EOF);
            fputc('\n', out); // keep the line break
            c = fgetc(fp);
            continue;
        }
        // detect the header #include <stdio.h>
        if (c == '#' && next == 'i') {
            // skip until newline or EOF
            while ((c = fgetc(fp)) != '\n' && c != EOF);
            fputc('\n', out); // keep the line break
            c = fgetc(fp);
            continue;
        }
        //  not a comment = write it normally 
        if (c != EOF) {
            fputc(c, out);
        }

        c = next;
    }

    fclose(fp);
    fclose(out);
    printf("cleaning finished — output in clean.c\n");
}
