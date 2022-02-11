class DiningPhilosophers {
    ReentrantLock[] locks = new ReentrantLock[5];
    Lock xxx = new ReentrantLock();
    
    public DiningPhilosophers() {
        for (int i = 0; i < 5; i += 1) {
            locks[i] = new ReentrantLock(true);
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        xxx.lock();
        locks[philosopher%5].lock();
        pickLeftFork.run();
        locks[(philosopher+1)%5].lock();
        pickRightFork.run();
        eat.run();
        putRightFork.run();
        locks[(philosopher+1)%5].unlock();
        putLeftFork.run();
        locks[philosopher%5].unlock();
        xxx.unlock();
    }
}