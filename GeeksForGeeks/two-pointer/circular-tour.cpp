int tour(petrolPump arr[],int n) {
    int start = 0;  
    int end = 1;  
    int curr_petrol = arr[start].petrol - arr[start].distance; 
    while (end != start || curr_petrol < 0)  {  
        while (curr_petrol < 0 && start != end)  {  
            curr_petrol -= arr[start].petrol - arr[start].distance;  
            start = (start + 1) % n;  
            if (start == 0)  
                return -1;  
        }  
        curr_petrol += arr[end].petrol - arr[end].distance;  
  
        end = (end + 1) % n;  
    }
    return start;
}