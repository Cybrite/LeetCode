class MyCalendar {
public:
    vector<pair<int,int>> bookings;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto &p : bookings){
            int s = p.first;
            int e = p.second;

            if(startTime < e && endTime > s){
                return false;
            }
        }

        bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */