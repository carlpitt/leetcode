class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False

        c_to_word: dict[str, str] = {}
        uniq_words = set[str]()

        for c, word in zip(pattern, words):
            if c in c_to_word:
                if c_to_word[c] != word:
                    return False
            else:
                if word in uniq_words:
                    return False
                c_to_word[c] = word
                uniq_words.add(word)
        return True
