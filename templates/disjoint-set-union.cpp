void initialize(int Arr[], int size[], int N){
    int i;
    for(i=0;i<N;i++){
        size[i] = 1;
        Arr[i] = i;
    }
}

//finding root of an element
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root
    {
     i = Arr[ i ];
    }
    return i;
}


    /*modified union function where we connect the elements by changing the root of one of the elements*/

int union(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B)
}

void weightedunion(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }

}

bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
    return true;
    else
    return false;
}