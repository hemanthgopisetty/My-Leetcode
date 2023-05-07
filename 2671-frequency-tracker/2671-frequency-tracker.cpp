class FrequencyTracker {
public:
    unordered_map<int,int>om;
    unordered_map<int,int>fm;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(om.count(number))
        {
            fm[om[number]]--;
            if(fm[om[number]]==0)fm.erase(om[number]);
        }
        om[number]++;
        fm[om[number]]++;
    }
    
    void deleteOne(int number) {
        //when there is no element
        if(!om.count(number)) return ;
        
        fm[om[number]]--;
        if(fm[om[number]]==0)fm.erase(om[number]);
        om[number]--;
        if(om[number]==0)om.erase(number);
        else fm[om[number]]++;
    }
    
    bool hasFrequency(int frequency) {
         return fm.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */