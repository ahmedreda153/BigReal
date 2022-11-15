#include <iostream>
#include <iomanip>
using namespace std;

class Board
{
protected:
   static char board[3][3];
   static char board2[3][3];
   int n_moves = 0;

public:
   bool update_board(int x, int y, char symbol);
   bool is_winner();
   bool is_draw();
   void display_board();
};
char Board::board[3][3] = {{'0','0','0'},{'0','0','0'},{'0','0','0'}};
char Board::board2[3][3]={{'0','0','0'},{'0','0','0'},{'0','0','0'}};
class Player
{
protected:
   char symbol;

public:
   Player(char symbol)
   {
      this->symbol = symbol;
   }
   void get_move(int &x, int &y);
   char get_symbol();
};

class computerTurn : public Board
{
public:
   computerTurn(char mine, char another);
};

class GameManager
{
public:
   void run();
};

bool Board::update_board(int x, int y, char mark)
{
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == '0'))
   {
      board[x][y] = toupper(mark);
      board2[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

void Board::display_board()
{
   for (int i : {0, 1, 2})
   {
      cout << "\n| ";
      for (int j : {0, 1, 2})
      {
         // cout << "(" << i << "," << j << ")";
         cout << setw(2) << board[i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}

bool Board::is_winner()
{
   char row_win[3], col_win[3], diag_win[2];
   for (int i : {0, 1, 2})
   {
      row_win[i] = board[i][0] & board[i][1] & board[i][2];
      col_win[i] = board[0][i] & board[1][i] & board[2][i];
   }
   diag_win[0] = board[0][0] & board[1][1] & board[2][2];
   diag_win[1] = board[2][0] & board[1][1] & board[0][2];

   for (int i : {0, 1, 2})
   {
      if ((row_win[i] && (row_win[i] == board[i][0])&&board[i][0]!='0') ||
          (col_win[i] && (col_win[i] == board[0][i])&&board[0][i]!='0'))
      {
         return true;
      }
   }
   if ((diag_win[0] && diag_win[0] == board[1][1])&&board[1][1]!='0' ||
       (diag_win[1] && diag_win[1] == board[1][1])&&board[1][1]!='0')
   {
      return true;
   }
   return false;
}

bool Board::is_draw()
{
   return (n_moves >= 5 && !is_winner());
}

void Player::get_move(int &x, int &y)
{
   cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
   cin >> x >> y;
}
char Player::get_symbol()
{
   return symbol;
}

computerTurn::computerTurn(char mine = 'x', char another = 'o')
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (board2[i][j] == '0')
         {
            // board[i][j] = mine;
            board[i][j] = mine;
            board2[i][j] = mine;
            if (is_winner())
            {
               return;
            }
            else
            {
               board[i][j] = another;
               board2[i][j] = another;
               if (is_winner())
               {
                 board[i][j] = mine;
                 board2[i][j] = mine;
                  return;
               }
               else
                  board[i][j] = '0';
                  board2[i][j] = '0';
            }
         }
      }
   }
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 3; j++)
         {
            if (board2[i][j] == '0')
            {
               board[i][j] = mine;
               board2[i][j] = mine;
               return;
            }
         }
      }
}

void GameManager::run()
{
   Board x_o;
   int x, y;
   Player players('o');
   x_o.display_board();
   while (true)
   {
      players.get_move(x, y);
      while (!x_o.update_board(x, y, players.get_symbol()))
      {
         players.get_move(x, y);
      }
      if (x_o.is_winner())
      {
         cout << "human wins\n";
         return;
      }
      computerTurn computerTurns('x', 'o');
      x_o.display_board();
      if (x_o.is_winner())
      {
         cout << "computer wins\n";
         return;
      }
      if (x_o.is_draw())
      {
         cout << "Draw!\n";
         return;
      }
   
   }

}

int main()
{
   GameManager x_o_game;
   x_o_game.run();
   system("pause");
}