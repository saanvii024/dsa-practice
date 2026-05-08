#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Helper function to check if the current number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        
        // If the array only has 1 element, we are already at the end. 0 jumps needed.
        if (n == 1) return 0;

        // --- STEP 1: PRECOMPUTATION (Building the Phonebook) ---
        // Key: Prime Number -> Value: List of indices that are a multiple of this prime
        unordered_map<int, vector<int>> primeToIndices;
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int temp = val;
            
            // Find all prime factors of the number at nums[i]
            // If 'p' is a prime factor of nums[i], then nums[i] is a multiple of 'p'.
            for (int p = 2; p * p <= temp; p++) {
                if (temp % p == 0) {
                    primeToIndices[p].push_back(i); // Add this index to the prime's list
                    
                    // Divide out this prime factor to find the remaining ones
                    while (temp % p == 0) {
                        temp /= p;
                    }
                }
            }
            // If the remaining number is a prime greater than 1, add it too
            if (temp > 1) {
                primeToIndices[temp].push_back(i);
            }
        }

        // --- STEP 2: SETUP BFS ---
        
        // Queue stores pairs of integers: (current_index, jumps_taken)
        queue<pair<int, int>> q; 
        
        // Standard visited array for the indices to prevent infinite loops
        vector<bool> vis(n, false); 
        
        // A set to remember which prime numbers we have already teleported from
        unordered_set<int> vis_primes; 

        // Start at index 0, having taken 0 jumps
        q.push(make_pair(0, 0)); 
        vis[0] = true;

        // --- STEP 3: RUN BFS ---
        
        while (q.size() > 0) {
            
            // Get the front item from the queue
            pair<int, int> current = q.front();
            int u = current.first;       // The current index we are standing on
            int jumps = current.second;  // The number of jumps taken to reach 'u'
            q.pop();

            // Did we reach the target?
            if (u == n - 1) {
                return jumps;
            }

            // EXPLORE TYPE 1: Adjacent steps
            int left_neighbor = u - 1;
            int right_neighbor = u + 1;

            if (left_neighbor >= 0 && vis[left_neighbor] == false) {
                vis[left_neighbor] = true;
                q.push(make_pair(left_neighbor, jumps + 1)); 
            }

            if (right_neighbor < n && vis[right_neighbor] == false) {
                vis[right_neighbor] = true;
                q.push(make_pair(right_neighbor, jumps + 1));
            }

            // EXPLORE TYPE 2: Prime Teleportation
            int val = nums[u];
            
            // If the number we are standing on is prime AND we haven't used it yet
            if (isPrime(val) && vis_primes.find(val) == vis_primes.end()) {
                
                vis_primes.insert(val); // Mark this prime as used
                
                // Loop through our pre-built phonebook to find all indices that are multiples
                for (int v : primeToIndices[val]) {
                    
                    if (vis[v] == false) {
                        vis[v] = true;
                        q.push(make_pair(v, jumps + 1));
                    }
                }
            }
        }
        
        // If the queue empties and we never reached the end (shouldn't happen with valid inputs)
        return -1;
    }
};