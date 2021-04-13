public class MergeSort {

    MergeSort(){};

    public void merge(int []data, int start, int center, int end)
    {
        int i = start; // 배열 앞부분 인덱스
        int j = center+1; // 배열 중간 인덱스
        int k = start; // 시작점.

        int[] tmp = new int [data.length];

        // 앞과 뒷쪽 부분중 제일 적은 값을 앞에 채운다.
        while (i <= center && j <= end) {
            if (data[i] <= data[j]) {
                tmp[k++] = data[i++];
            } else {
                tmp[k++] = data[j++];
            }
        }

        // while 문을 둘중에 하나만 실행됨.
        while (i <= center) {
            tmp[k++] = data[i++];
        }

        while (j <= end) {
            tmp[k++] = data[j++];
        }

        // 정렬된 배열을 전체 넣어줌.
        for (int index=start; index<=end; index++){
            data[index] = tmp[index];
        }

    }

    public void mergerSort(int[] data, int start, int end)
    {
        // 중간지점 구함
        if (start < end) {
            int center = (start + end) / 2;
            mergerSort(data, start, center);
            mergerSort(data, center + 1, end);
            merge(data, start, center, end);
        }
    }

    public static void main(String[] args){
        int []data = {1,33,4,22,56,2};
        MergeSort msort = new MergeSort();
        msort.mergerSort(data,0, data.length-1);
        for (int i =0; i<data.length; i++){
            System.out.println(data[i]);
        }
    }
};



