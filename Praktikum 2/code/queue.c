const int len = 2;
int array[len];
int start = 0;
int end = 0;
int fill = 0;

void enqueue(int i)
{
    if(fill != 0)
    {
        if(((end + 1)%len) != start)
        {
            end  = ((end+1) % len);
            array[end] = i;
            fill++;
        }else
        {
            array[end] = i;
        }
    }else
    {
        array[end] = i;
        fill++;
    }
    
}

int dequeue()
{
    if(fill == 0)
    {
        return -1;
    }else
    {
        if(fill != 1)
        {
            int erg = array[start];
            start = ((start+1) % len);
            fill--;
            return erg;
        }else
        {
            fill--;
            return array[start];
        }
    }
}