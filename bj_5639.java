import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BST bst = new BST(Integer.parseInt(scan.nextLine()));

        while(scan.hasNext()) {
            bst.add(bst.root, Integer.parseInt(scan.nextLine()));
        }

        System.out.println(bst.postorder());
    }

    public static class BST {
        Node root;

        public BST(int root) {
            this.root = new Node(root);
        }

        public static void add(Node root, int input) {
            if(input < root.data)
            {
                if(root.left == null)
                    root.left = new Node(input);
                else
                    add(root.left, input);
            

            else if(input > root.data)
            {
                if(root.right == null)
                    root.right = new Node(input);
                else
                    add(root.right, input);
            }
        }

        public String postorder() {
            return postorder(root);
        }

        public String postorder(Node root)
        {
            String line = "";
            if(root.left != null)
                postorder(root.left);
            if(root.right != null)
                postorder(root.right);

            System.out.println(root.data);
            return line;
        }
    }

    public static class Node {
        Node right;
        Node left;
        int data;

        public Node() {
            this.right = null;
            this.left = null;
            this.data = 0;
        }

        public Node(int n) {
            this.data = n;
        }
    }
}}
