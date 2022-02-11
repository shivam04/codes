class Solution {
public:
    map<string, string> url_pair;
    string ascii = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string suffix = "";
        int n = ascii.size();
        for(int i=0;i<6;i++) {
            int j = rand()%n;
            char c = ascii[j];
            suffix += c;
        }
        string shortUrl = "http://tinyurl.com/" + suffix;
        url_pair[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url_pair[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));