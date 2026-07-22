class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> current_line;
        int current_length = 0;

        for(int i=0; i<words.size(); i++){
            string word = words[i];

            if(!current_line.empty() && current_length + word.length() + current_line.size() > maxWidth){
                int total_space_needed = maxWidth - current_length;
                int gaps = current_line.size() - 1;
                string justified_line = "";

                if(gaps == 0){
                    justified_line += current_line[0];
                    while(justified_line.length() < maxWidth){
                        justified_line += " ";
                    }
                }else{
                   int base_spaces = total_space_needed / gaps;
                   int extra_spaces = total_space_needed % gaps;

                   for(int j=0; j<gaps; j++){
                    justified_line += current_line[j];

                    justified_line += string(base_spaces , ' ');

                    if(j < extra_spaces){
                        justified_line += " ";
                    }
                   }
                   
                   justified_line += current_line[gaps];
                }

                ans.push_back(justified_line);
                current_line.clear();
                current_length = 0;
            }

            current_line.push_back(word);
            current_length += word.length();
        }

        string last_line = "";

        for(int i=0; i<current_line.size(); i++){
            last_line += current_line[i];
            if(i != current_line.size()-1){
                last_line += " ";
            }
        }

        while(last_line.length() < maxWidth){
            last_line += " ";
        }

        ans.push_back(last_line);

        return ans;
    }
};