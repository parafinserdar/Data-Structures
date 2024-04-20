public class Main {
    public static void main(String[] args) {
        DynamicArray dynamicArray = new DynamicArray(5);

        dynamicArray.add("A");
        dynamicArray.add(42);
        dynamicArray.add(2.3);
        dynamicArray.add(2.6);
        dynamicArray.add(5);
        dynamicArray.add("Parafin");
        System.out.println(dynamicArray);
        System.out.println("size: " + dynamicArray.size);
        System.out.println("capacity: " + dynamicArray.capacity);
        System.out.println("empty: " + dynamicArray.isEmpty());
    }
}