bool    are_char_matching(char str1, char str2)
{
    char    increment;

    increment = str1 + 1;
    if (str1 != str2)
    {
        if (increment == str2 || (increment == 123 && str2 == 97))
            return (true);
        return (false);
    }
    return (true);
}

bool    check_unevened_sized_arrays(char *str1, char *str2)
{
    int     index;
    int     cursor;
    int     previous;
    bool    modification;

    index = 0;
    previous = 0;
    modification = false;
    while (str2[index] != '\0')
    {
        cursor = previous;
        while (str1[cursor] != '\0')
        {
            if (are_char_matching(str1[cursor], str2[index]))
            {
                previous = cursor;
                modification = true;
                break;
            }
            cursor++;
        }
        if (str1[cursor] == '\0' && str2[index + 1] == '\0')
            return (false);
        if (str1[cursor] == '\0' && modification == false)
            return (false);
        index++;
    }
    return (modification);
}

bool    check_equally_sized_arrays(char* str1, char* str2)
{
    int     index;
    bool    modification;

    index = 0;
    modification = false;
    while (str2[index] != '\0')
    {
        if (!are_char_matching(str1[index], str2[index]))
            return (false);
        index++;
    }
    return (true);
}

bool canMakeSubsequence(char* str1, char* str2) 
{
    int str1_len;
    int str2_len;

    str1_len = strlen(str1);
    str2_len = strlen(str2);
    if(str1_len >= str2_len)
    {
        if (str1_len == str2_len)
            return(check_equally_sized_arrays(str1, str2));
        return (check_unevened_sized_arrays(str1, str2));
    }
    return (false);
}
