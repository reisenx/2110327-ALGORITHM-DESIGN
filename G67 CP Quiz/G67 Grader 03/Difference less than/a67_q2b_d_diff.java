import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class a67_q2b_d_diff
{
    static int n;
    static long d,ans;
    static long[] A;
    public static void main(String[] args) throws IOException
    {
        // Initialize Java BufferedReader for input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer data = new StringTokenizer(reader.readLine());
        n = Integer.parseInt(data.nextToken());
        d = Long.parseLong(data.nextToken());
        
        // Input ArrayList A
        data = new StringTokenizer(reader.readLine());
        A = new long[n];
        for(int i = 0; i < n; i++)
        {
            A[i] = Long.parseLong(data.nextToken());
        }

        // Sort the ArrayList A in ascending order
        Arrays.sort(A);

        // Count amount of pairs that satisfy |A[j] - A[i]| >= d when i < j
        // Since we need to check all pairs, sorting it beforehand is better
        // Brute force uses O(n^2) | This method uses O(nlog(n))
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            // j is index of lowest A[j] that greater than A[i] + d
            // No need to reset 'j' to 0 each A[i] because A is already sorted.
            while(j < n && A[j] <= A[i] + d) { j++; }
            // We can assume that all number from A[i] to A[j - 1] are satisfy the problem
            ans += (j - i - 1);
        }

        // Output
        System.out.println(ans);
    }
}