#include<bits/stdc++.h>
using namespace std;


bool checkCellPaths(vector<vector<char>>& b, string word, int i, int j, int idx){
    if(idx == word.size())
        return true;

    if(i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || word[idx] != b[i][j])
        return false;

    char temp = b[i][j];
    b[i][j] = '-';

    bool ans =  checkCellPaths(b, word, i, j-1, idx+1) || 
                checkCellPaths(b, word, i, j+1, idx+1) ||
                checkCellPaths(b, word, i-1, j, idx+1) ||
                checkCellPaths(b, word, i+1, j, idx+1) ;
    
    b[i][j] = temp;

    return ans;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(checkCellPaths(board, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;
}

void populateNQueensAns(int n,int i, vector<vector<string>>& ans,vector<string>& board,bool occupiedCols[], bool mainDiagonal[], bool altDiagonal[]){
    if(i == n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(occupiedCols[j] || mainDiagonal[i - j + n-1] || altDiagonal[i + j])
            continue;
        
        board[i][j] = 'Q';
        occupiedCols[j] = true;
        mainDiagonal[i - j + n-1] = true;
        altDiagonal[i + j] = true;

        populateNQueensAns(n, i+1, ans, board, occupiedCols, mainDiagonal, altDiagonal);

        board[i][j] = '.';
        occupiedCols[j] = false;
        mainDiagonal[i - j + n-1] = false;
        altDiagonal[i + j] = false;
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    bool occupiedCols[n] = {false};
    bool mainDiagonal[2*n-1] = {false};
    bool altDiagonal[2*n-1] = {false};
    populateNQueensAns(n, 0, ans, board, occupiedCols, mainDiagonal, altDiagonal);
    return ans;
}

void populateRatAns(int n, vector<vector<int>>& grid,int i, int j, vector<string>& ans, string& path){
    if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0){
        return;
    }

    if(i == n-1 && j == n-1){
      ans.push_back(path);
      return;  
    }
    
    grid[i][j] = 0;

    path.push_back('U') ;
    populateRatAns(n, grid, i-1, j , ans, path);
    path.pop_back();

    path.push_back('D') ;
    populateRatAns(n, grid, i+1, j , ans, path);
    path.pop_back();

    path.push_back('L') ;
    populateRatAns(n, grid, i, j-1 , ans, path);
    path.pop_back();

    path.push_back('R') ;
    populateRatAns(n, grid, i, j+1 , ans, path);
    path.pop_back();

    grid[i][j] = 1;
}

vector<string> ratInAMaze(int n, vector<vector<int>>& grid){ 
    vector<string> ans;
    string path = "";
    populateRatAns(n, grid, 0, 0, ans, path);
    return ans;
}

bool checkAdjacent(int i, int n, vector<int>& colors, vector<vector<int>>& graph){
    for(int j=0;j<n;j++){
        if(graph[i][j] == 1 && colors[i] == colors[j]){
            return false;
        }
    }
    return true;
}

bool populateMColors(int n, int i,int m,vector<vector<int>>& graph, vector<int>& colors){
    if(i == n)
        return true;
    for(int j=0; j < m; j++){
        colors[i] = j;
        if(checkAdjacent(i,n,colors,graph)){
            if(populateMColors(n, i+1, m, graph, colors)){
                return true;
            }
        }
        colors[i] = -1;
    }
    return false;
}

bool MColors(int n, int m, int e,vector<vector<int>>& edges){
    vector<vector<int>> graph(n, vector<int>(n,0));
    vector<int> colors(n, -1);
    for(auto row : edges){
        graph[row[0]][row[1]] = 1;
        graph[row[1]][row[0]] = 1;
    }
    return populateMColors(n, 0, m, graph, colors);
}

bool solveSudoku(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& squares){
    if(i == 9)
        return true;
    if(j == 9){
        return solveSudoku(board, i+1,0,rows, cols, squares);
    }
    if(board[i][j] != '.'){
        return solveSudoku(board, i,j+1,rows, cols, squares);
    }
    for(int k=1;k<=9;k++){
        if(rows[i][k-1] || cols[j][k-1] || squares[(i/3)*3+(j/3)][k-1])
            continue;
        board[i][j] = '0' + k;
        rows[i][k-1] = 1;
        cols[j][k-1] = 1;
        squares[(i/3)*3 + (j/3)][k-1] = 1;
        if(solveSudoku(board, i, j+1, rows, cols, squares)){
            return true;
        }
        board[i][j] = '.';
        rows[i][k-1] = 0;
        cols[j][k-1] = 0;
        squares[(i/3)*3 + (j/3)][k-1] = 0;
    }
    return false;
}
void SudokuSolver(vector<vector<char>>& board){
    vector<vector<bool>> rows(9, vector<bool>(9,false));
    vector<vector<bool>> cols(9, vector<bool>(9,false));
    vector<vector<bool>> squares(9, vector<bool>(9,false));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                rows[i][board[i][j] - '1'] = 1;
                cols[j][board[i][j] - '1'] = 1;
                squares[(i/3)*3 + (j/3)][board[i][j] - '1'] = 1;
            }
        }
    }
    solveSudoku(board,0,0,rows,cols,squares);
}

void populateAddOperationsAns(string& num, int target,int i,long long eval,long long lastop, string& ans, vector<string>& result){
    if(i == num.size()){
        if(target == eval){
            result.push_back(ans);
        }
        return;
    }
    string operand = "";
    for(int j=i;j<num.size();j++){
        operand += num[j];
        long long val = stoll(operand);
        int len = ans.length();
        ans += '+';
        ans += operand;
        populateAddOperationsAns(num, target, j+1, eval+val,val,ans, result);
        ans.resize(len);

        ans += '-';
        ans += operand;
        populateAddOperationsAns(num, target, j+1, eval-val,val*(-1),ans, result);
        ans.resize(len);

        ans += '*';
        ans += operand;
        populateAddOperationsAns(num, target, j+1, eval-lastop+(lastop*val),lastop*val,ans, result);
        ans.resize(len);
        if(num[i] == '0')
            break;
    }
}

vector<string> addOperations(string num, int target){
    vector<string> result;
    string ans = "";
    string operand = "";
    int i = 0;
    for(auto x: num){
        operand += x;
        i++;
        long long val = stoll(operand);
        int len = ans.length();
        ans += operand;
        populateAddOperationsAns(num, target, i,val, val, ans, result);
        ans.resize(len);
        if(num[0] == '0')
            break;
    }
    return result;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    vector<vector<string>> ans ;
    vector<string> vecstrans;
    vector<vector<int>> grid =  {{1, 0, 0, 0} , {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,0},{0,2}};
    vector<vector<char>> board2 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vecstrans = addOperations("123",6);
    for(auto x: vecstrans){
        cout<<x<<"\t";
    }
}