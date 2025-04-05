pub struct Solution;

impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut ans = names.into_iter().zip(heights).collect::<Vec<_>>();

        ans.sort_unstable_by(|a, b| b.1.cmp(&a.1));

        ans.into_iter().map(|(name, _)| name).collect()
    }
}
