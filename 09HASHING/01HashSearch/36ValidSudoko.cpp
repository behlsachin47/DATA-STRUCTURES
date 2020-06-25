class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //hashsets of rows form 1-9
        //hashsets of cols from 1-9
        //hashsets of subsuqres of 1-9 
        std::vector<std::unordered_set<char> > row_hashSets(9, std::unordered_set<char> {});
        std::vector<std::unordered_set<char> > col_hashSets(9, std::unordered_set<char> {});
        std::vector<std::unordered_set<char> > subsquare_hashSets (9, std::unordered_set<char> {});
        
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j++) {
                
                char element = board[i][j];
                if (element == '.')
                    continue;
                
                if (row_hashSets[i].count(element))
                    return 0;
                else
                    row_hashSets[i].insert(element);
                
                if (col_hashSets[j].count(element))
                    return 0;
                else 
                    col_hashSets[j].insert(element);
                
                //find the subsquare
                int squareNum = ((i/3)*3) + (j/3);
                //std::cout << i << " " << j << " " << squareNum << std::endl;
                if (subsquare_hashSets[squareNum].count(element))
                    return 0;
                else
                    subsquare_hashSets[squareNum].insert(element);
            }
        }
        return 1;
    }
};