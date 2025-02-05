import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class a67_q1a_abc_forbidden
{
    static String[] wordList;
    static int count = 0;
    
    public static void permutation(char[] word, int step, int a, int b, int c, int N, boolean[] banWords)
    {
        if (step == N) 
        {
            wordList[count++] = new String(word);
            return;
        }

        char prev = ' ';
        if(step > 0) prev = word[step - 1];

        if (a > 0 && !(prev == 'A' && banWords[0]) && !(prev == 'B' && banWords[3]) && !(prev == 'C' && banWords[6]))
        {
            word[step] = 'A';
            permutation(word, step + 1, a - 1, b, c, N, banWords);
        }
        if (b > 0 && !(prev == 'A' && banWords[1]) && !(prev == 'B' && banWords[4]) && !(prev == 'C' && banWords[7]))
        {
            word[step] = 'B';
            permutation(word, step + 1, a, b - 1, c, N, banWords);
        }
        if (c > 0 && !(prev == 'A' && banWords[2]) && !(prev == 'B' && banWords[5]) && !(prev == 'C' && banWords[8]))
        {
            word[step] = 'C';
            permutation(word, step + 1, a, b, c - 1, N, banWords);
        }
    }

    public static void main(String[] args) {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));)
        {
            String[] data = reader.readLine().trim().split("\\s+");
            int N = Integer.parseInt(data[0]);
            int a = Integer.parseInt(data[1]);
            int b = Integer.parseInt(data[2]);
            int c = Integer.parseInt(data[3]);
            int M = Integer.parseInt(reader.readLine().trim());

            if (a == 0 && b == 0 && c == 0)
            {
                System.out.println(0);
                return;
            }
            
            if (M == 9) 
            {
                System.out.println(0);
                return;
            }

            if (a + b + c < N) 
            {
                System.out.println(0);
                return;
            }            

            boolean[] banWords = new boolean[9];

            for(int i = 0; i < M; i++)
            {
                String ban = reader.readLine();
                int index = 3*(ban.charAt(0) - 'A') + (ban.charAt(1) - 'A');
                banWords[index] = true;
            }
            
            wordList = new String[(int) Math.pow(3, N)];

            char[] word = new char[N];
            Arrays.fill(word, ' ');
            permutation(word, 0, a, b, c, N, banWords);

            System.out.println(count);
            for (int i = 0; i < count; i++) 
            { 
                System.out.println(wordList[i]);
            }
        }
        catch(IOException e) {}
    }
}