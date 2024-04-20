public class Main {
    public static void main(String[] args) {
        DoublyLinkedList doublyLinkedList = new DoublyLinkedList();

        doublyLinkedList.insertAtEnd(10);
        doublyLinkedList.insertAtEnd(20);
        doublyLinkedList.insertAtEnd(30);
        doublyLinkedList.insertAtBeginning(5);

        doublyLinkedList.display();
    }
}