import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        for (int i = 0; i<n; i++) {
            int m = Integer.parseInt(bf.readLine());
            int count = 1;
            HashMap<Integer, Integer> list = new HashMap<>();

            for (int j = 0; j < m; j++) {
                String line = bf.readLine();
                list.put(Integer.parseInt(line.split(" ")[0]),
                        Integer.parseInt(line.split(" ")[1]));

            }

            int sd = list.get(1);
            for (int k = 2; k <= m; k++) {
                if(list.get(k) < std){
                    count++;
                    std = list.get(k);
                }
                // list로 정렬된 수들 중에서 두번째 성적의 가장 작은 값들과 비교할 수 있도록한다,
                // std는 가장 작은 수인데, 이보다 더 작은 수가 나타나면 바꿔주는 것 => 시간초과를 피할 수 있다. 
            }
            System.out.println(count);
        }
    }
}t
