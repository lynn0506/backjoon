import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String N = scan.nextLine();
        int N_ = Integer.parseInt(N);
        String N_original = N;
        int original_N = N_;
        int M = Integer.parseInt(scan.nextLine());
        int count4 = N_ - 100;
        count4 = (count4 < 0)? -count4 : count4;

        String[] buttons = new String[M];

        for(int i = 0; i<M; i++) {
            buttons[i] = scan.next();
        }

        int count = 0;

        while(true) {
            for(int j = 0; j<M; j++) {
                if(N.contains(buttons[j])) {
                    N_--;
                    count++;
                    N = Integer.toString(N_)
                }
            }
            boolean check = false;

            for(int j = 0; j<M; j++) {
                if(N.contains(buttons[j])) {
                    check = true;
                    break;
                }
            }

            if(check == false) {
                count = count + N.length();
                break;
            }
            if(N_ <= 0) {
                if(check == true) count = 500000;
                break;
            }
        }

        N_ = original_N;
        N = N_original;

        int count2 = 0;
        while (true){
            for(int j = 0; j< M; j++) {
                if(N.contains(buttons[j])) {
                    N_++;
                    count2++;
                    N = Integer.toString(N_);
                }
            }
            boolean check = false;

            for(int j = 0; j<M; j++) {
                if(N.contains(buttons[j])) {
                    check = true;
                    break;
                }
            }
            if(check == false) {
                count2 = count2 + N.length();
                break;
            }

            if(N_ >= 1000000) {
                if(check == true ) count2 = 500000;
                break;
            }
         }

        int strstr = (count > count2)? (count4 < count2)? count4: count2 :
                (count4 < count)? count4: count;
        System.out.println(strstr);
    }
};
