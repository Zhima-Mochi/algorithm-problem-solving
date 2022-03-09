#
# @lc app=leetcode id=535 lang=python3
#
# [535] Encode and Decode TinyURL
#

# @lc code=start
import random


class Codec:
    code2long = {}
    long2code = {}
    select = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    def getCode(self):
        res = []
        width = len(self.select)
        for i in range(6):
            res.append(self.select[random.randint(0, width-1)])
        return ''.join(res)

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        if longUrl in self.long2code:
            return "https://tinyurl.com/" + self.long2code[longUrl]
        else:
            code = self.getCode()
            while(code in self.code2long):
                code = self.getCode()
            self.long2code[longUrl] = code
            self.code2long[code] = longUrl
            return "https://tinyurl.com/" + code

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.code2long[shortUrl[shortUrl.rindex('/')+1:]]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
# @lc code=end
