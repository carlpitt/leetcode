use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let n = strs.len();
        let mut map = HashMap::with_capacity(n);

        for s in strs {
            let mut counts = [0; 26];

            for c in s.bytes() {
                counts[(c - b'a') as usize] += 1;
            }

            map.entry(counts)
                .or_insert_with(|| Vec::with_capacity(n / 2))
                .push(s);
        }

        map.into_values().collect()
    }
}
