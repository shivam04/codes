class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N) {
        sort(Entry, Entry+N);
        sort(Exit, Exit+N);
        int res = 1;
        int resT = Entry[0];
        int pN = 1;
        
        int i = 1, j = 0;
        while(i<N and j<N) {
           if(Entry[i] <= Exit[j]) {
               pN++;
               if(pN > res) {
                   res = pN;
                   resT = Entry[i];
               }
               i++;
           } else {
               pN--;
               j++;
           }
           
        }
        return {res,resT};
	}
};