import java.util.EmptyStackException;
public class Queue {
    private int maxSize;
    private int[] queueArray;
    private int front;
    private int rear;
    private int currentSize;

    public Queue(int size) {
        this.maxSize = size;
        this.queueArray = new int[maxSize];
        this.front = 0;
        this.rear = -1;
        this.currentSize = 0;
    }

    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full, cannot enqueue " + value);
        } else {
            if (rear == maxSize - 1) {
                rear = -1;
            }
            queueArray[++rear] = value;
            currentSize++;
            System.out.println(value + " enqueued to queue");
        }
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            int value = queueArray[front++];
            if (front == maxSize) {
                front = 0;
            }
            currentSize--;
            System.out.println(value + " dequeued from queue");
            return value;
        }
    }

    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            return queueArray[front];
        }
    }

    public boolean isEmpty() {
        return (currentSize == 0);
    }

    public boolean isFull() {
        return (currentSize == maxSize);
    }


    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
        } else {
            System.out.print("Queue (front to rear): ");
            int index = front;
            for (int i = 0; i < currentSize; i++) {
                System.out.print(queueArray[index++] + " ");
                if (index == maxSize) {
                    index = 0;
                }
            }
            System.out.println();
        }
    }
}