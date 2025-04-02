import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class da67_f_abc_permutation
{
    public static StringBuilder result = new StringBuilder();
    public static int count = 0;
    
    public static void permutation(char[] word, int step, int a, int b, int c, int N)
    {
        if (step == N)
        {
            result.append(word).append("\n");
            count++;
            return;
        }

        if (a > 0)
        {
            word[step] = 'A';
            permutation(word, step + 1, a - 1, b, c, N);
        }
        if (b > 0)
        {
            word[step] = 'B';
            permutation(word, step + 1, a, b - 1, c, N);
        }
        if (c > 0)
        {
            word[step] = 'C';
            permutation(word, step + 1, a, b, c - 1, N);
        }
    }

    public static void main(String[] args) {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));)
        {
            String[] data = reader.readLine().trim().split(" ");
            int N = Integer.parseInt(data[0]);
            int a = Integer.parseInt(data[1]);
            int b = Integer.parseInt(data[2]);
            int c = Integer.parseInt(data[3]);

            if (a == 0 && b == 0 && c == 0)
            {
                System.out.println(0);
                return;
            }

            if (a + b + c < N)
            {
                System.out.println(0);
                return;
            }
            
            char[] word = new char[N];
            Arrays.fill(word, ' ');
            permutation(word, 0, a, b, c, N);

            System.out.println(count);
            System.out.print(result);
        }
        catch(IOException e) {}
    }
}
