/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = 0;
    int r = intervals.size()-1;
    int mini = min(newInterval.start,newInterval.end);
    int maxi = max(newInterval.start,newInterval.end);
    newInterval.start = mini;
    newInterval.end = maxi;
    vector<Interval> v;
    if(r==-1){
        v.push_back(newInterval);
        return v;
    }
    int s = newInterval.start;
    int e = newInterval.end;
    int as=-1;
    int ae = -1;
    int i;
    for(i=l;i<=r;i++){
        if(intervals[i].start<=s and intervals[i].end>=s){
            as = i;
            break;
        }
    }
    for(i=r;i>=l;i--){
        if(intervals[i].start<=e and intervals[i].end>=e){
            ae = i;
            break;
        }
    }
    if(as==-1 and ae==-1){
        if(e<intervals[l].start){
            v.push_back(newInterval);
            for(int i=l;i<=r;i++){
                v.push_back(intervals[i]);
            }
        }else if(s>intervals[r].end){
            for(int i=l;i<=r;i++){
                v.push_back(intervals[i]);
            }
            v.push_back(newInterval);
        }else if(s<intervals[l].start and e>intervals[r].end){
            v.push_back(newInterval);
            return v;
            
        }else{
            for(int i=l;i<=r;i++){
                if(intervals[i].start>s){
                    as = i;
                    break;
                }
            }
            for(int i=r;i>=l;i--){
                if(intervals[i].end<e){
                    ae = i;
                    break;
                }
            }
            for(int i=l;i<=as-1;i++){
                v.push_back(intervals[i]);
            }
            Interval temp;
            temp.start = min(intervals[as].start,s);
            temp.end = max(intervals[ae].end,e);
            v.push_back(temp);
            for(int i = ae+1;i<=r;i++){
                v.push_back(intervals[i]);
            }
        }
        
    }else if(as==-1){
        for(int i=l;i<=r;i++){
            if(intervals[i].start>s){
                as = i;
                break;
            }
        }
        for(int i=l;i<=as-1;i++){
            v.push_back(intervals[i]);
        }
        Interval temp;
        temp.start = min(intervals[as].start,s);
        temp.end = max(intervals[ae].end,e);
        v.push_back(temp);
        for(int i = ae+1;i<=r;i++){
            v.push_back(intervals[i]);
        }
    }else if(ae==-1){
        for(int i=l;i<=as-1;i++){
            v.push_back(intervals[i]);
        }
        for(int i=r;i>=l;i--){
            if(intervals[i].end<e){
                ae = i;
                break;
            }
        }
        Interval temp;
        temp.start = min(intervals[as].start,s);
        temp.end = max(intervals[ae].end,e);
        v.push_back(temp);
        for(int i = ae+1;i<=r;i++){
            v.push_back(intervals[i]);
        }
        
    }else{
        for(int i=l;i<=as-1;i++){
            v.push_back(intervals[i]);
        }
        Interval temp;
        temp.start = min(intervals[as].start,s);
        temp.end = max(intervals[ae].end,e);
        v.push_back(temp);
        for(int i = ae+1;i<=r;i++){
            v.push_back(intervals[i]);
        }
    }
    return v;
}
