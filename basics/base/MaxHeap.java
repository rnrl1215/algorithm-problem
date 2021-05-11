import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class MaxHeap {

    public static void maxHeapify(ArrayList<Integer> list, int idx, int size)
    {
        int leftChild = idx * 2 + 1;
        int rightChild = idx * 2 + 2;
        int updateIndex = idx;

        if (leftChild < size && list.get(updateIndex) < list.get(leftChild)) {
            updateIndex = leftChild;
        }

        if (rightChild < size && list.get(updateIndex) < list.get(rightChild)) {
            updateIndex = rightChild;
        }

        if (idx != updateIndex) {
            Collections.swap(list, idx, updateIndex);
            maxHeapify(list, updateIndex, size);
        }
    }


    public static void insert(ArrayList<Integer> list, int key) {
        list.add(key);
        int i = list.size()-1;
        while (i > 0 && list.get(i/2) < list.get(i)){
            Collections.swap(list, i/2, i);
            i = i/2;
        }
    }

    public static void delete(ArrayList<Integer> list, int key) {
        list.remove(list.size());
    }

    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();
        list.add(3);
        list.add(22);
        list.add(4);
        list.add(55);
        list.add(7);
        list.add(100);
        list.add(11);
        list.add(313);
        list.add(1);


        for(int  i = list.size()/2-1; i >= 0; i--) {
            maxHeapify(list, i, list.size());
        }

        insert(list, 120);

        int range = list.size()-1;
        for (int i = list.size() - 1; i > 0; i--) {
            Collections.swap(list, 0, i);
            maxHeapify(list, 0, range--);
        }

        for(int i = 0; i < list.size(); i++){
            System.out.println(list.get(i));
        }

    }
}
