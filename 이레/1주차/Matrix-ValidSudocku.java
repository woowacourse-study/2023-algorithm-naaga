import java.util.*;

class Matrix-ValidSudocku {
    static int[][] map = new int[9][9];
    static int[] GridY = {0,0,0,1,1,1,2,2,2};
    static int[] GridX = {0,1,2,0,1,2,0,1,2};
    static int[] coordinateOfGrid = {0,3,6};
    
    public boolean isValidSudoku(char[][] board) {
        for(int i=0; i<9 ; i++) {
            for(int j =0; j<9 ; j++) {
                if(Character.isDigit(board[i][j])){
                    map[i][j]= (int)board[i][j];
                }else if (board[i][j] == '.') {
                    map[i][j] = 0; // Assign 0 for empty cells
                }
            }
        }
        return hasNoRepititionInGrid() && hasNoRepititionInGridColumn()
                &&hasNoRepititionInGridRow();
        
    }
    
    static boolean hasNoRepititionInGrid() {
        for(int i : coordinateOfGrid) {
            for(int j : coordinateOfGrid){
                Set<Integer> grid = new HashSet();
                for(int k = 0 ; k<9; k++) {
                    int num = map[i+GridY[k]][j+GridX[k]];
                    if(num != 0&&!grid.add(num)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    static boolean hasNoRepititionInGridRow() {
        for(int i = 0 ; i<9;i++) {
            Set<Integer> grid = new HashSet();
            for(int j = 0 ; j<9;j++) {
                int num = map[i][j];
                if(num != 0) {
                    if(!grid.add(num)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    static boolean hasNoRepititionInGridColumn() {
        for(int i = 0 ; i<9;i++) {
            Set<Integer> grid = new HashSet();
            for(int j = 0 ; j<9;j++) {
                int num = map[j][i];
                if(num != 0 && !grid.add(num)) {
                    return false;
                }
            }
        }
        return true;
        
    }
}
