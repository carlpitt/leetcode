import random
import string


class Codec:
    base = "https://tinyurl.com/"
    chars = string.digits + string.ascii_letters

    def __init__(self) -> None:
        self.url2code = dict[str, str]()
        self.code2url = dict[str, str]()

    def encode(self, long_url: str) -> str:
        """Encodes a URL to a shortened URL."""
        if long_url not in self.url2code:
            code = "".join(random.choice(self.chars) for _ in range(6))
            while code in self.code2url:
                code = "".join(random.choice(self.chars) for _ in range(6))
            self.code2url[code] = long_url
            self.url2code[long_url] = code
        return self.base + self.url2code[long_url]

    def decode(self, short_url: str) -> str:
        """Decodes a shortened URL to its original URL."""
        return self.code2url[short_url[-6:]]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# code = codec.encode("https://leetcode.com/problems/design-tinyurl")
# print(code)
# print(codec.decode(code))
