char to_upper_case(char c)
{
    if(c > 'a' && c < 'z')
    {
        c = c - ('a' - 'A');
        return c;
    }else
    {
        return c;
    }
}