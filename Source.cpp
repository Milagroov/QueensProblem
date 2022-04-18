#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void n_queens(int n);
void backtrack(vector<int>&, int current_row, int N);
bool construct(const vector<int>&, int row, int N, vector<int>&);
bool is_safe(const vector<int>&, int row, int col, int N);
bool is_solution(const vector<int>&, int N);
void print_solution(const vector<int>&, int N);

int main()
{
    int n;
    cin >> n;
    n_queens(n);
    return 0;
}

void n_queens(int n)
{
    vector<int> queens = vector<int>();
    backtrack(queens, 0, n);
}

void backtrack(vector<int>& queens, int current_row, int N)
{
    //check si on a rsolu le probleme
    if (is_solution(queens, N))
    {
        print_solution(queens, N);
    }
    else
    {
        //On fait un vector avec des emplacements de reines probable
        vector<int> reine_probable = vector<int>();
        if (construct(queens, current_row, N, reine_probable))
        {
            for (int i = 0; i < reine_probable.size(); ++i)
            {
                //On met la reine dans le vector provisoire
                queens.push_back(reine_probable[i]);
                backtrack(queens, current_row + 1, N);
                //Si on trouve pas de solution, on supprime la reine et on essaie la prochaine
                queens.pop_back();
            }
        }
    }
}

bool construct(const vector<int>& queens, int row, int N, vector<int>& reine_probable)
{
    for (int i = 0; i < N; ++i)
    {
        if (is_safe(queens, row, i, N))
        {
            reine_probable.push_back(i);
        }
    }
    return reine_probable.size() > 0;
}

bool is_safe(const vector<int>& queens, int row, int col, int N)
{
    for (int i = 0; i < queens.size(); ++i)
    {
        //cases ou il y a deja des reines
        if (i == row || queens[i] == col) return false;
        //cases ou les reines sont en danger en diagonales
        if (abs(i - row) == abs(queens[i] - col)) return false;
    }
    return true;
}

bool is_solution(const vector<int>& queens, int N)
{
    return queens.size() == N;
}

void print_solution(const vector<int>& queens, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (queens[i] == j) { cout << 'Q'; }
            else { cout << '_'; }
        }
        cout << endl;
    }
}