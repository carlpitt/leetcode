#include <vector>

using uint = unsigned;

class [[nodiscard]] CustomStack {
    public:
        explicit constexpr CustomStack(const uint max_size) noexcept :
            m_len{0} {
            this->m_stack.resize(max_size);
            this->m_inc.resize(max_size);
        }

        constexpr auto push(const uint x) noexcept -> void {
            if (this->m_len < this->m_stack.size()) {
                this->m_stack[this->m_len] = x;
                ++this->m_len;
            }
        }

        [[nodiscard]] constexpr auto pop() noexcept -> int {
            if (this->m_len == 0) {
                return -1;
            }

            const auto i = this->m_len - 1;
            const auto ans =
                static_cast<int>(this->m_stack[i] + this->m_inc[i]);

            if (this->m_len > 1) {
                this->m_inc[i - 1] += this->m_inc[i];
            }

            this->m_inc[i] = 0;
            --this->m_len;

            return ans;
        }

        constexpr auto increment(const uint k, const uint val) noexcept
            -> void {
            if (this->m_len > 0) {
                this->m_inc[std::min(this->m_len, k) - 1] += val;
            }
        }

    private:
        std::vector<uint> m_stack;
        std::vector<uint> m_inc;
        uint m_len;
};

// // Your CustomStack object will be instantiated and called as such:
// auto obj = CustomStack(maxSize);
// obj.push(x);
// const auto param_2 = obj.pop();
// obj.increment(k, val);
