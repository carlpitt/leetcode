pub struct Solution;

impl Solution {
    #[allow(clippy::needless_pass_by_value)]
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        if edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] {
            edges[0][0]
        } else {
            edges[0][1]
        }
    }
}
