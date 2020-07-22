class Codec:
    
    def __init__(self):
        self.url_pair = {}
    
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        suffix = ''.join([random.choice(string.ascii_letters + string.digits) for i in range(6)])
        shortUrl = 'http://tinyurl.com/' + suffix
        self.url_pair[shortUrl] = longUrl
        return shortUrl
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.url_pair.get(shortUrl, 'Not an encodes TinyUrl')
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))