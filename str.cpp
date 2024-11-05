/*#include <iostream>
#include <string>

using namespace std;

// Function to perform Naive String Matching
void naiveStringMatching(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Pattern not found in the text." << endl;
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Naive String Matching:" << endl;
    naiveStringMatching(text, pattern);

    return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

const int d = 256; // Number of characters in the input alphabet

// Function to perform Rabin-Karp String Matching
void rabinKarp(const string& text, const string& pattern, int q) {
    int M = pattern.length();
    int N = text.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern.
        // If the hash values match then check for characters one by one
        if (p == t) {
            // Check for characters one by one
            int j;
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == M) {
                cout << "Pattern found at index: " << i << endl;
            }
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Rabin-Karp Algorithm:" << endl;
    int q = 101; // A prime number
    rabinKarp(text, pattern, q);

    return 0;
}

/*g++ -o naive_string_matching naive_string_matching.cpp
./naive_string_matching

g++ -o rabin_karp rabin_karp.cpp
./rabin_karp

*/

/*
Sure! Let’s break down how both the Naive String Matching algorithm and the Rabin-Karp algorithm work, including their methodologies, advantages, and potential drawbacks.

### 1. Naive String Matching Algorithm

#### How It Works
The Naive String Matching algorithm checks for the occurrence of a pattern in a text by examining every possible starting position in the text. The algorithm follows these steps:

1. **Iterate Over Text**: For each position in the text from `0` to `n - m` (where `n` is the length of the text and `m` is the length of the pattern):
   - Start a nested iteration over the characters of the pattern.

2. **Character Comparison**: For each character in the pattern, compare it with the corresponding character in the text starting from the current position. 
   - If all characters match, record the position as a match.
   - If any character does not match, break out of the inner loop and move to the next starting position in the text.

3. **Output Matches**: After checking all possible positions, print the indices where matches were found.

#### Example
For a text `"ABABDABACDABABCABAB"` and pattern `"ABABCABAB"`:
- The algorithm will start comparing the pattern at every index of the text until it finds a match at index 10.

#### Time Complexity
- **Worst Case**: \(O(n \times m)\), where:
  - \(n\) is the length of the text.
  - \(m\) is the length of the pattern.
  
The worst case occurs when the text and pattern have many characters in common, leading to maximum comparisons.

#### Advantages and Drawbacks
- **Advantages**: 
  - Simple to implement.
  - Easy to understand.
  
- **Drawbacks**: 
  - Inefficient for large texts or patterns due to its high time complexity.

---

### 2. Rabin-Karp Algorithm

#### How It Works
The Rabin-Karp algorithm improves efficiency by using hashing to find the pattern. Here's how it operates:

1. **Hash Function**: Calculate the hash value of the pattern and the hash value of the initial window of the text (substring of the same length as the pattern).

2. **Compare Hashes**: 
   - If the hash values match, it’s a potential match. The algorithm then checks the actual characters in that substring to confirm a match.
   - If the hash values do not match, the algorithm moves to the next substring in the text.

3. **Sliding Window**:
   - For each new position in the text, the hash value of the current window is calculated using a rolling hash formula, which efficiently updates the hash by removing the leading character and adding the trailing character.
   - This helps to avoid recalculating the hash for the entire substring, significantly speeding up the process.

4. **Output Matches**: Just like the naive approach, if matches are found after checking the actual characters, they are recorded and printed.

#### Example
For the same text `"ABABDABACDABABCABAB"` and pattern `"ABABCABAB"`:
- The algorithm computes hash values for the pattern and substrings of the text.
- It checks the hash value first, and if they match, it confirms the match by comparing the actual characters.

#### Time Complexity
- **Average Case**: \(O(n + m)\)
- **Worst Case**: \(O(n \times m)\) in the presence of many hash collisions.

The average case is better than the naive approach because it uses hash comparisons first before checking characters.

#### Advantages and Drawbacks
- **Advantages**:
  - More efficient than the naive approach, especially for large texts and multiple patterns.
  - The use of hashing allows for quick comparisons.

- **Drawbacks**:
  - More complex to implement.
  - Hash collisions can lead to additional character comparisons, affecting performance.

---

### Summary

- The **Naive String Matching algorithm** is straightforward but inefficient for larger inputs due to its quadratic time complexity.
- The **Rabin-Karp algorithm** uses hashing to potentially improve efficiency, particularly beneficial when searching for multiple patterns in the same text. However, it has the added complexity of dealing with hash calculations and potential collisions.

Both algorithms have their use cases depending on the requirements for simplicity versus performance. For small-scale or educational examples, the Naive approach suffices, while Rabin-Karp is more suitable for performance-critical applications.*/