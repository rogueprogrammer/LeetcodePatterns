int getHashForPattern(string s) {
	 int res = 0;
	 for (int i = 0; i < s.size(); ++i) {
		 res +=  ((tolower(s[i]) - 'a') + 1) * pow(3, i);
	 }
	 return res;
 }

 

 bool checkIfEqual(string a, string b) {
	 for (int i = 0; i < a.size(); ++i) {
		 if (a[i] != b[i]) {
			 return false;
		 }
	 }
	 return true;
 }

 /*
	Good video to understand algorithm: https://www.youtube.com/watch?v=H4VrKHVG5qI
	Rabin-Karp Algorithm for finding needle in haystack or pattern in string
	1. Calculate hash function for pattern/needle
	2. Calculate hash for first window in text.
	3. Repeat the following:
		i. if hash(pattern) == hash(text)
			-> then match characters one by one and check if they're the same
		ii. Subtract left most from hash value of text window
		iii. Shift text window to one char to right and add it's hash value.

 Rolling Hash Algorithm to compute hash:
 x = oldHash - val(oldchar)
 x = x/prime
 newhash = x + prime^m-1 * val(newChar)

 Where:
 val(char) = char - 'a' and m = length of pattern

 Has a run time of O(m+n), where m is length of haystack and n is length of needle. 
 */
 bool rabin_karp(string needle, string haystack) {

	 int needleHash = getHashForPattern(needle);
	 //compute hashVal for first window
	 string window = haystack.substr(0, needle.size());
	 int hashVal = getHashForPattern(window);

	 if (hashVal == needleHash) {
		 if (checkIfEqual(window, needle)) {
			 return true;
		 }
	 }

	 //now check hash values for the rest of the substrings of needle's size within haystack
	 int start = 1; 
	 while (1) {
		 int end = start + needle.size()-1;
		 if (start >= haystack.size() || end >= haystack.size()) {
			 break;
		 }
		 hashVal -= (haystack[start - 1] - 'a' + 1);
		 hashVal /= 3;
		 hashVal += (haystack[end] - 'a' + 1) * pow(3, needle.size() - 1);
		 if (hashVal == needleHash) {
			 string substring = haystack.substr(start, needle.size());
			 if (checkIfEqual(substring, needle)) {
				 return true;
			 }
		 }
		 ++start;
	 }

	 return false;
 }





void main() {
	cout << rabin_karp("abc", "xjlkjlkjeiuonacjks") << endl;
	cout << rabin_karp("abc", "xjlkjlkjeiuonabcjks") << endl;
}
