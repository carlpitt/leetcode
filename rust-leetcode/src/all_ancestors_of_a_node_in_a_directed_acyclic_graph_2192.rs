pub struct Solution;

impl Solution {
    #[allow(clippy::cast_possible_truncation)]
    #[allow(clippy::cast_possible_wrap)]
    #[allow(clippy::cast_sign_loss)]
    pub fn get_ancestors(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        fn dfs(
            x: i32,
            curr: usize,
            ans: &mut Vec<Vec<i32>>,
            graph: &Vec<Vec<usize>>,
        ) {
            for &ch in &graph[curr] {
                if ans[ch].is_empty() || ans[ch][ans[ch].len() - 1] != x {
                    ans[ch].push(x);
                    dfs(x, ch, ans, graph);
                }
            }
        }

        let n = n as usize;
        let mut graph = vec![Vec::new(); n];

        for e in edges {
            graph[e[0] as usize].push(e[1] as usize);
        }

        let mut ans = vec![Vec::new(); n];

        for i in 0..n {
            dfs(i as i32, i, &mut ans, &graph);
        }

        ans
    }
}
