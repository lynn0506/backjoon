import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static String num1;
    static String num2;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        num1 = bf.readLine();
        num2 = bf.readLine();
        System.out.println(LCS(num1.length(), num2.length()));
    }

    public static int LCS(int m, int n) {
        int[][] C = new int[m+1][n+1];

        for(int i = 0; i< m; i++) {
            C[i][0] = 0;
        }
        for(int i = 0;i<n; i++) {
            C[0][i] = 0;
        }

        for(int i = 1; i<= m; i++) {
            for(int j = 1; j<=n; j++) {
                if(num.substring(i-1, i).equals(num2.substring(j-1, j)))
                    C[i][j] = C[i-1][j-1]+1;
                else
                    C[i][j] = (C[i-1][j] > C[i][j-1])? C[i-1][j] : C[i][j-1];
            }
        }
        return C[m][n];
    }
}
1
