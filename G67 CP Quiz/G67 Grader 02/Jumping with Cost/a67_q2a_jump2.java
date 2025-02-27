import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class a67_q2a_jump2
{
    static int n,k;
    static int[] a,b;
    public static void main(String[] args)
    {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)))
        {
            String[] data = reader.readLine().trim().split(" ");
            n = Integer.parseInt(data[0]);
            k = Integer.parseInt(data[1]);
            
            data = reader.readLine().trim().split(" ");
            a = new int[data.length];
            for(int i = 0; i < data.length; i++)
            {
                a[i] = Integer.parseInt(data[i]);
            }

            data = reader.readLine().trim().split(" ");
            b = new int[data.length];
            for(int i = 0; i < data.length; i++)
            {
                b[i] = Integer.parseInt(data[i]);
            }

            for(int i = 1; i < Math.min(n,k); i++)
            {
                int bestJump = Integer.MIN_VALUE;
                for(int j = 0; j < i; j++)
                {
                    if(a[i-j-1] - b[j] > bestJump)
                    {
                        bestJump = a[i-j-1] - b[j];
                    }
                }
                a[i] += bestJump;
            }

            for(int i = k; i < n; i++)
            {
                int bestJump = Integer.MIN_VALUE;
                for(int j = 0; j < k; j++)
                {
                    if(a[i-j-1] - b[j] > bestJump)
                    {
                        bestJump = a[i-j-1] - b[j];
                    }
                }
                a[i] += bestJump;
            }

            System.out.println(a[n-1]);
        }
        catch(IOException e) {}
    }
}
