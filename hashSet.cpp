/*
705. Design HashSet

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.

*/

class MyHashSet {
    int numBuckets;
    // vector of vector of int
    vector<vector<int>> bucket;
    
    inline int hash_fun(int key)
    {
        return (key % numBuckets);
    }
    
public:
    
    
    
    /** Initialize your data structure here. */
    MyHashSet() {
        numBuckets = 12000; //since the problem statement asks 10K ops 
        // in the worst we may have 10K adds, keeping more that what asks is good defer collision
        bucket = vector<vector<int>>(numBuckets, vector<int>{});
    }
    
    void add(int key) {
        
        int indx = hash_fun(key);
        
        if (find(bucket[indx].begin(), bucket[indx].end(), key) == bucket[indx].end()) // Not already seen, so add
            bucket[indx].push_back(key);
        
    }
    
    void remove(int key) {
        
       int indx = hash_fun(key);;
        
        auto iter = find(bucket[indx].begin(), bucket[indx].end(), key);
        if (iter != bucket[indx].end())
            bucket[indx].erase(iter);
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
        int indx = hash_fun(key);;
        
        if (find(bucket[indx].begin(), bucket[indx].end(), key) != bucket[indx].end()) // Found
            return true;
        
        
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
