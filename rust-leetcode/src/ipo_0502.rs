use std::collections::BinaryHeap;

pub struct Solution;

impl Solution {
    pub fn find_maximized_capital(
        k: i32,
        mut w: i32,
        profits: Vec<i32>,
        capital: Vec<i32>,
    ) -> i32 {
        let mut projects = capital.into_iter().zip(profits).collect::<Vec<_>>();
        projects.sort_unstable();

        let mut maximize_capital = BinaryHeap::new();
        let mut i = 0;

        for _ in 0..k {
            while i < projects.len() && w >= projects[i].0 {
                maximize_capital.push(projects[i].1);
                i += 1;
            }

            if let Some(profit) = maximize_capital.pop() {
                w += profit;
            } else {
                break;
            }
        }

        w
    }
}
