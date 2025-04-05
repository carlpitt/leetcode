#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

using std::literals::operator""sv;
using std::literals::operator""s;

class Solution {
    public:
        // Encodes a URL to a shortened URL.
        [[nodiscard]] auto encode(const std::string &long_url) -> std::string {
            // if (url2code.find(long_url) == url2code.end()) {
            if (!url2code.contains(long_url)) {
                const auto code = random_string();
                code2url[code] = long_url;
                url2code[long_url] = code;
            }
            return std::string{base} + url2code[long_url];
        }

        // Decodes a shortened URL to its original URL.
        [[nodiscard]] auto decode(const std::string &short_url) -> std::string {
            return code2url[short_url.substr(short_url.size() - 6)];
        }

    private:
        static constexpr auto base = "https://tinyurl.com/"sv;
        static constexpr auto chars =
            "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"sv;

        std::unordered_map<std::string, std::string> url2code{};
        std::unordered_map<std::string, std::string> code2url{};

        [[nodiscard]] auto random_string() const -> std::string {
            auto code = std::string{};
            auto gen = std::mt19937{std::random_device{}()};
            auto dis =
                std::uniform_int_distribution<std::size_t>{0, chars.size() - 1};
            do {
                code.clear();
                for (auto i = 0; i < 6; ++i) {
                    code.push_back(chars[dis(gen)]);
                }
            } while (code2url.contains(code));
            // } while (code2url.find(code) != code2url.end());

            return code;
        }
};

// Your Solution object will be instantiated and called as such:
// auto main() -> int {
//     auto solution = Solution{};
//     constexpr auto url = "https://leetcode.com/problems/design-tinyurl"sv;
//     const auto code = solution.encode(std::string{url});
//     std::cout << code << '\n';
//     std::cout << solution.decode(code) << '\n';
// }
