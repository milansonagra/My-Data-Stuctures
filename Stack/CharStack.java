package dsf.stack;

class CharStack
{
   private int top=-1;
    private char[] st=new char[50];
    CharStack()
    {
        st[0]='\0';
    }
    
    public int push(char m)
    {
        top++;
        st[top]=m;
        return top;
    }
    public char pop()
    {
        if(top==-1)
        {
            return '\0';
        }
        char ans=st[top];
        //st[top]='\0';
        top--;
        return ans;
    }
    public char showtop()
    {
        if(top==-1)
        {
            return '\0';
        }
        char ans=st[top];
        return ans;
    }    
}
