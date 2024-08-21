class BoundedBlockingQueue {
    private List<Integer> queue;
    private int capacity;
    public BoundedBlockingQueue(int capacity) {
        this.capacity = capacity;
        this.queue = new LinkedList<>();
    }

    public synchronized void enqueue(int element) throws InterruptedException {
        while(this.size() == capacity) wait();
        queue.add(element);
        notifyAll();
    }

    public synchronized int dequeue() throws InterruptedException {
        while(queue.isEmpty()) wait();
        int res = queue.remove(0);
        notifyAll();
        return res;
    }

    public int size() {
        return queue.size();
    }
}