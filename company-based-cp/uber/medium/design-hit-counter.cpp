class HitCounter {
    private final int THRESHOLD = 300;
    Integer times[];
    Integer hit[];
    public HitCounter() {
        times = new Integer[THRESHOLD];
        hit = new Integer[THRESHOLD];
    }
    
    public void hit(int timestamp) {
        int idx = timestamp%THRESHOLD;
        if (times[idx] == null || (times[idx] != timestamp)) {
            hit[idx] = 1;
            times[idx] = timestamp;
        } else {
            hit[idx]++;
        }
    }
    
    public int getHits(int timestamp) {
        int cnt = 0;
        for(int i = 0; i < THRESHOLD; i++) {
            if (times[i] != null && (timestamp - times[i] < THRESHOLD)) {
                cnt += (hit[i]);
            }
        }
        return cnt;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */