pub struct Solution;

impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }

        let mut a = 0;
        let mut b = 1;

        for _ in 1..n {
            let s = a + b;
            a = std::mem::replace(&mut b, s);
        }

        b
    }
}
