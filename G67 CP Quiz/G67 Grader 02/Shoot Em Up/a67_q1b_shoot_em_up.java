import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class a67_q1b_shoot_em_up 
{
    static int time, ceiling, initial;
    static StringBuilder movements = new StringBuilder();

    public static void recursive(char[] move, int step, int current)
    {
        if(current <= 0 || current > ceiling) { return; }
        if(step == time) 
        { 
            movements.append(move).append("\n");
            return; 
        }

        move[step] = 'D';
        recursive(move, step + 1, current - 1);
        move[step] = 'S';
        recursive(move, step + 1, current);
        move[step] = 'U';
        recursive(move, step + 1, current + 1);
    }

    public static void main(String[] args)
    {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)))
        {
            String[] data = reader.readLine().trim().split(" ");
            time = Integer.parseInt(data[0]);
            ceiling = Integer.parseInt(data[1]);
            initial = Integer.parseInt(data[2]);

            char[] move = new char[time];
            Arrays.fill(move, ' ');

            recursive(move, 0, initial);
            System.out.print(movements);
        }
        catch(IOException e) {}
    }
}
