import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class a67_q2a_stable_sort
{
    static int n,m;
    static int[] A;
    static StringBuilder result = new StringBuilder();
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(reader.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(reader.readLine());
        A = new int[n];
        for(int i = 0; i < n; i++)
        {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for(int q = 0; q < m; q++)
        {
            String[] data = reader.readLine().trim().split(" ");

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
}