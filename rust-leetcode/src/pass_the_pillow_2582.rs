pub struct Solution;

impl Solution {
    pub const fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let extra_time = time % (n - 1);

        if time / (n - 1) % 2 == 0 {
            extra_time + 1
        } else {
            n - extra_time
        }
    }
}
