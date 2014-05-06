#include <stdio.h>
#include <string.h>

char *trim(char *str)
{
    char *start = str;
    char *end;

    if (start) {
        end = start + strlen(str) - 1;
        while (*start && isspace(*start))
            start++;
        while (end > start && isspace(*end)) {

            *end = '\0';
            end--;
        }
    }
    
    return start;
}

int main(int argc, const char *argv[])
{
    char s[] = "   hello   world   ";
    char *p = trim(s);
    printf("s = %s\n", p); 
    return 0;
}
