#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool canGo(int x, int y, vector<vector<int>> &matrix, int matrix_size, vector<vector<int>> visited) {
    // check if rat can be placed at x, y
    // checking for index out of range
    // is cell visited or not
    // and if cell is blocked
    if (((x >= 0 && x < matrix_size) && (y >= 0 && y < matrix_size)) && visited[y][x] == 0 && matrix[y][x] == 1) {
        return true;
    }

    return false;
}

void solve(vector<vector<int>> &matrix, int matrix_size, vector<string> &all_paths, string c_path, int x, int y, vector<vector<int>> visited) {
    // reached to destination
    if (y == matrix_size - 1 && x == matrix_size - 1) {
        all_paths.push_back(c_path);
        return;
    }

    // mark visited
    visited[y][x] = 1;

    // rr calls
    // first check if rat can go to next cell
    // up case
    if (canGo(x, y - 1, matrix, matrix_size, visited)) {
        c_path.push_back('U');
        solve(matrix, matrix_size, all_paths, c_path, x, y - 1, visited);
        c_path.pop_back();
    }

    // down case
    if (canGo(x, y + 1, matrix, matrix_size, visited)) {
        c_path.push_back('D');
        solve(matrix, matrix_size, all_paths, c_path, x, y + 1, visited);
        c_path.pop_back();
    }

    // left case
    if (canGo(x - 1, y, matrix, matrix_size, visited)) {
        c_path.push_back('L');
        solve(matrix, matrix_size, all_paths, c_path, x - 1, y, visited);
        c_path.pop_back();
    }

    // right case
    if (canGo(x + 1, y, matrix, matrix_size, visited)) {
        c_path.push_back('R');
        solve(matrix, matrix_size, all_paths, c_path, x + 1, y, visited);
        c_path.pop_back();
    }

    // mark visited
    visited[y][x] = 0;
}

void p1() {
    // Problem 1 : Rat in a Maze Problem - I - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

    // Statement : Consider a rat placed at (0, 0) in a square matrix of order N * N.
    // It has to reach the destination at (N - 1, N - 1).
    // Find all possible paths that the rat can take to reach from source to destination.
    // The directions in which the rat can move
    // are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
    // Value 0 at a cell in the matrix represents that it is blocked
    // and rat cannot move to it
    // while value 1 at a cell in the matrix represents
    // that rat can be travel through it.
    // Note: In a path, no cell can be visited more than one time.
    // If the source cell is 0, the rat cannot move to any other cell.

    // Logic :
    // create a vector of string all_paths to store all the answers
    // a string c_paths to store current path
    // and a 2d vector visited to track all the visited cells of given matrix
    // mark all the cells unvisited initially in visites vector
    // now create a function solve with below given signature
    // solve(vector<vector<int>> &matrix, int matrix_size, vector<string> &all_paths, string c_path, int x, int y, vector<vector<int>> visited) -> void
    // above
    // matrix is given matrix
    // matrix_size is size of given matrix
    // all_paths is vector of string to store all paths/answers
    // c_path is current path which rat has travelled till now
    // x and y are coordinates of current cell (row and column)
    // visited is vector to track record of visited cells
    // inside function add base case
    // check (y == matrix_size-1 && x == matrix_size-1)
    // if above condition is true than rat has reached to destination
    // simply store the path of rat c_path in all_paths
    // and than return
    // processing
    // mark current coordinates of visited vector as visited
    // visited[y][x] = 1
    // then check if rat can move upwards
    // if yes than move rat upwards
    // add U in c_path and call solve() function with below coordinates
    // (x, y-1)
    // then check if rat can move downwards
    // if yes than move rat downwards
    // add D in c_path and call solve() function with below coordinates
    // (x, y+1)
    // then check if rat can move leftwards
    // if yes than move rat leftwards
    // add L in c_path and call solve() function with below coordinates
    // (x-1, y)
    // and lastly check if rat can move rightwards
    // if yes than move rat rightwards
    // add R in c_path and call solve() function with below coordinates
    // (x+1, y)
    // before ending function mark previewsly visited marked cell as unvisited
    // to check if rat can move to any pertucular cell
    // create a function with below given signature
    // canGo(int x, int y, vector<vector<int>> &matrix, int matrix_size, vector<vector<int>> visited) -> bool
    // check for below conditions
    // if coordinates are out of bound/range
    // if cell is blocked at that coordinates
    // if cell is already visited
    // in these case return false as rat cant move through that cell
    // else return true
    // NOTE : before calling solve() function check if source cell (0, 0) is not 0
    // if source cell is cell than rat cant move from it and cannot be able to go to other cell
    // in this case length of all_paths will be 0

    // Code :
    // given matrix
    vector<vector<int>> matrix{
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    // size of matrix
    int n = 4;

    // current coordinates
    int src_x = 0;
    int src_y = 0;

    // all possible paths
    vector<string> all_paths;
    // current paths
    string c_path;

    // for visited cells
    vector<vector<int>> visited = matrix;

    // initialising visited cells with 0
    for (int y = 0; y < visited.size(); y++) {
        for (int x = 0; x < visited[y].size(); x++) {
            visited[y][x] = 0;
        }
    }

    // checking if source cell is not blocked
    if (matrix[src_y][src_x] != 0) {
        // calling to solve
        solve(matrix, n, all_paths, c_path, src_x, src_y, visited);
    }

    // sorting
    sort(all_paths.begin(), all_paths.end());

    // printing all paths
    for (int i = 0; i < all_paths.size(); i++) {
        cout << all_paths[i] << endl;
    }
}

int main() {
    // Lecture 39 : Recursion Day 10

    // p1();

    return 0;
}