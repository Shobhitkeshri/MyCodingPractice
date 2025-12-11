class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int falseCount=0;
        int trueCount=0;
        int trueLength=0,falseLength=0;

        int start=0,end=0;
        while(end<answerKey.size()){
            trueCount+=answerKey[end]=='F';
            if(trueCount>k){
                trueCount-=answerKey[start]=='F';
                start++;
            }
            trueLength=max(trueLength,end-start+1);
            end++;
        }
         start=0,end=0;
        while(end<answerKey.size()){
            falseCount+=answerKey[end]=='T';
            if(falseCount>k){
                falseCount-=answerKey[start]=='T';
                start++;
            }
            falseLength=max(falseLength,end-start+1);
            end++;
        }
        return max(trueLength,falseLength);        
    }
};