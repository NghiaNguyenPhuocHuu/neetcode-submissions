class Solution:

    def encode(self, strs: List[str]) -> str:
        # Format: #<len>#<string>
        # e.g ["neet", "code"] -> "#4#neet#4#code"
        return "".join(f"#{len(s)}#{s}" for s in strs)
    def decode(self, s: str) -> List[str]:
        decoded = []
        i = 0
        n = len(s)

        while i < n:
            # 1. Skip the leading '# (s[i])
            # THe length digits start at i + 1
            j = i + 1

            # 2. Find the second '#' that ends the length number
            while s[j] != "#":
                j += 1
            
            # 3. Parse length from between the two '#' characters
            length = int(s[i + 1:j])

            # 4. Extract the payload setting
            start = j + 1
            end = start + length
            decoded.append(s[start:end])

            # 5. Jump directly to the start of the next block
            i = end

        return decoded