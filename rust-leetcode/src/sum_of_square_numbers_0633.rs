pub struct Solution;

impl Solution {
    pub const fn judge_square_sum(mut c: i32) -> bool {
        if c == 0 {
            return true;
        }

        while c % 2 == 0 {
            c /= 2;
        }

        let mut exponent_count = 0;
        while c % 3 == 0 {
            exponent_count += 1;
            c /= 3;
        }
        if exponent_count % 2 != 0 {
            return false;
        }

        let mut divisor = 6;
        while divisor * divisor <= c {
            exponent_count = 0;

            while c % (divisor - 1) == 0 {
                exponent_count += 1;
                c /= divisor - 1;
            }

            if (divisor - 1) % 4 == 3 && exponent_count % 2 != 0 {
                return false;
            }

            exponent_count = 0;

            while c % (divisor + 1) == 0 {
                exponent_count += 1;
                c /= divisor + 1;
            }

            if (divisor + 1) % 4 == 3 && exponent_count % 2 != 0 {
                return false;
            }

            divisor += 6;
        }

        c % 4 != 3
    }
}
