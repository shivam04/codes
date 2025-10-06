/*
Food delivery companies employ tens of thousands of delivery drivers who each submit hundreds of deliveries per week.
Delivery details are automatically sent to the system immediately after the delivery.

Delivery drivers have different hourly payment rates, depending on their performance.
Drivers can take on, and be paid for, multiple deliveries simultaneously.

If a driver is paid $10.00 per hour, and a delivery takes 1 hour and 30 minutes, the driver is paid $15.00 for that delivery.

We are building a dashboard to show a single number - the total cost of all deliveries - on screens in the accounting department offices.

At first, we want the following functions:

* `addDriver(driverId [integer], usdHourlyRate [double])`
   - The given driver will not already be in the system
   

* `recordDelivery(driverId [integer], startTime, endTime)`
   - Discuss the time format you choose
   - Times require minimum one-second precision
   - The given driver will already be in the system
   - All deliveries will be recorded immediately after the delivery is completed
   - No delivery will exceed 3 hours

* `getTotalCost()`
   - Return the total, aggregated cost of all drivers' deliveries recorded in the system
   - For example, return 135.30 if one driver is in the system and has a total cost of 100.30 USD and another driver is in the system and has a total cost of 35.00 USD.
   - This will be used for a live dashboard
   - Do not worry about exact formatting

All inputs will be valid.

Share any decisions or assumptions you make.
If you do anything differently in this interview than you would in production, share that.

Before coding, let's discuss how you will store the time data and why.

Assumptions:
1. Drivr regisstation only once.
2. record Delivery timestamp long seconds 

1. Registration part -> using hasmap <string, double> 
2. DeliveryRecord: hapmap< string, List<Pair<Long(start time),Long(end time)>>

m*n

we are optimisizng
usdHourlyRate * (totalHoursOfDeliveryDriverHasDone)
O(N)

3. PreCoumpted Data
toalCostForTheDeliveries += usdHourlyRate * (endTime-startTime)/60
O(1)

We want to see good OOP practices.
You may look up syntax using a search engine.

Time complexity : 
Space complexity : 
// Time O(1)
// Space Complexity O(N*M)
// Compution Purpose Space Complexity -> O(1)

Q2 : 
The analytics team uses the live dashboard reporting function you built to see how much money is owed in total to all drivers.

Add the following functions:

* `payUpTo (payTime)`
   - Pay all drivers for recorded deliveries which ended up to and including the given time
   
   find all the deliveries where endTime <= payTime -> mark it as isPaid = true
   O(N*M)

* `getTotalCostUnpaid()`
   - Return the total, aggregated cost of all drivers' deliveries which have not been paid
   1. totalPaidAmount 
    1.1. totalCost - totalPaidAmount;
    
    O(1)
    
The solution does not need to be thread-safe or handle concurrency.



Q3 : 
Some cities have restrictions on the total number of drivers that can be active at any time.

As one part of understanding our compliance with restrictions,
our team wants to understand the maximum number of drivers who have been actively making deliveries simultaneously.

For one of our tasks in this large project, write a new function:

* `maxSimultaneousDrivers24hBefore (endTime [integer])`
   * Returns the maximum number of simultaneous drivers who were active in the 24 hours before the given end time.

The solution does not need to be thread-safe or handle concurrency.

[driver, start, end]
[1, 1 10]
[2, 1, 3]
[3, 2, 4]
[4, 3, 5]
[5, 5, 6]

O(N*M*24*60*60)




*/
import java.io.*;
import java.util.*;
import java.util.function.LongToIntFunction;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import javax.swing.JList.DropLocation;

import org.apache.xml.resolver.apps.resolver;

import be.abeel.util.Pair;

/**
 * file
 */
class Delivery {

    long stratTime;
    long endTime;
    boolean isPaid;
    
    public Delivery(long startTime, long endTime) {
        this.stratTime = startTime;
        this.endTime = endTime;
    }
    
    public long getStartTime() {
        return stratTime;
    }
    public long getEndTime() {
        return endTime;
    }
    public void setIsPaid(boolean isPaid) {
        this.isPaid = isPaid;
    }
    
    public boolean isPaid() {
        return this.isPaid;
    }
}

class Driver {
    int driverId;
    double hourlyRate; 
    List<Delivery> deliveries;
    
    public Driver(double hourlyRate, int driverId) {
        this.hourlyRate = hourlyRate;
        deliveries = new ArrayList<>();
        this.driverId = driverId;
    }
    
    public double getHourlyCost() {
        return this.hourlyRate;
    }
    
    public void addDeliveries(Long startTime, Long endTime) {
        this.deliveries.add(new Delivery(startTime, endTime));
    }
    
    public List<Delivery> getDeliveries() {
        return deliveries;
    }
}

class DeliverySystem {
    double totalCost;
    double totalPaidAmount;
    Map<Integer, Driver> driverDB;
    
    public DeliverySystem() {
        totalCost = 0;
        totalPaidAmount = 0;
        driverDB = new HashMap<>();
    }
    
    public void addDriver(int driverId, double usdHourlyRate) {
        driverDB.put(driverId, new Driver(usdHourlyRate, driverId));
    }
    
    public void recordDelivery(int driverId, long startTime, long endTime) {
        driverDB.get(driverId).addDeliveries(startTime, endTime);
        totalCost += ((endTime - startTime)/3600.0)*driverDB.get(driverId).getHourlyCost();
    } 
    
    public double getTotalCost() {
        return Math.round(this.totalCost*100.0)/100.0;
    }
    
    public void payUpTo(long payTime) {
        for(Map.Entry<Integer, Driver> entry: driverDB.entrySet()) {
            Driver driverDetails = entry.getValue();
            for (Delivery deliveryDetails: driverDetails.getDeliveries()) {
                if (deliveryDetails.getEndTime() <= payTime && !deliveryDetails.isPaid()) {
                    deliveryDetails.setIsPaid(true);
                    totalPaidAmount += ((deliveryDetails.getEndTime() - deliveryDetails.getStartTime())/3600.0)*driverDetails.getHourlyCost();
                }
            }
        }
    }
    
    public double getTotalCostUnpaid() {
        double totalUpaidAmount = totalCost - totalPaidAmount;
        return Math.round(totalUpaidAmount*100.0)/100.0;
    }
    
    public int maxSimultaneousDrivers24hBefore(long endTime) {
        long startTime = endTime - 24*60*60;
        long maxDriver = 0;
        for(long i = startTime; i<=endTime; i++) {
            long count = 0;
            for(Map.Entry<Integer, Driver> entry: driverDB.entrySet()) {
                Driver driverDetails = entry.getValue();
                for (Delivery deliveryDetails: driverDetails.getDeliveries()) {
                    if (deliveryDetails.getEndTime() >= i && deliveryDetails.getStartTime() <= i) {
                        count += 1;
                    }
                }
            maxDriver = Math.max(a, b);
        }
        }
        
    }
}



public class Solution {

    static int addNumbers(int a, int b) {
        return a+b; 
    }

    public static void main(String[] args) {
        DeliverySystem billingSystem = new DeliverySystem();
        
        billingSystem.addDriver(1, 35.10);
        billingSystem.addDriver(2, 15.15);
        billingSystem.addDriver(3, 8.55);
        billingSystem.addDriver(4, 11.28);
        billingSystem.addDriver(5, 0.1);

        // System.out.println(billingSystem.getTotalCost());
        billingSystem.recordDelivery(1, 0, 3600);    // Jan 1 1970 00:00:00 - Jan 1 1970 01:00:00
        billingSystem.recordDelivery(2, 0, 5400);    // Jan 1 1970 00:00:00 - Jan 1 1970 01:30:00
        billingSystem.recordDelivery(2, 5400, 7200); // Jan 1 1970 01:30:00 - Jan 1 1970 02:00:00

        // System.out.println(billingSystem.getTotalCost());

        billingSystem.recordDelivery(5, 0, 3600);      // Jan 1 1970 00:00:00 - Jan 1 1970 01:00:00
        billingSystem.recordDelivery(5, 3600, 7200);   // Jan 1 1970 01:00:00 - Jan 1 1970 02:00:00
        billingSystem.recordDelivery(5, 7200, 10800);  // Jan 1 1970 02:00:00 - Jan 1 1970 03:00:00
        billingSystem.recordDelivery(5, 10800, 14400); // Jan 1 1970 03:00:00 - Jan 1 1970 04:00:00
        billingSystem.recordDelivery(5, 14400, 18000); // Jan 1 1970 04:00:00 - Jan 1 1970 05:00:00

        // System.out.println(billingSystem.getTotalCost());
        
        
        billingSystem.payUpTo(3599); // Jan 1 1970 00:00:59, one second before the first delivery
        System.out.println(billingSystem.getTotalCostUnpaid());
        System.out.println(billingSystem.getTotalCost());

        billingSystem.payUpTo(3601); // Jan 1 1970 01:00:01, one second after the first delivery
        System.out.println(billingSystem.getTotalCostUnpaid());
        System.out.println(billingSystem.getTotalCost());

        billingSystem.payUpTo(7201); // Jan 1 1970 02:00:01, one second after the last delivery
        System.out.println(billingSystem.getTotalCostUnpaid());
        System.out.println(billingSystem.getTotalCost());

        billingSystem.payUpTo(7201); // Jan 1 1970 02:00:01, one second after the last delivery
        System.out.println(billingSystem.getTotalCostUnpaid());
        System.out.println(billingSystem.getTotalCost());
    }
}
