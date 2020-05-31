#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int index; //which is used for best move for AI

char board[9]= {'.','.','.','.','.','.','.','.','.'};

void draw_board() //display tic-tac-toe board
{
    cout<<endl;
    cout<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout<<"---------"<<endl;
    cout<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout<<"---------"<<endl;
    cout<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
}

int equals3(char a, char b, char c) {
  return a == b && b == c && a != '.';
}
char checkWinner() {
  char winner = 'p';//any symbol

  // horizontal
  for (int i = 0; i < 9; i+=3) {
    if (equals3(board[i], board[i+1], board[i+2])) {
      winner = board[i];
    }
  }

  // Vertical
  for (int i = 0; i < 3; i++) {
    if (equals3(board[i], board[i+3], board[i+6])) {
      winner = board[i];
    }
  }

  // Diagonal
  if (equals3(board[0], board[4], board[8])) {
    winner = board[0];
  }
  if (equals3(board[2], board[4], board[6])) {
    winner = board[2];
  }

  int openSpots = 0;//check whether board empty
    for (int j = 0; j < 9; j++) {
      if (board[j] == '.') {
        openSpots++;
      }
    }

  if (winner == 'p' && openSpots == 0) {
    return 't'; //which belong to tie
  }
  else
  {
    return winner;
  }
}

int minimaxAlgo(int depth, bool isMaximizer)
{
    char result = checkWinner();
    if (result != 'p')
    {
      if(result == 'X') //win of AI
        return 10;
      else if(result == 'O') //loss
        return -10;
      else if(result == 't') //tie
        return 0;
    }
    if(isMaximizer)
    {
        int bestScore = INT_MIN;
        int score;
        for(int i = 0; i < 9; i++)
        {
            if(board[i] == '.')
            {
                board[i] = 'X';
                score = minimaxAlgo(depth + 1, false);
                board[i] = '.';
                bestScore = max(score,bestScore);
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = INT_MAX;
        int score;
        for(int i = 0; i < 9; i++)
        {
            if(board[i] == '.')
            {
                board[i] = 'O';
                score = minimaxAlgo(depth + 1, true);
                board[i] = '.';
                bestScore = min(score,bestScore);
            }
        }
        return bestScore;
    }
}

void BestMove()
{
    int score;
    int bestScore = INT_MIN;
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == '.')
        {
            board[i] = 'X';
            score = minimaxAlgo(0,false);
            board[i] = '.';
            if(score > bestScore)
            {
                bestScore = score;
                index = i;
            }
        }
    }
    board[index] = 'X';
}

int main()
{
    int move;
    //draw_board();

    do{
        system("CLS");
        BestMove();
        //board[index] = 'X';
        draw_board();

        char result = checkWinner();
        if (result == 'X')
        {
          cout<<endl<<"CPU WON.....";
            break;
        }
        if(result == 't')
        {
            cout<<endl<<"Draw....";
            break;
        }

        again:
        cout<<"\nEnter Your Move:";
        cin>>move;

        if(board[move-1] == '.')
        {
            board[move-1] = 'O';
        }
        else
        {
            cout<<"\nInvalid Move....,Enter Correct Move Again\n";
            goto again;
        }

        system("CLS");
        draw_board();

         result = checkWinner();
        if (result == 'O')
        {
          cout<<endl<<"You WON.....";
            break;
        }
        if(result == 't')
        {
            cout<<endl<<"Draw....";
            break;
        }

    }while(1);
    return 0;
}










