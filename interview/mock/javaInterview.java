What is abstraction and how is it implemented in Java?

Write code to demonstrate an abstract class and interface and try
to make them connected

abstract class PaymentStrategy {
    public void doPayment();
    
    protected void handleHiddenPaymentUseCase() {
        /// code
    }
}

interface IPaymentStrategy {
    void doPayment();
    
    default handleHiddenPaymentUseCase() {
        /// code
    }
}


class StripePaymentStrategy implements IPaymentStrategy//extends PaymentStrategy {
    public void doPayment() {
        // do preprocessing
        handleHiddenPaymentUseCase();
        // do some post processing;
    }
}

. Explain the static keyword and its various uses in Java

Static methods vs. instance methods: Discuss the differences
between static and instance methods, highlighting when to use each.


static method is class propery
instance metos

Explain the differences between Runnable
and Callable in Java and Explain how and why futures are used with callable

 Write a simple multi-threaded program to print 1 -> 100
 
class MuliThreadedApp {
    public static void main() {
        for(int i=0;i<100;i++) {
            Thread thread = new Thread(() -> System.out.println(i));
            thread.start();
        }
    }
}

: What is thread safety and how can it be ensured in Java applications? 

: Name some of the collections in java which supports Thread
Safety 

Explain the internal working of HashMap in Java.

Array<LinkedLis> -> 10^6

key -> [i]

collison -> [i] -> (key,1)->(key,2)

Discuss the concept of the load factor in HashMap and its impact
on performance. 

Explain the differences between Comparable and Comparator in Java.

Code a comparator which would sort an ArrayList in descending order.

class CustomSort implents Comparator<Integer>{
    int compare(Integer a, Integer b) {
        return b-a;
    }
}

Arrays.sort(arr, new CustomSort());

: Describe the Stream API in Java and its advantages.

: Explain the map, filter and reduce functions in
streams 


Given a list of words, find a list that contains the length
of each word that starts with ‘b’

list: ("apple", "banana", "cherry", "date", "elderberry");


class ListFilter {
    public static void main() {
        List<Stirng> lsit = List.of("apple", "banana", "cherry", "date", "elderberry");
        List<Integer> lengthList = list.stream()
            .filter(String::stratsWith('b'))
            .map(String::getLength())
            .toList();
    }
}

Can you differentiate between StringBuffer and StringBuilder in Java?

Discuss scenarios where using StringBuffer or StringBuilder is more appropriate based on thread safety requirements.

Final vs Finally vs Finalize: Explain the differences and use-cases for final,
finally, and finalize in Java.


