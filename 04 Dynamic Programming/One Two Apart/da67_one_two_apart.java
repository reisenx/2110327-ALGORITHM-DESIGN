
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class da67_one_two_apart
{
    public final static int MOD = 100000007;
    public static int N, ans = 0;
    public static int[][] state = new int[1000001][7];

    public static int addMod(int a, int b)
    {
        return ((a % MOD) + (b % MOD)) % MOD;
    }

    public static int addMod(int a, int b, int c)
    {
        return (addMod(a,b) + (c % MOD)) % MOD;
    }

    public static void main(String[] args)
    {
        state[0] = new int[] {0,0,0,0,0,0,0};
        state[1] = new int[] {1,1,0,0,1,0,0};
        state[2] = new int[] {1,1,1,1,1,1,1};
        for(int i = 3; i < 1000001; i++)
        {
            state[i][0] = addMod(state[i-1][0], state[i-1][2], state[i-1][5]);
            state[i][1] = addMod(state[i-1][0], state[i-1][2]);
            state[i][2] = addMod(state[i-1][1], state[i-1][3]);
            state[i][3] = addMod(state[i-1][1], state[i-1][3]);
            state[i][4] = addMod(state[i-1][0], state[i-1][5]);
            state[i][5] = addMod(state[i-1][4], state[i-1][6]);
            state[i][6] = addMod(state[i-1][4], state[i-1][6]);
        }

        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)))
        {
            N = Integer.parseInt(reader.readLine().trim());
            for(int i = 0; i < 7; i++)
            {
                ans = addMod(ans, state[N][i]);
            }
            System.out.println(ans);
        }
        catch(IOException e) {}
    }
}