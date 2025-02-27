import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class a67_q2a_stable_sort
{
    static int n,m;
    static int[] A;
    static StringBuilder result = new StringBuilder();
    public static void main(String[] args)
    {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));)
        {
            String[] data = reader.readLine().trim().split(" ");
            n = Integer.parseInt(data[0]);
            m = Integer.parseInt(data[1]);

            data = reader.readLine().trim().split(" ");
            A = new int[data.length];
            for(int i = 0; i < data.length; i++)
            {
                A[i] = Integer.parseInt(data[i]);
            }

            for(int q = 0; q < m; q++)
            {
                data = reader.readLine().trim().split(" ");

                boolean isSorted = true;
                boolean isStable = true;
                for(int i = 1; i < n; i++)
                {
                    int prevIdx = Integer.parseInt(data[i - 1]) - 1;
                    int currentIdx = Integer.parseInt(data[i]) - 1;
                    int prevValue = A[prevIdx];
                    int currentValue = A[currentIdx];

                    if(currentValue < prevValue)
                    {
                        isSorted = false;
                        isStable = false;
                        break;
                    }
                    if(currentValue == prevValue && currentIdx < prevIdx)
                    {
                        isStable = false;
                    }
                }

                if(isSorted) { result.append("1 "); }
                else { result.append("0 "); }
                if(isStable) { result.append("1\n"); }
                else { result.append("0\n"); }
            }
            
            System.out.print(result);
        }
        catch(IOException e) {}
    }
}