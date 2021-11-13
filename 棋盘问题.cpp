#include <iostream>
using namespace std;

#define ori_size 8
int tile = 0;

int board[ori_size][ori_size] = {0};

/**
 * all_row: 当前要研究的棋盘的左上角的小方格在原始棋盘中的位置的行数
 * all_cloumn: 当前要研究的棋盘的左上角的小方格在原始棋盘中的位置的列数
 * one_row: 当前要研究的棋盘上特殊方格在当前棋盘中的位置的行数
 * one_cloumn: 当前要研究的棋盘上特殊方格在当前棋盘中的位置的列数
 * size: 当前要研究棋盘的大小（边长）
 */
void chessBoard(int all_row, int all_cloumn, int one_row, int one_cloumn, int size)
{
    if(size == 1) return;
    int t = ++tile;
    int s = size/2;
    if(one_row <= s && one_cloumn <= s)
    {
        chessBoard(all_row,all_cloumn, one_row, one_cloumn, s);
    }
    else
    {
        board[all_row+s-1-1][all_cloumn+s-1-1] = t;
        chessBoard(all_row, all_cloumn, s, s, s);
    }

    if(one_row > s && one_cloumn <= s)
    {
        chessBoard(all_row+s, all_cloumn,one_row-s, one_cloumn, s);
    }
    else
    {
        board[all_row+s-1][all_cloumn+s-1-1] = t;
        chessBoard(all_row+s, all_cloumn, 1, s, s);
    }

    if(one_row <= s && one_cloumn > s)
    {
        chessBoard(all_row, all_cloumn+s, one_row, one_cloumn-s, s);
    }
    else
    {
        board[all_row+s-1-1][all_cloumn+s-1] = t;
        chessBoard(all_row, all_cloumn+s, s, 1, s);
    }

    if(one_row>s &&one_cloumn>s)
    {
        chessBoard(all_row+s, all_cloumn+s, one_row-s, one_cloumn-s, s);
    }
    else
    {
        board[all_row+s-1][all_cloumn+s-1] = t;
        chessBoard(all_row+s, all_cloumn+s, 1, 1, s);
    }
}

int main()
{
    int row, cloumn;
    cin>>row;
    cin>>cloumn;
    chessBoard(1, 1, row, cloumn, ori_size);
    for(int i = 0; i < ori_size; i++)
    {
        for(int j = 0; j < ori_size; j++){
            cout<<board[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}