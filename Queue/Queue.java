package DSF_Queue;

class SimpleQueue
{
    private char[] queue;
    private int F,R;
    private final int size;
    
    SimpleQueue(int size)
    {
        this.size=size;
        queue=new char[this.size];
        F=R=-1;
    }
    public void insert(char c)
    {
        if(R>=size)
        {
            System.out.println("\t\t\nQueue OVERFLOW !");
            return;
        }
        else if(F==-1&&R==-1)
        {
            F=R=0;
            queue[R]=c;
            System.out.println("\tInsert element ->"+queue[R]+"\t at \t F="+F+" and R="+R);
        }
        else
        {
            R++;
            queue[R]=c;
            System.out.println("\tInsert element ->"+queue[R]+"\t at \t F="+F+" and R="+R);      
        }
    }
    public char delete()
    {
        char r;
        if(F>=R)
        {
            System.out.println("\t\t\nQueue UNDERFLOW !");
            F=R=-1;
        }
        else if(R==-1)
        {
            System.out.println("\t\t\nQueue Empty !");
        }
        else
        {
            r=queue[F];
            System.out.println("\tDelete element ->"+queue[R]+"\t at \tF="+F+" and R="+R);
            F++;
            return r;
        }
        return '\0';
    }
}
public class Queue 
{
    public static void main(String[] args) 
    {
        SimpleQueue Q1=new SimpleQueue(10);
       
        Q1.insert('1');
        Q1.insert('2');
        Q1.insert('3');
        Q1.insert('4');
        Q1.delete();// System.out.println("in main o/p="+Q1.delete());
        Q1.delete();// System.out.println("in main o/p="+Q1.delete());
        Q1.insert('5');
        Q1.insert('6');
    }
}
