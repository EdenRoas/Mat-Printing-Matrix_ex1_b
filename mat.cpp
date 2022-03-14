#include <iostream>
#include <vector>
#include "mat.hpp"
#include <stdexcept>
/**
* AUTHOR: Eden Roas
**/

using namespace std;

namespace ariel 
{
    string mat(int col, int row, char s1, char s2){
        const int inf = 33;
        const int sup = 126;
        if(col % 2 == 0 || row % 2 == 0){
            throw invalid_argument("The matrix sizes cannot be even"); 
        }
        if(col<0 || row<0){
            throw invalid_argument("The matrix sizes cannot be negetive");
        } 
        if ((s1 < inf || s1 > sup) || (s2 < inf || s2 > sup))
            {
            throw invalid_argument("Invalid character");
            }
        /** 
         * round is the number of layers we have in any round
         * temp this 
         * */
        vector< vector<char> > mat(row, vector<char> (col));
        int round = (min(row,col)/2);
        char temp_s = s1;
        if (s1 == s2){
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    mat[i][j] = s1;
                }
                
            }
            
        }
        else {
            for (int i = 0; i <= round; i++)
            {
                for (int l_c = i; l_c < col - i; l_c++)
                {   
                mat[i][l_c] = temp_s;
                mat[row - i - 1][l_c] = temp_s;
                }
                for (int l_r = i; l_r < row - i; l_r++)
                {
                mat[l_r][i] = temp_s;
                mat[l_r][col - i - 1] = temp_s;
                }
                if(temp_s == s1){ 
                    temp_s = s2;
                }
                else {
                    temp_s = s1;
                }
            }
        }
        string print_mat = " ";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                print_mat += mat[i][j];
            }
            print_mat+= '\n';
        }
        
        return print_mat;

        
    }
    // int main(){
    //     int row,col;
    //     char s1,s2;
    //     cin >> col;
    //     cin >> row;
    //     cin >> s1;
    //     cin >> s2;
    //     cout << ariel:: mat(col,row,s1,s2);
    //     return 0 ;
    // }
}
