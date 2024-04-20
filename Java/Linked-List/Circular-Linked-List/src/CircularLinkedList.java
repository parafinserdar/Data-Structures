class CircularLinkedList {
    private Node head;
    private Node tail;

    public CircularLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int size() {
        if (isEmpty()) return 0;

        int count = 0;
        Node current = head;
        do {
            count++;
            current = current.next;
        } while (current != head);

        return count;
    }

    public void insert(int data) {
        Node newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode.next = head;
        } else {
            tail.next = newNode;
            tail = newNode;
            tail.next = head;
        }
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Liste boş.");
            return;
        }

        Node current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    public void insertAtPosition(int data, int position) {
        if (position < 0 || position > size()) {
            System.out.println("Geçersiz pozisyon.");
            return;
        }

        Node newNode = new Node(data);
        if (position == 0) {
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
                newNode.next = head;
            } else {
                newNode.next = head;
                head = newNode;
                tail.next = head;
            }
        } else if (position == size()) {
            tail.next = newNode;
            tail = newNode;
            tail.next = head;
        } else {
            Node current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current.next;
            }
            newNode.next = current.next;
            current.next = newNode;
        }
    }

    public void deleteAtPosition(int position) {
        if (isEmpty() || position < 0 || position >= size()) {
            System.out.println("Geçersiz pozisyon.");
            return;
        }

        if (position == 0) {
            if (size() == 1) {
                head = null;
                tail = null;
            } else {
                head = head.next;
                tail.next = head;
            }
        } else {
            Node current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current.next;
            }
            current.next = current.next.next;
            if (position == size() - 1) {
                tail = current;
            }
        }
    }
}