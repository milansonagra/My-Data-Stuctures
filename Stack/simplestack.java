package dsf.stack;
import java.util.Scanner;
class IntStack
{
    private int top=-1;
    private int length_stack;
   
    int[] st=new int[10];
    public int push(int m)
    {
        top++;
        st[top]=m;
        return top;
    }
    public int pop()
    {
        if(top==-1)
        {
            return '\0';
        }
        int ans=st[top];
        st[top]='\0';
        top--;
        return ans;
    }
}
public class simplestack 
{
    public static void main(String[] args) 
    {
        Scanner ip=new Scanner(System.in);
        
        IntStack Stack1=new IntStack();
        System.out.print("Enter the number of element :");
        int no_element=ip.nextInt();
        int element;
        while(no_element>0)
        {
            System.out.print("\tEnter element\t->");
            element=ip.nextInt();
            System.out.println("pointer value:"+Stack1.push(element));
            no_element--;
        }
        
        int no_pop;
        System.out.print("Enter number of pop:");
        no_pop=ip.nextInt();
        while(no_pop>0)
        {
            int temp;
            if((temp=Stack1.pop())=='\0')
            {
                System.out.println("STACK IS EMPTY.");
                break;
            }
            System.out.println("\tpop element ->"+temp);
            no_pop--;
        } 
    }
}
