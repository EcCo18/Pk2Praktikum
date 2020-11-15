char to_upper_case(char c)
{
    if(c > 'a' && c < 'z')
    {
        c = c - 20;
        return c;
    }else
    {
        return c;
    }
}