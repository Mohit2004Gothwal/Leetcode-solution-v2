#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) for range queries
class FenwickTree {
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }
    void update(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    // Query sum from index left to right
    int queryRange(int left, int right) {
        if (left > right) return 0;
        return query(right) - query(left - 1);
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        
        // Step 1: Compute raw prefix values P_i
        vector<long long> P(n + 1, 0);
        long long current_even = 0;
        long long current_odd = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) current_even++;
            else current_odd++;
            P[i + 1] = current_even * b - current_odd * a;
        }

        // Step 2: Coordinate Compression for Fenwick Tree ranking
        vector<long long> unique_vals = P;
        sort(unique_vals.begin(), unique_vals.end());
        unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
        
        auto getRank = [&](long long val) {
            return lower_bound(unique_vals.begin(), unique_vals.end(), val) - unique_vals.begin() + 1;
        };

        // Step 3: Process subarrays while enforcing the "at least one odd number" rule
        FenwickTree bit(unique_vals.size());
        long long total_valid_subarrays = 0;
        
        int last_odd_idx = -1; 
        int valid_j_bound = -1; // Marks up to what index j we can safely look back

        // Insert the base case P[0] = 0
        bit.update(getRank(P[0]), 1);

        for (int i = 1; i <= n; i++) {
            // Check if current element is odd (using 0-indexed adjustment for nums)
            if (nums[i - 1] % 2 != 0) {
                // If we hit an odd number, all previous prefix boundaries up to (i-1) 
                // are now valid because any subarray ending at i will include this odd item.
                while (valid_j_bound < i - 1) {
                    valid_j_bound++;
                    if (valid_j_bound > 0) {
                        // Dynamically add older prefixes into our Fenwick active tree
                        bit.update(getRank(P[valid_j_bound]), 1);
                    }
                }
                last_odd_idx = i - 1;
            }

            if (last_odd_idx != -1) {
                // We need to count j values where P[j] >= P[i]
                int current_rank = getRank(P[i]);
                int total_ranks = unique_vals.size();
                
                // Query counts from current_rank up to total_ranks
                total_valid_subarrays += bit.queryRange(current_rank, total_ranks);
            }
        }

        return total_valid_subarrays;
    }
};
