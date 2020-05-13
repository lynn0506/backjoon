import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        BST bst = new BST();
        for(int i = 0; i<n; i++) {
            bst.add(scan.nextLine());
        }
        System.out.println(bst.preorder());
        System.out.println(bst.inorder());
        System.out.println(bst.postorder());
    }

    public static class Node {
        String data;
        Node left;
        Node right;

        Node() {
            this.data = null;
            this.left = null;
            this.right = null;
        }

        Node(String data) {
            this.data = data;
        }
    }
    public static class BST {
       Node root;

        public BST() {
            this.root = new Node("A");
        }

        public BST(Node ro) {
            this.root = ro;
        }

        public void add(String str) {
            String rt = str.substring(0, 1);
            String l = str.substring(2, 3);
            String r = str.substring(4, 5);

            Node target = search(root, rt);
            if(!r.equals("."))
                target.right = new Node(r);
            if(!l.equals("."))
                target.left = new Node(l);
        }

        public Node search(Node root, String target) {
            if(root.data.equals(target))
                return root;
            else {
                String str = inorder(root);
                String pre = "";

                for(int i = 0; i<str.length(); i++) {
                    if(str.substring(i, i+1).equals(root.data)) {
                        pre = str.substring(0, i);
                    }
                }

                if(pre.contains(target) && root.left != null)
                   return search(root.left, target);

                else 
                    return search(root.right, target);
            }
        }


        public String preorder() {
            return preorder(root);
        }
        public String preorder(Node r) {
            String line = "";
            line = line.concat(r.data);

            if(r.left != null)
                line = line.concat(preorder(r.left));
            if(r.right != null)
                line = line.concat(preorder(r.right));

            return line;
        }

        public String inorder() {
            return inorder(root);
        }

        public String inorder(Node r) {
            String line = "";
            if(r.left != null) {
                line = line.concat(inorder(r.left));
            }
            line = line.concat(r.data);
            if(r.right != null) {
                line = line.concat(inorder(r.right));
            }
            return line;
        }

        public String postorder() {
            return postorder(root);
        }

        public String postorder(Node r) {
            String line = "";
            if(r.left != null) {
                line = line.concat(postorder(r.left));
            }
            if(r.right != null) {
                line = line.concat(postorder(r.right));
            }
            line = line.concat(r.data);
            return line;
        }
    }
} 
