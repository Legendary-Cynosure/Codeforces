// https://codeforces.com/contest/1913/problem/B
// https://codeforces.com/profile/tourist
// GNU C++20 (64)

#include <bits/stdc++.h>
using namespace std;

// Debug macro to output information when running the code in LOCAL mode
#ifdef LOCAL
#include "algo/debug.h" // External debug header file, not provided here
#else
#define debug(...) 42 // Placeholder debug function
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt; // Read the number of test cases

  while (tt--) {
    string s;
    cin >> s; // Read the binary string for each test case

    // Length of the string
    int n = (int) s.size(); 

    // Counter for the number of '0's and '1's
    vector<int> cnt(2); 
    for (char c : s) {
      // Count the occurrences of '0's and '1's
      cnt[(int) (c - '0')] += 1; 
    }

    // Counter for the needed number of '0's and '1's
    vector<int> need(2); 

    // Initialize the answer to the length of the string
    int ans = n; 

    // Iterate through the string
    for (int i = 0; i < n; i++) {
      // Increment the count of the opposite bit at the current position
      need[(int) (s[i] - '0') ^ 1] += 1;

      // Check if the counts of '0's and '1's are enough for the needed count
      if (cnt[0] >= need[0] && cnt[1] >= need[1]) {
        // Update the answer if the conditions are met
        ans = n - 1 - i; 
      }
    }

    // Output the minimum total cost for this test case
    cout << ans << '\n'; 
  }

  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
 
// #ifdef LOCAL
// #include "algo/debug.h"
// #else
// #define debug(...) 42
// #endif
 
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
//   int tt;
//   cin >> tt;
//   while (tt--) {
//     string s;
//     cin >> s;
//     int n = (int) s.size();
//     vector<int> cnt(2);
//     for (char c : s) {
//       cnt[(int) (c - '0')] += 1;
//     }
//     vector<int> need(2);
//     int ans = n;
//     for (int i = 0; i < n; i++) {
//       need[(int) (s[i] - '0') ^ 1] += 1;
//       if (cnt[0] >= need[0] && cnt[1] >= need[1]) {
//         ans = n - 1 - i;
//       }
//     }
//     cout << ans << '\n';
//   }
//   return 0;
// }