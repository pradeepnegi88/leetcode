class Solution {
public:
   int climb(int max){
       int previous = 0;
       int previous2 = 0;
       int current = 0;
       for (int i = max;i>=0;i--){
            if(i == max) {
                current = 1;
                previous2 = previous;
                 previous = current;
                continue;
                }
                int count = 0;
                if(i+1<=max){
                count+= previous;
                }
                if(i+2<=max){
                count+=  previous2;
                }
               
                current= count;
                previous2 = previous;
                 previous = current;
                 

       }
              return current;


   }

    int climbStairs(int n) {
        return climb(n);
    }
};

//recursion: 0->n
//tabular  : n->0