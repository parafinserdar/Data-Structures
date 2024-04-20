public class Main {
    public static void main(String[] args) {
        BinarySearchTree bTree = new BinarySearchTree();

        bTree.insert(new Node(42));
        bTree.insert(new Node(25));
        bTree.insert(new Node(9));
        bTree.insert(new Node(100));
        bTree.insert(new Node(8));

        bTree.display();
        boolean a = bTree.search(9);
        boolean b = bTree.search(2555);
        System.out.println(a);
        System.out.println(b);
        System.out.print("------" + "\n");
        bTree.remove(942525);
        bTree.remove(100);
        bTree.display();
    }
}