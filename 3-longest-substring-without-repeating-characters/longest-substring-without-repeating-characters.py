class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st = set()
        i = 0
        ans = 0

        for j in range(len(s)):
            while s[j] in st:
                st.remove(s[i])
                i += 1

            st.add(s[j])
            ans = max(ans, j - i + 1)

        return ans