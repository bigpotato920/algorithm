#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *trim(char *s) {
    char *start = s;
    char *end;

    if (start) {

        end = start + strlen(s) - 1;
        while (*start && isspace(*start))
            start++;
        while (end > start && isspace(*end))
            *end-- = '\0';

    }
    
    return start;
}

int length_of_last_word(const char *s)
{
    char *new_str = (char*)malloc(strlen(s)+ 1);
    char *trim_str = NULL;
    int last_index = 0;
    int cur_index = 0;
    int len = 0;

    strcpy(new_str, s);
    trim_str = trim(new_str);
    len = strlen(trim_str);

    while (cur_index < len) {
        if (isspace(trim_str[cur_index])) {
            last_index = cur_index;
        }
        cur_index++;
    }
    printf("new_str = %s\n", trim_str);
    free(new_str);

    if (last_index == 0)
        return len;

    return len - last_index - 1;
}

int main(int argc, const char *argv[])
{
    const char *s = "a ";

    printf("len = %d\n", length_of_last_word(s));
    return 0;
}
