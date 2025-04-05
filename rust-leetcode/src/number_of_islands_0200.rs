pub struct Solution;

use std::collections::VecDeque;

impl Solution {
    /*pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut ans = 0;
        let m = grid.len();
        let n = grid[0].len();
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] != '0' {
                    ans += 1;
                    grid[i][j] = '0';
                    let mut todo = VecDeque::new();
                    todo.push_back((i, j));
                    while let Some((x, y)) = todo.pop_front() {
                        for (dx, dy) in &directions {
                            let nx = x + dx;
                            let ny = y + dy;
                            if nx < m && ny < n && grid[nx][ny] != '0' {
                                grid[nx][ny] = '0';
                                todo.push_back((nx, ny));
                            }
                        }
                    }
                }
            }
        }

        ans
    }*/

    pub fn num_islands_dfs(mut grid: Vec<Vec<char>>) -> i32 {
        let mut ans = 0;

        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == '1' {
                    Self::dfs(&mut grid, i, j);

                    ans += 1;
                }
            }
        }

        ans
    }

    fn dfs(grid: &mut [Vec<char>], i: usize, j: usize) {
        if i >= grid.len() || j >= grid[0].len() || grid[i][j] != '1' {
            return;
        }

        grid[i][j] = '0';

        Self::dfs(grid, i + 1, j);

        if i > 0 {
            Self::dfs(grid, i - 1, j);
        }

        Self::dfs(grid, i, j + 1);

        if j > 0 {
            Self::dfs(grid, i, j - 1);
        }
    }
}
