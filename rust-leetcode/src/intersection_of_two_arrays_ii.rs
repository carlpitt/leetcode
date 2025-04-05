// use std::cmp::Ordering;

pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn intersect(nums1: &[i32], nums2: &[i32]) -> Vec<i32> {
        let mut ans = Vec::with_capacity(nums1.len().min(nums2.len()));
        let mut counts = [0u16; 1001];

        for &n in nums1 {
            counts[n as usize] += 1;
        }

        for &n in nums2 {
            let count = &mut counts[n as usize];

            if *count > 0 {
                ans.push(n);
                *count -= 1;
            }
        }

        ans

        // nums1.sort_unstable();
        // nums2.sort_unstable();

        // let mut ans = Vec::with_capacity(nums1.len().min(nums2.len()));
        // let mut i = 0;
        // let mut j = 0;

        // while i < nums1.len() && j < nums2.len() {
        //     match nums1[i].cmp(&nums2[j]) {
        //         Ordering::Less => {
        //             i += 1;
        //         }
        //         Ordering::Greater => {
        //             j += 1;
        //         }
        //         Ordering::Equal => {
        //             ans.push(nums1[i]);

        //             i += 1;
        //             j += 1;
        //         }
        //     }
        // }

        // ans
    }
}
