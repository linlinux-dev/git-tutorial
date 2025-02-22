#include <stdio.h>
#include <string.h>

int str(char* haystack, char* needle) 
{
    int e = strlen(needle);
    int f = strlen(haystack);
    for(int i = 0; i < f; i++)
    {
        if(needle[i] == haystack[i])
        {
            for(int j = i + 1; j <)
        }
    }
    return 0;
}

int main()
{
    char *a = "sadbutsad";
    char *b = "sad";
    int c = str(a,b);
}