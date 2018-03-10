/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below*/
void printDuplicates(int arr[], int n)
{
   int i;
   int f=0;
   for(i=0;i<n;i++){
        int idx = arr[i]%n;
        arr[idx]+=n;
        int temp = arr[idx];
        if(temp/n>1){
            f=1;
            if(temp/n<3)
            cout<<idx<<" ";
        }
   }
   
   if(!f)
   cout<<"-1";
}