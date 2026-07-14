class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> valToidx;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valToidx.contains(val)){
            return false;
        }else{
            nums.push_back(val);
            valToidx[val] = nums.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(!valToidx.contains(val)){
            return false;
        }else{
            int i = valToidx[val];
            int last_val = nums.back();

            nums[i] = last_val;
            valToidx[last_val] = i;
            nums.pop_back();
            valToidx.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int i = rand() % nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */