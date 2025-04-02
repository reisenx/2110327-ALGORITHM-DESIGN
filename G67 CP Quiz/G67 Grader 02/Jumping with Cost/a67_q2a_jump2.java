import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class a67_q2a_jump2
{
    static int n,k;
    static int[] a,b;
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer data = new StringTokenizer(reader.readLine());
        n = Integer.parseInt(data.nextToken());
        k = Integer.parseInt(data.nextToken());
        
        data = new StringTokenizer(reader.readLine());
        a = new int[n];
        for(int i = 0; i < n; i++)
        {
            a[i] = Integer.parseInt(data.nextToken());
        }

        data = new StringTokenizer(reader.readLine());
        b = new int[k];
        for(int i = 0; i < k; i++)
        {
            b[i] = Integer.parseInt(data.nextToken());
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
}
