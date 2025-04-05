use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::collections::HashSet;

pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn k_smallest_pairs(
        nums1: &[i32],
        nums2: &[i32],
        k: i32,
    ) -> Vec<Vec<i32>> {
        let k = k as usize;
        let mut ans = Vec::with_capacity(k);
        let mut q = BinaryHeap::new();

        q.push(Reverse((nums1[0] + nums2[0], 0, 0)));

        let mut visited = HashSet::new();

        visited.insert((0, 0));

        for _ in 0..k {
            if let Some(Reverse((_, i, j))) = q.pop() {
                ans.push(vec![nums1[i], nums2[j]]);

                if i + 1 < nums1.len() && visited.insert((i + 1, j)) {
                    q.push(Reverse((nums1[i + 1] + nums2[j], i + 1, j)));
                }

                if j + 1 < nums2.len() && visited.insert((i, j + 1)) {
                    q.push(Reverse((nums1[i] + nums2[j + 1], i, j + 1)));
                }
            }
        }

        ans
    }
}
