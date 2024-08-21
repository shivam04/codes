class FooBar {
    private int n;
    Semaphore f = new Semaphore(1);
    Semaphore s = new Semaphore(0);
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            f.acquire();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            s.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            s.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            f.release();
        }
    }
}