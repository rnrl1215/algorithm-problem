//https://vprog1215.tistory.com/143

class Solution {

    private int mNumberOfArea;
    private int mMaxSizeOfOnerArea;

    //위 아래 왼쪽 오른쪽 탐색방향 정의
    private int []dirx = {0,0,1,-1};
    private int []diry = {-1,1,0,-0};
    
    // 전체 맵 사이즈
    private int mapXsize;
    private int mapYsize;
    
    // 방문을 체크한다.
    private int [][]checkMap;


    // 다음 탐색할 부분이 맵안에 있는지 체크한다.
    boolean checkBoundary(int dx, int dy) {
        if(dx < 0 || dx >= mapXsize || dy < 0 || dy >= mapYsize) {
            return false;
        } else {
            return true;
        }
    }

    public int solve(int dx, int dy, int[][] picture, int findNum) {
        // 방문을 해줬다는 표시를 남긴다.
        checkMap[dx][dy] = findNum;
        
        // 해당 픽셀 카운트를 계산한다.
        int count = 0;
        for(int i=0; i < 4; i ++) {
            int ndx = dx + dirx[i];
            int ndy = dy + diry[i];

            // 방문 체크 및 바운더리 체크, picture의 영역 체크
            if (checkBoundary(ndx, ndy) && checkMap[ndx][ndy] == 0 && picture[ndx][ndy] == findNum) {
                count += solve(ndx, ndy, picture, findNum);
            }
        }

        // count + 1 은 현재까지 방문한 셀들의 수를 카운트
        return count+1;
    }

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        int maxNum = 0;

        mapXsize = m;
        mapYsize = n;
        int[] answer = new int[2];
        checkMap = new int[m][n];

        for(int i = 0; i <m; i++) {
            for(int j = 0; j < n; j++) {
                // 사진 전체를 탐색한다.
                // 방문 여부와 picture의 값을 체크한다.
                if(picture[i][j] != 0 && checkMap[i][j] == 0 ) {
                    numberOfArea++;
                    if(maxNum <= picture[i][j]) {
                        maxNum = picture[i][j];
                    }
                    int pixelCount = solve(i,j,picture,picture[i][j]);
                    if(pixelCount > maxSizeOfOneArea) {
                        maxSizeOfOneArea = pixelCount;
                    }
                }
            }
        }
        

        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}
