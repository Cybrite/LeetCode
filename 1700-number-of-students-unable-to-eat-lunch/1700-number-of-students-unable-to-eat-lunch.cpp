class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        int sand_num = 0;
        int rotations = 0;

        for(int s : students){
            stu.push(s);
        }

        while(!stu.empty() && rotations < stu.size()){
            if( stu.front() == sandwiches[sand_num] ){
                stu.pop();
                sand_num++;
                rotations = 0;
            }else{
                stu.push(stu.front());
                stu.pop();
                rotations++;
            }
        }

        return stu.size();
    }
};