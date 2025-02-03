#include<iostream>
using namespace std;
int A,B,C;

/**
 * @details
 * Properties:
 * 1.) (a*b) mod c = ((a mod c) * (b mod c)) mod c
 * 2.) (a mod b) mod b = a mod b
 * ------------------------------------------
 * Prove: (a1*a2*a3) mod b = ((a1 mod b)*(a2 mod b)*(a3 mod b)) mod b
 * (a1*a2*a3) mod b = ((a1*a2)*a3) mod b
 * (a1*a2*a3) mod b = [((a1*a2) mod b) * (a3 mod b)] mod b
 * (a1*a2*a3) mod b = [[((a1 mod b)*(a2 mod b)) mod b] * [(a3 mod b) mod b]] mod b
 * Given X = (a1 mod b)*(a2 mod b) and Y = (a3 mod b)
 * (a1*a2*a3) mod b = [(X mod b) * (Y mod b)] mob b
 * (a1*a2*a3) mod b = (X*Y) mod b
 * (a1*a2*a3) mod b = ((a1 mod b)*(a2 mod b)*(a3 mod b)) mod b
 * From the proof above, we can always extend the multiplier and get
 * (a1*a2*a3*...*an) mod b = ((a1 mod b)*(a2 mod b)*...*(an mod b)) mod b
 * So (A^B) mod C = ((A mod C)^B) mod C
 * ------------------------------------------
 * Example: (17^13) mod 7
 * ---------- Reduce the base (A) -----------
 * (17^13) mod 7 = ((17 mod 7)^13) mod 7
 * (17^13) mod 7 = (3^13) mod 7
 * ---------- Calculate the modulo ----------
 * 13 = 8 + 4 + 1 or `1101` in base 2
 * So (3^13) mod 7 = ((3^8) * (3^4) * (3^1)) mod 7
 * ------------------------------------------
 * Step 1: A = 3^1 | B = 13 (13 mod 2 = 1) | result = 1
 * result = (3*1) mod 7
 * result = (3^1) mod 7
 * A = (3^2) mod 7
 * ------------------------------------------
 * Step 2: A = (3^2) mod 7 | B = 6  (6 mod 2 = 0)  | result = (3^1) mod 7
 * A = (((3^2) mod 7) * ((3^2) mod 7)) mod 7
 * A = ((3^2)*(3^2)) mod 7
 * A = (3^4) mod 7
 * ------------------------------------------
 * Step 3: A = (3^4) mod 7 | B = 3 (3 mod 2 = 1) | result = (3^1) mod 7
 * result = (((3^4) mod 7) * ((3^1) mod 7)) mod 7
 * result = ((3^4) * (3^1)) mod 7
 * A = ((3^4) mod 7 * (3^4) mod 7) mod 7
 * A = ((3^4) * (3^4)) mod 7
 * A = (3^8) mod 7
 * ------------------------------------------
 * Step 4: A = (3^8) mod 7 | B = 1 (1 mod 2 = 1) | result = ((3^4) * (3^1)) mod 7
 * result = (((3^8) mod 7) * (((3^4) * (3^1)) mod 7)) mod 7
 * result = ((3^8) * (3^4) * (3^1)) mod 7
 * A = ((3^8) mod 7 * (3^8) mod 7) mod 7
 * A = ((3^8) * (3^8)) mod 7
 * A = (3^16) mod 7
 * ------------------------------------------
 * Step 5: B = 0 <--- BREAK
 * result = (((3^8) mod 7) * (((3^4) * (3^1)) mod 7)) mod 7
 * result = ((3^8) * (3^4) * (3^1)) mod 7
 * result = (3^13) mod 7
 * result = (17^13) mod 7
 * ------------------------------------------
 */
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> A >> B >> C;
    
    int result = 1;
    A = A % C;
    while(B > 0)
    {
        if(B % 2 == 1) { result = (result * A) % C; }
        A = (A*A) % C;
        B /= 2;
    }
    cout << result;
    return 0;
}