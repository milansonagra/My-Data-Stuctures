package DSF_Queue;
class CircularQueue
{
    private char[] queue;
    private final int size;
    private int F,R;
    
    CircularQueue(int size)
    {
        this.size=size;
        queue=new char[size];
        F=R=-1;
    }
    public void insert(char c)
    {
        if(F==R+1)
        {
            System.out.println("Circular Queue OVERFLOW !");
        }
        else if(F==-1&&R==-1)
        {
            F=R=0;
            queue[R]=c;
            System.out.println("\tInsert element ->"+queue[R]+"  at \t F="+F+" and R="+R);
        }
        else
        {
            if(R==size-1)
            {
                R=0;
            }
            else
            {
                R++;
            }      
            queue[R]=c;
            System.out.println("\tInsert element ->"+queue[R]+"  at \t F="+F+" and R="+R);      
        }
    }
    public char delete()
    {
        char r;
        if(R==F-1)
        {
            System.out.println("Circular Queue UNDERFLOW !");
            F=R=-1;
            return '\0';
        }
        else if(R==-1)
        {
           System.out.println("Circular Queue Empty !");
           return '\0';
        }
        else
        {
            r=queue[F];
            System.out.println("\tDelete element ->"+queue[F]+" from  F="+F+" and R="+R);
            if(F==4)
            {
                F=0;
            }
            else
            {
                F++;
            }
            return r;
        }
    }
}
public class Circular_Queue 
{
    public static void main(String[] args) 
    {
        CircularQueue A=new CircularQueue(5);
        A.insert('1');
        A.insert('2');
        A.insert('3');
        A.delete();
        A.insert('4');
        A.insert('5');
        A.insert('6');
        A.insert('7');
        A.insert('A');
        A.insert('9');
        A.delete();
        A.insert('C');
        A.delete();
        A.delete();
        A.delete();
        A.delete();
        A.delete();
    }
}
