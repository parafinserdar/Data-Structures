public class Main {
    public static void main(String[] args) {
        CircularLinkedList list = new CircularLinkedList();

        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(5);


        System.out.print("Başlangıçtaki Liste: ");
        list.display();


        list.insertAtPosition(10, 2);
        System.out.print("Pozisyona Eleman Ekleme Sonrası Liste: ");
        list.display();

        list.deleteAtPosition(3);
        System.out.print("Pozisyondaki Elemanı Silme Sonrası Liste: ");
        list.display();
    }
}