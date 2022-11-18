
import java.util.ArrayList;
import java.util.List;

class Solution442 {
    public static void main(String[] args) {
        int arr[] = { 4, 3, 2, 7, 8, 2, 3, 1 };

        List<Integer> dup = findDuplicates(arr);

        for (int i = 0; i < dup.size(); i++) {
            System.out.println(dup.get(i));
        }
    }

    public static List<Integer> findDuplicates(int[] arr) {
        List<Integer> duplicates = new ArrayList<>();

        for (int i = 1; i <= arr.length; i++) {
            if (arr[i] < 0) {
                duplicates.add(i);
            } else {
                System.out.println(i);
                System.out.println(arr[i - 1]);
                System.out.println(arr[arr[i - 1]]);
                arr[arr[i - 1]] *= -1;
            }
        }

        return duplicates;
    }
}