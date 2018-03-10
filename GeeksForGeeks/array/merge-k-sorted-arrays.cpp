priority_queue<int, vector<int>, greater<int>> pq;
    int a[k];
    for(int i = 0; i < k; i++){a[i] = 0;}
    int *res = (int*)malloc(sizeof(int)*k*k);
    for(int i = 0; i < k; i++){
        pq.push(arr[i][0]);
    }
    int x = pq.top(); int j = 0;
    while(1){
        if(j >= k*k){break;}
        int  i = 0;
        x = pq.top();
        for(; i < k; i++){
            if(arr[i][a[i]] == x){break;}
        }
        res[j] = x; j++; pq.pop();
        a[i]++;
        if(a[i] >= k){continue;}
        pq.push(arr[i][a[i]]);
    }
    return res;