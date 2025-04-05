pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn max_num_edges_to_remove(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        fn union(root: &mut [usize], mut x: usize, mut y: usize) -> bool {
            x = find(root, x);
            y = find(root, y);

            if x == y {
                false
            } else {
                root[x] = y;

                true
            }
        }

        fn find(root: &mut [usize], i: usize) -> usize {
            if i != root[i] {
                root[i] = find(root, root[i]);
            }

            root[i]
        }

        let n = n as usize;
        let mut ans = 0;
        let mut root1 = (0..=n).collect::<Vec<_>>();
        let mut root2 = (0..=n).collect::<Vec<_>>();
        let mut alice_edges = 0;
        let mut bob_edges = 0;

        for e in &edges {
            if e[0] == 3 {
                if union(&mut root1, e[1] as usize, e[2] as usize) {
                    union(&mut root2, e[1] as usize, e[2] as usize);

                    alice_edges += 1;
                    bob_edges += 1;
                } else {
                    ans += 1;
                }
            }
        }

        for e in edges {
            match e.first() {
                Some(1) => {
                    if union(&mut root1, e[1] as usize, e[2] as usize) {
                        alice_edges += 1;
                    } else {
                        ans += 1;
                    }
                }
                Some(2) => {
                    if union(&mut root2, e[1] as usize, e[2] as usize) {
                        bob_edges += 1;
                    } else {
                        ans += 1;
                    }
                }
                _ => {}
            }
        }

        if alice_edges == bob_edges && alice_edges == n - 1 {
            ans
        } else {
            -1
        }
    }
}
