//
// Created by xzh on 2021/7/21.
//

/* vsprintf example */
#include <stdio.h>
#include <stdarg.h>

void PrintFError(const char *format, ...) {
    char buffer[256];
    va_list args;
    va_start (args, format);
    vsprintf(buffer, format, args);
    perror(buffer);
    va_end (args);
}

int main() {
    FILE *pFile;
    char fileName[] = "myfile.txt";

    pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        PrintFError("Error opening '%s'", fileName);
    } else {
        // file successfully open
        fclose(pFile);
    }
    return 0;
}