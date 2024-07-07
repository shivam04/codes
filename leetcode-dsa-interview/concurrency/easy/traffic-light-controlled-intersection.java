class TrafficLight {
    private int currActive;

    public TrafficLight() {
        currActive = 0;
    }
    
    public void carArrived(
        int carId,           // ID of the car
        int roadId,          // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,       // Direction of the car
        Runnable turnGreen,  // Use turnGreen.run() to turn light to green on current road
        Runnable crossCar    // Use crossCar.run() to make car cross the intersection 
    ) {
        synchronized(this) {
            if ((direction ==1 || direction == 2) && currActive == 1) {
                turnGreen.run();
                currActive = ((currActive+1)%2);
            } else if ((direction == 3 || direction == 4) && currActive == 0) {
                turnGreen.run();
                currActive = ((currActive+1)%2);
            }
            crossCar.run();
        }
    }
}