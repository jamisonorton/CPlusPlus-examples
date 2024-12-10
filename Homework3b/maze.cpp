#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include "Grid.h"

using namespace std;

typedef tuple<int, int, int> Coordinate;

// Recursive function to find the maze path
bool find_maze_path(Grid &grid, int row, int col, int level, vector<Coordinate> &solution) {
    // Check bounds
    if (row < 0 || row >= grid.height() || col < 0 || col >= grid.width() || level < 0 || level >= grid.depth())
        return false;

    // Check if cell is passable (1) and not already visited
    if (grid.at(row, col, level) != 1)
        return false;

    // Add the current cell to the solution path
    solution.emplace_back(row, col, level);

    // Mark the cell as visited
    grid.at(row, col, level) = -1;

    // Check if we reached the destination
    if (row == grid.height() - 1 && col == grid.width() - 1 && level == grid.depth() - 1)
        return true;

    // Recursive calls for all six directions
    if (find_maze_path(grid, row - 1, col, level, solution) ||  // Up
        find_maze_path(grid, row + 1, col, level, solution) ||  // Down
        find_maze_path(grid, row, col - 1, level, solution) ||  // Left
        find_maze_path(grid, row, col + 1, level, solution) ||  // Right
        find_maze_path(grid, row, col, level - 1, solution) ||  // Below
        find_maze_path(grid, row, col, level + 1, solution)) {  // Above
        return true;
    }

    // Backtrack if no path is found: remove the cell from the solution path
    solution.pop_back();
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: ./maze <maze_file> <solution_file>" << endl;
        return 1;
    }

    string maze_file = argv[1];
    string solution_file = argv[2];

    // Read the maze from the file
    Grid grid;
    ifstream input(maze_file);
    if (!input) {
        cerr << "Error: Could not open maze file " << maze_file << endl;
        return 1;
    }

    try {
        input >> grid;
    } catch (const exception &e) {
        cerr << "Error reading maze: " << e.what() << endl;
        return 1;
    }
    input.close();

    // Solve the maze
    vector<Coordinate> solution;
    if (find_maze_path(grid, 0, 0, 0, solution)) {
        ofstream output(solution_file);
        if (!output) {
            cerr << "Error: Could not open solution file " << solution_file << endl;
            return 1;
        }

        output << "SOLUTION" << endl;
        for (const auto &[row, col, level] : solution) {
            output << row << " " << col << " " << level << endl;
        }
        output.close();
    } else {
        ofstream output(solution_file);
        if (!output) {
            cerr << "Error: Could not open solution file " << solution_file << endl;
            return 1;
        }
        output << "NO SOLUTION" << endl;
        output.close();
    }

    return 0;
}