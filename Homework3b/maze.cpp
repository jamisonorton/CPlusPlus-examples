#include <iostream>
#include <string>
#include <stack>
#include <tuple>
#include <vector>
#include "Grid.h"

class MazeSolver {
public:
    MazeSolver(const Grid& grid) : grid_(grid) {}

    bool solve() {
        std::stack<std::tuple<int, int, int>> stack;
        std::vector<std::vector<std::vector<bool>>> visited(
            grid_.depth(), std::vector<std::vector<bool>>(
                              grid_.height(), std::vector<bool>(grid_.width(), false)));

        // Start point (0, 0, 0)
        stack.push({0, 0, 0});
        visited[0][0][0] = true;

        // Directions to move in the 3D grid: up, down, left, right, forward, backward
        const std::vector<std::tuple<int, int, int>> directions = {
            {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

        while (!stack.empty()) {
            auto [x, y, z] = stack.top();
            stack.pop();

            // Check if we reached the end point (height-1, width-1, depth-1)
            if (x == grid_.height() - 1 && y == grid_.width() - 1 && z == grid_.depth() - 1) {
                std::cout << "Maze solved! Reached destination (" << x << ", " << y << ", " << z << ")." << std::endl;
                return true;
            }

            // Explore all possible directions
            for (const auto& [dx, dy, dz] : directions) {
                int new_x = x + dx;
                int new_y = y + dy;
                int new_z = z + dz;

                // Check if the new position is within bounds and is an open space (0)
                if (is_valid(new_x, new_y, new_z, visited)) {
                    stack.push({new_x, new_y, new_z});
                    visited[new_z][new_x][new_y] = true; // Mark this position as visited
                }
            }
        }

        std::cout << "No path found!" << std::endl;
        return false;
    }

private:
    const Grid& grid_;

    bool is_valid(int x, int y, int z, const std::vector<std::vector<std::vector<bool>>>& visited) {
        return x >= 0 && x < grid_.height() && y >= 0 && y < grid_.width() && z >= 0 && z < grid_.depth() &&
               grid_.at(x, y, z) == 0 && !visited[z][x][y];
    }
};

int main(int argc, char* argv[]) {
    try {
        // Reading the maze from input
        Grid maze;
        std::cin >> maze;

        // Creating a maze solver object
        MazeSolver solver(maze);

        // Solving the maze
        solver.solve();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}