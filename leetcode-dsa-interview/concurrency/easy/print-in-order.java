class Foo {
    Semaphore f = new Semaphore(1);
    Semaphore s = new Semaphore(0);
    Semaphore t = new Semaphore(0);

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        f.acquire();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        s.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        s.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        t.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        t.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        f.release();
    }
}