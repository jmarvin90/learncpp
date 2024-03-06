#include <iostream>
#include <cmath>
#include <algorithm>

void show_grid(const std::vector<std::vector<int>>& grid) {
    /* Show the grid on the screen. */
    for (int row=0; row<grid.size(); row++) {
        for (int col: grid[row]) {
            std::cout << col << " ";
        }

        std::cout << "\n";
    }
    std::cout << "\n";
}

std::vector<int> next_blank(const std::vector<std::vector<int>>& grid) {
    /* Find the x, y for the 'next' 0 val in the grid (from top left). */
    for (int row=0; row<grid.size(); row++) {
        for (int col=0; col<grid[row].size(); col++) {
            if (grid[row][col] == 0) {
                return std::vector<int> {col, row};
            }
        }
    }

    return std::vector<int> {-1, -1};
}

std::vector<int> get_column(
    const std::vector<std::vector<int>>& grid,
    int column_number
) {
    /* Return the values for the column at the specified position. */
    std::vector<int> output;

    for (int row=0; row<grid.size(); row++) {
        output.push_back(grid[row][column_number]);
    }

    return output;
}

int get_zone_width(const std::vector<std::vector<int>>& grid) {
    /* Calculate the width of the zones in the grid. */
    return (int)std::sqrt(grid.size());
}

int get_zone_start(
    const std::vector<std::vector<int>>& grid,
    int coord
) {
    /* Find the value representing the zone start for a given coordinate. */
    int zone_width {get_zone_width(grid)};
    return (coord / zone_width) * zone_width;
}

std::vector<int> get_zone(
    const std::vector<std::vector<int>>& grid,
    int x, int y
) {
    /* Return values from the zone at the given coordinates. */
    int zone_width {get_zone_width(grid)};
    int x_start {get_zone_start(grid, x)};
    int y_start {get_zone_start(grid, y)};
    std::vector<int> output;

    for (int row=y_start; row<y_start+zone_width; row++) {
        for (int col=x_start; col<x_start+zone_width; col++) {
            output.push_back(grid[row][col]);
        }
    }

    return output;
}

bool number_in_vector(const std::vector<int>& vec, int val) {
    /* Check whether a specified number appears in the input vector. */
    return std::find(vec.begin(), vec.end(), val) != vec.end();
}

bool proposed_number_is_valid(
    const std::vector<std::vector<int>>& grid,
    int x, int y, int number
) {
    /* Validate whether a specified number is valid at the given coordinates. */
    std::vector<int> col {get_column(grid, x)};
    std::vector<int> zone {get_zone(grid, x, y)};
    bool in_row {number_in_vector(grid[y], number)};
    bool in_col {number_in_vector(get_column(grid, x), number)};
    bool in_zone {number_in_vector(get_zone(grid, x, y), number)};
    return !in_row && !in_col && !in_zone;
}

bool grid_is_solved(const std::vector<std::vector<int>>& grid) {
    /* Check whether the grid has been solved. */
    return next_blank(grid) == std::vector<int>{-1, -1};
}

bool solve(
    const std::vector<std::vector<int>> grid, 
    std::vector<std::vector<int>>& origin
) {
    /* Solve the grid using a backtracking algorithm. */
    if (grid_is_solved(grid)) {
        origin = grid;
        return true;
    }

    for (int num=1; num<=grid.size(); num++) {
        std::vector<int> blank {next_blank(grid)};
        if (proposed_number_is_valid(grid, blank[0], blank[1], num)) {
            std::vector<std::vector<int>> new_grid {grid};
            new_grid[blank[1]][blank[0]] = num;
            if (solve(new_grid, origin)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Specify the input sudoku board
    std::vector<int> row_0 {2, 3, 0, 1, 9, 6, 0, 5, 4}; 
    std::vector<int> row_1 {0, 5, 7, 0, 0, 0, 0, 2, 9};
    std::vector<int> row_2 {0, 1, 0, 5, 7, 2, 0, 0, 0};
    std::vector<int> row_3 {0, 0, 9, 0, 0, 4, 0, 0, 0};
    std::vector<int> row_4 {1, 0, 5, 8, 0, 0, 0, 0, 0};
    std::vector<int> row_5 {3, 0, 6, 0, 0, 9, 0, 0, 8};
    std::vector<int> row_6 {0, 0, 0, 0, 0, 0, 5, 0, 0};
    std::vector<int> row_7 {0, 6, 0, 0, 0, 8, 2, 0, 0}; 
    std::vector<int> row_8 {7, 8, 2, 3, 0, 0, 0, 4, 0};
    std::vector<std::vector<int>> grid {
        row_0, row_1, row_2, row_3, row_4, row_5, row_6, row_7, row_8
    };

    show_grid(grid);
    solve(grid, grid);              // Solve the grid   
    show_grid(grid);                // Show the solved grid on the screen

    return 0;
}