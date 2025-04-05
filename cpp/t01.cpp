struct [[nodiscard]] S {
        [[nodiscard]]
        constexpr auto f() -> int {
            return 5;
        }
};
enum class E {
};

[[gnu::const]]
auto main() -> int {
    S{}.f();
}
