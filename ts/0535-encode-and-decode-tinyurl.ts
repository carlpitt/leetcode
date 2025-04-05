const base = "https://tinyurl.com/";
const chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const url2code: { [key: string]: string } = {};
const code2url: { [key: string]: string } = {};

function randomString(): string {
    let code = "";
    for (let i = 0; i < 6; ++i) {
        code += chars[Math.floor(Math.random() * chars.length)];
    }
    return code;
}

/**
 * Encodes a URL to a shortened URL.
 */
function encode(longUrl: string): string {
    if (!url2code[longUrl]) {
        let code = randomString();
        while (code2url[code] !== undefined) {
            code = randomString();
        }
        code2url[code] = longUrl;
        url2code[longUrl] = code;
    }
    return base + url2code[longUrl];
}

/**
 * Decodes a shortened URL to its original URL.
 */
function decode(shortUrl: string): string {
    return code2url[shortUrl.slice(-6)];
}

// Your functions will be called as such:
const code = encode("https://leetcode.com/problems/design-tinyurl");
console.log(code);
console.log(decode(code));
