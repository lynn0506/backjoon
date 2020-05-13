import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String ppap = bf.readLine();
        Stack<String> stack = new Stack<>();

        for (int i = 0; i < ppap.length(); i++) {
            if (ppap.substring(i, i + 1).equals("P"))
                stack.push(ppap.substring(i, i + 1));
            else if (ppap.substring(i, i + 1).equals("A")) {
                String A = "";
                for (int j = 0; j < 2; j++) {
                    if (!stack.isEmpty()) {
                        A = A.concat(stack.pop());
                   }
                }
                A = A.concat(ppap.substring(i, i + 1));
                if (i + 1 != ppap.length()) {
                    i++;
                    A = A.concat(ppap.substring(i, i + 1));
                }
                if (A.equals("PPAP"))
                    stack.push("P");
                else {
                    System.out.println("NP");
                    return;
                }
            }
        }
        String A = "";
        while (!stack.isEmpty()) {
            A = A.concat(stack.pop());
        }
        if(A.equals("P"))
            System.out.println("PPAP");
        else
            System.out.println("NP");
    }
} 
