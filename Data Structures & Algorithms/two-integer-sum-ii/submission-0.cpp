class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]!=target){
                if(abs(numbers[i+1]+numbers[j]-target)>abs(numbers[i]+numbers[j-1]-target)){
                    j--;
                }else{
                    i++;
                }
            }else{
               return vector<int>({i+1,j+1}); 
            }
        }
        return vector<int>();
    }
};
