import java.util.Scanner;
public class Stack
 {
   
    int arr[];
    int top=-1;
    int n;

    //constructor to initialize the array
    Solution()
    {
        Scanner s=new Scanner(System.in);
        System.out.print("enter no of elements in the array : ");
         n=s.nextInt();
         arr=new int[n];
    }
    
    //method to push the element into the stack
    void push()
    {
        if(isfull())
        {
            System.out.println("stack full");
        }
        else
        {
        System.out.println("--\nenter the value to push : ");
        Scanner s=new Scanner(System.in);
        int v=s.nextInt();
       
        arr[++top]=v;
        }
    }
     //method to pop the element from the stack
    void pop()
    {
       if(isempty())
       {
        System.out.println("stack empty");
       }
       else
       {
       top--;
       }
    }

     //method to pop the specific element from the stack
    void pop_p()
    {
        if(isempty())
        {
         System.out.println("stack empty");
        }
        else
        {
        System.out.println("--\nenter the value to pop : ");
        Scanner s=new Scanner(System.in);
        int u=s.nextInt();
        boolean found =false;
        for(int i=0;i<=top;i++)
        {
            if(arr[i]==u)
            {
                for(int k=i;k<top;k++)
                {
                    arr[k]=arr[k+1];
                }
                top--;
                found =true;
                break;
            }
        }
        if(!found)
        {
            System.out.println("element is not found");
        }
    }
    }

    //display the stack
    void show()
    {
        if(isempty())
        {
            System.out.println("stack empty");
        }
        else
        {
        for(int i=top;i>=0;i--)
        {
            System.out.println(arr[i]);
        }
    }
    }

    //display the top element
    void peek()
    { 
        if(isempty())
        {
            System.out.println("stack empty");
        }
        else
        {
            System.out.println("top element : "+arr[top]);
        }
    }

    //display the current size
    void size()
    {
        if(isempty())
        {
            System.out.println("stack empty");
        }
        else
        {
            System.out.println("current size : "+ (top+1));
        }
    }

    //checking stack full
    boolean isfull()
    {
        return top==n-1;
    }

    //checking stack empty
    boolean isempty()
    {
        return top==-1;
    }

 
 public static void main(String[] args)
        {
          Solution sl=new Solution();
          Scanner ss=new Scanner(System.in);
         
          int choice;
          int x;
          System.out.print("Enter choice (1: push, 2: pop, 3: show, 4: pop specific value, 5: peek, 6: size): ");
          do
          {
            System.out.print("-\nenter choice : ");
            choice =ss.nextInt();
               switch(choice)
               {
                case 1:
                sl.push();
                break;

                case 2:
                sl.pop();
                break;

                case 3:
                sl.show();
                break;

                case 4:
                sl.pop_p();
                break;

                case 5:
                sl.peek();
                break;

                case 6:
                sl.size();
                break;


                default:
                System.out.println("invalid choice");
                break;
               };
               System.out.print("-\npress 0 to continue : ");
                  x=ss.nextInt();
          }while(x==0);
         }
         
     }
 
 
 
 