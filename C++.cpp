/*
//Q1.
// There is a large pile of socks that must be paired by color.
// Given an array of integers representing the color of each sock, 
// determine how many pairs of socks with matching colors there are. 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// function using unordered_map
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> map;
    int pairs = 0;
    int i = 0;
    while (i < n) {
        if (map.find(ar[i]) == map.end()) {  // If the sock type is not in the map
            map.insert({ar[i], 1});
        } else {
            map[ar[i]]++;
            if (map[ar[i]] % 2 == 0) pairs++; // If the count becomes even, we have a pair
        }
        i++;
    }
    return pairs;
}
// function using vector
int sockMerchant(int n , vector<int> ar){
    int pairs = 0;
    vector <int> count(101, 0); // Assuming sock types are in the range 0-100
    for(int i = 0; i < n; i++){
        count[ar[i]] ++;
        if(count[ar[i]] % 2 == 0){
            pairs++;
        }
    }
    return pairs;
}
int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    cout << "pairs = " << sockMerchant(n, ar) << endl;
    return 0;
}
*/

/*
//Q2.
// Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
// Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
// - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
#include <iostream>
#include <string>
using namespace std;
string time_change(string s){
    string hour = s.substr(0, 2);
    string minutes = s.substr(3, 2);
    string seconds = s.substr(6, 2);
    string period = s.substr(8, 2);
    int hr = stoi(hour);
    if(period == "AM"){
        if(hr == 12){
            hour = "00";
        }
    } else { // PM case
        if(hr != 12){
            hr += 12;
            hour = to_string(hr);
        }
    }
    return hour + ":" + minutes + ":" + seconds;    
}
int main(){
    string s = "12:00:00AM";
    cout << "12 hour time = " << s << endl;
    string ans = time_change(s);
    cout << "24 hour time = " << ans << endl;
    return 0;
}
*/

/*
//Q3.
// Nina received an odd New Year's present from a student: a set of  unbreakable sticks.
// Each stick has a length, l ,and the length of the ith stick is (l)i-1.
// Deciding to turn the gift into a lesson, Nina asks her students the following:
// How many ways can you build a square using exactly 6 of these unbreakable sticks?
// Note: Two ways are distinct if they use at least one different stick.
// As there are  choices of sticks, we must determine which combinations of sticks can build a square.
#include <iostream>
#include <vector>
using namespace std;
int possible_ways(int n , vector<int> &sticks){
    int ways = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    if(sticks[i] == sticks[j] && sticks[j] == sticks[k] && sticks[k] == sticks[l]){
                        ways++;
                    }
                }
            }
        }
    }
    return ways;
}
int main(){
    int n; cin >> n;
    vector<int> sticks(n);
    for(int i = 0; i < n; i++){
        cin >> sticks[i];
    }
    int ans = possible_ways(n , sticks);
    cout << "Number of ways to form a square = " << ans << endl;
    return 0;
}
*/

/*
//Q4.
//John Watson knows of an operation called a right circular rotation on an array of integers.
//One rotation operation moves the last array element to the first position and shifts all remaining elements right one.
//To test Sherlock's abilities, Watson provides Sherlock with an array of integers.
//Sherlock is to perform the rotation operation a number of times then determine the value of the element at a given position.
//For each array, perform a number of right circular rotations and return the values of the elements at the given indices.
#include <iostream>
#include <vector>
using namespace std;
vector<int> circularArrayRotation(vector<int> arr, int k, vector<int> queries) {
    int n = arr.size();
    k = k % n; // In case k is greater than n
    vector<int> rotated(n);
    // Rotate the array
    for(int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }
    // Answer the queries
    vector<int> result;
    for(int q : queries) {
        result.push_back(rotated[q]);
    }
    return result;
}
int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    vector<int> result = circularArrayRotation(arr, k, queries);
    for(int val : result) {
        cout << val << endl;
    }
    return 0;
}
*/

/*
// Q5.
// You are given an integer, . Write a program to determine if  is an element of the Fibonacci sequence.
// The first few elements of the Fibonacci sequence are . A Fibonacci sequence is one where every element
// is a sum of the previous two elements in the sequence. The first two elements are 0 and 1.
#include <iostream>
#include <cmath>
using namespace std;
string isFibonacci(int n){
    // A number is Fibonacci if one of (5*n*n + 4) or (5*n*n - 4) is a perfect square
    int test1 = 5*n*n + 4;
    int test2 = 5*n*n - 4;
    int sqrt1 = sqrt(test1);
    int sqrt2 = sqrt(test2);
    if(sqrt1 * sqrt1 == test1 || sqrt2 * sqrt2 == test2){
        return "IsFibo";
    } else {
        return "IsNotFibo";
    }
}
int main() {
    int t; cin >> t;
    while(t--){
        long n;
        cin >> n;
        string ans = isFibonacci(n);
        cout<< ans << endl;
    }
    return 0;
}
*/

/*
//Q6.
//Rotate the vector array by k times to the left and print the rotated final vector array:---------------
#include<iostream>
#include<vector>
using namespace std;
vector<int> leftRotation(int k , vector<int> arr){
    int n = arr.size(); 
    vector<int>final_arr(n);
    for(int i=0 ; i<n ; i++){
        final_arr[(n-k+i)%n] = arr[i];
    }
    return final_arr;
}
int main(){
    int k = 2; // rotate k times 
    vector<int> arr = {10,20,30,40,50};
    vector<int>ans = leftRotation(k , arr);
    for(int j=0 ; j<arr.size() ;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}
*/



//Q7.
// we have 9 stone and 1 of this stone is heavy. we have a comparision machine . minimum comparision required to find the heavy one.
// answer = 2.



/*
// Q8.
// An arcade game player wants to climb to the top of the leaderboard and track their ranking.
// The game uses Dense Ranking, so its leaderboard works like this:
// The player with the highest score is ranked number 1 on the leaderboard.
// Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.
// Example
//ranked = [100, 90, 90, 80]
//player = [70, 80, 105]
// The ranked players will have ranks 1, 2, 2, and 3, respectively. If the player's scores are 70, 80 and 105,
// their rankings after each game are 4th, 3rd and 1st. Return [4, 3, 1] .
#include<iostream>
#include<vector>
using namespace std;
vector<int> show_rank(vector<int> ranked  , vector<int> player){
    // Remove duplicates from ranked to create a unique scores list
    vector<int> unique_ranked;
    for(int score : ranked){
        if(unique_ranked.empty() || unique_ranked.back() != score){
            unique_ranked.push_back(score);
        }
    }
    vector<int> result;
    int n = unique_ranked.size();
    for(int score : player){
        // Binary search to find the rank
        int left = 0, right = n - 1;
        int rank = n + 1; // Default rank if score is less than all ranked scores
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(unique_ranked[mid] <= score){
                rank = mid + 1; // +1 for 1-based ranking
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        result.push_back(rank);
    }
    return result;
}
int main(){
    int n ; cin >> n ; 
    vector<int>ranked(n);
    for(int i=0 ; i<n ; i++){
        cin >> ranked[i];
    }
    int m ; cin >> m ;
    vector<int>player(m);
    for(int i=0 ; i<m ; i++){
        cin >> player[i];
    }
    vector<int> ans = show_rank(ranked , player);
    for(int i=0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
// Q9.
// The factorial of the integer n, written n!, is defined as:  n! = n x (n - 1) x (n - 2) x ... x 1
// Calculate and print the factorial of a given integer.
// Note: Factorials of n>20 can't be stored even in a 64 bit long long variable. Big integers must be used for such calculations.
// Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.
// We recommend solving this challenge using BigIntegers.
#include<iostream>
#include<vector>
using namespace std;
void factorial(int n){
    vector<int> result;
    result.push_back(1); // Initialize result with 1
    for(int i = 2; i <= n; i++){
        int carry = 0;
        for(int j = 0; j < result.size(); j++){
            int prod = result[j] * i + carry;
            result[j] = prod % 10; // Store last digit
            carry = prod / 10; // Carry forward the rest
        }
        while(carry){
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    // Print the result in reverse order
    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i];
    }
    cout << endl;
}
int main(){
    int n; cout << "Enter a number :- " ; cin >> n;
    cout << "factorial of " << n << " is ";
    factorial(n);
    return 0;
}
*/

/*
// Q10.
// A 3 x 3 magic square is a 3 x 3 grid filled with distinct integers from 1 to 9 such that each cell contains a different integer and the sum of the integers in each row, column, and both main diagonals is the same.
// You will be given a 3 x 3 matrix of integers in the inclusive range [1, 9].
// We can convert any digit a to any other digit b in the range [1, 9] at cost of |a - b|.
// Given s, convert it into a magic square at minimal cost. Print this cost on a new line.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    // All 8 possible 3x3 magic squares using digits 1-9
    vector<vector<vector<int>>> magic_squares = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };
    int min_cost = INT_MAX; // Initialize minimum cost to maximum integer value
    for (const auto& magic : magic_squares) {
        int current_cost = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                // Calculate the absolute difference between input and current magic square
                current_cost += abs(s[i][j] - magic[i][j]);
            }
        }
        // Update minimum cost if the current cost is lower
        min_cost = min(min_cost, current_cost);
    }
    return min_cost;
}
// Example usage and main function for HackerRank format
int main() {
    vector<vector<int>> s(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> s[i][j];
        }
    }
    int result = formingMagicSquare(s);
    cout << result << endl;
    return 0;
}
*/

/*
// Q11.
// Larry has been given a permutation of a sequence of natural numbers incrementing from 1 to n.
// He must determine whether the array can be sorted using the following operation any number of times:
// Choose any 3 consecutive indices and rotate their elements in such a way that . ABC -> BCA -> CAB -> ABC .
// On a new line for each test case, print YES if A can be fully sorted. Otherwise, print NO.
#include <bits/stdc++.h>
using namespace std;
string larrysArray(vector<int> A) {
    int inv = 0;
    int n = A.size();
    // count inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]){
                inv++;
            }
        }
    }
    // if inversion count is even → possible
    return (inv % 2 == 0) ? "YES" : "NO";
}
int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        cout << larrysArray(A) << "\n";
    }
}
*/

/*
// Q12. 
// Maximum Subarray Sum Problem - calculate the sum of all possible subarrays and return the maximum sum among them.
// Note : Try to Solve in linear time complexity.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Print all sub-arrays of a vector function
void Print_subarray(vector<int>& nums , int n){
    for(int st=0 ; st<n ; st++){
        for(int end=st ; end<n ; end++){
            for(int i=st ; i<=end ; i++){
                cout << nums[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}
// Brute force approach
int max_sum(vector<int>& nums , int n){
    int maxSum = INT_MIN;
    for(int st=0 ; st<n ; st++){
        int currSum = 0;
        for(int end=st ; end<n ; end++){
            currSum += nums[end];
            maxSum = max(maxSum , currSum);
        }
    }
    return maxSum;
}
// Kadane's Algorithm
int max_Sum(vector<int>& nums , int n){
    int maxSum = INT_MIN , currSum = 0;
    for(int i=0 ; i<n ; i++){
        currSum += nums[i];
        maxSum = max(maxSum , currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}
int main(){
    vector<int> nums = {-1, -2, -3, -4, -5};
    int n = nums.size();

    int ans = max_Sum(nums , n); //max subarray sum
    cout << ans << endl;

    return 0;
}
*/

/*
// Q13.
// Pair sum - return pair of index whose elements sum is equals to the target. 
// Note : given array or vector is sorted.
// we return pair in form of a vector of size Two.

#include <iostream>
#include <vector>
using namespace std;
vector<int> pairsum(vector<int>& nums , int n , int tar){
    int st=0 , end = n-1;
    vector<int> ans;

    while(st < end){
        if(nums[st] + nums[end] == tar){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if(nums[st] + nums[end] > tar){
            end--;
        }
        else{
            st++;
        }
    }
}
int main(){
    vector<int> nums = {1, 2, 5, 7, 9};
    int n = nums.size();
    int tar = 9;

    vector<int> ans = pairsum(nums , n , tar);
    cout << "index pair : (" << ans[0] << "," << ans[1] << ")";
    
    return 0;
}
*/

/*
// Q14.
// Majority element - find majority element in a vector or an array.
// majority element is the element which occurs more than (size/2) times in an array or a vector.
// Or you can say - element with maximum occurance.
// given : answer always exist.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// T(n) = O(nlogn) 
int majority_ele(vector<int>& nums , int n){
    //sort
    sort(nums.begin() , nums.end());
    //loop
    int freq = 1 , ans = nums[0];
    for(int i=1 ; i<n ; i++){
        if(nums[i] == nums[i-1]){
            freq++;
        }else{
            freq = 1;
            ans = nums[i];
        }

        if(freq > n/2){
            return ans;
        }
    }
    return -1; // never executed
}
// Moore's voting algorithm   ,      T(n) = O(n)
int Majority_ele(vector<int>&nums , int n){
    int freq = 0 , ans = 0;
    for(int i=0 ; i<n ; i++){
        if (freq == 0){
            ans = nums[i];
        }
        if(nums[i] == ans){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, 2, 2, 2, 1, 2, 4, 4};
    int n = nums.size();

    int ans = Majority_ele(nums , n);
    cout << ans << endl;

    return 0;
}
*/

// Q15.          ...to be added soon...