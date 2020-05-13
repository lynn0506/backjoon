import java.util.*;

public class Main {
    static List<ArrayList<Integer>> list = new ArrayList<>();
    static int N;
    static int M;
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       N = scan.nextInt();
       M = scan.nextInt();
       int src = scan.nextInt();
        for(int i = 0; i<=N; i++)
            list.add(new ArrayList<>());
      for(int i = 0; i<M; i++) {
           int a = scan.nextInt();
           int b = scan.nextInt();

          list.get(a).add(b);
           list.get(b).add(a);
       }

       DFS(src);
       BFS(src);
    }

    public static void DFS(int src) {
        Stack<Integer> stack = new Stack<>();
        Set<Integer> set = new HashSet<>();
        set.add(src);
       List<Integer> l = new ArrayList<>();
        l = new ArrayList<>(list.get(src));
        Collections.sort(l);
        System.out.print(src);
        for(int i = 1; i <= l.size(); i++) {
            stack.push(l.get(l.size()-i));
        }

       while(!stack.isEmpty()) {
           int trg = stack.pop();
           if(!set.contains(trg)) {
               set.add(trg);
               System.out.print(" " + trg);
               List<Integer> w = list.get(trg);
               Collections.sort(w);
               for(int i = 1; i<=w.size(); i++) {
                   stack.push(w.get(w.size()-i));
               }
           }
       }
       System.out.println();
    }

    public static void BFS(int src) {
        Queue<Integer> queue = new ArrayDeque<>();
        List<Integer> l = list.get(src);
        Collections.sort(l);
        Set<Integer> set = new HashSet<>();
        set.add(src);

        for(int i = 0; i<l.size(); i++) {
            queue.add(l.get(i));
        }
        System.out.print(src);

        while(!queue.isEmpty()) {
            int trg = queue.poll();
            if(!set.contains(trg)) {
                set.add(trg);
                System.out.print(" "+trg);
                List<Integer> w = list.get(trg);
                for(int i = 0; i<w.size(); i++) {
                    queue.add(w.get(i));
                }
            }
        }
        System.out.println();
    }
} 
