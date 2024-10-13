/***
 * Java: Cargo Management
Description
A shipping company needs a cargo management application.

 

Create the Package class and implement the IPackage interface with the following properties.

id (int)
name (string)
weight (int)
length (int)
width (int)
height (int)
 

Create the Cargo class and implement the IShipping interface.

Declare a field of List<IPackage> to store the packages.
Add the following methods to the Cargo class:
addPackage(IPackage package): adds a package to the list of packages
removePackage(int id): removes a package from the list based on its ID
calculateTotalCost(): returns the total cost of shipping for all packages in the list
categoryPrices(): returns a map of the weight category, and the total shipping cost for each category in the packages list
Weight ≤ 1 and Length ≤ 30 and Width ≤ 30 and Height ≤ 30 -> Small
Weight ≤ 3 and Length ≤ 60 and Width ≤ 60 and Height ≤ 60 -> Medium
Other -> Large
packageList(): returns a map with each unique package name as the key and the respective number of packages as value.
 

The cost to ship an item is based on the product of Length * Width * Height (L * W * H)

L * W * H <= 100000: 10
100000 < L * W * H <= 500000: 20
500000 < L * W * H: 30
 

Example

There are 6 package objects, with Id, Name, Weight, Length, Width, and Height.

1 Package-1 3 46 40 23

2 Package-2 2 54 68 37

3 Package-3 2 65 45 60

4 Package-4 3 20 50 11

5 Package-5 1 29 22 9

6 Package-6 1 11 16 31

 

Calculate the total shipping cost. For package Id = 1, LWH = 46*40*23 = 42320, so the shipping cost is 10. The sum of shipping costs for all items is 80.

 

Output

Total Cost: 80

Medium Category Price: 30

Large Category Price: 40

Small Category Price: 10

Package-1 (1 units)

Package-2 (1 units)

Package-3 (1 units)

Package-4 (1 units)

Package-5 (1 units)

Package-6 (1 units)

 

Note: I/O and method calls are handled by the provided code stub.

 

Input Format For Custom Testing
Sample Case 1
Sample Input For Custom Testing

3 
1 Package-1 1 4 40 35 
2 Package-2 2 62 3 7 
3 Package-3 4 46 12 56
Sample Output

Total Cost: 30 
Large Category Price: 20 
Medium Category Price: 10 
Package-1 (1 units) 
Package-2 (1 units) 
Package-3 (1 units)
Explanation

The 3 packages are created, shipping costs are calculated, and output is generated.

Sample Case 2
Sample Input For Custom Testing

9
1 Package-1 1 60 2 21
2 Package-2 1 67 4 30
3 Package-3 3 48 63 63
4 Package-4 2 65 64 43
5 Package-5 2 67 31 12
6 Package-6 3 39 67 41
7 Package-7 3 13 67 6
8 Package-8 2 5 9 25
9 Package-9 1 2 58 19
Sample Output

Total Cost: 120
Large Category Price: 90
Medium Category Price: 30
Package-1 (1 units)
Package-2 (1 units)
Package-3 (1 units)
Package-4 (1 units)
Package-5 (1 units)
Package-6 (1 units)
Package-7 (1 units)
Package-8 (1 units)
Package-9 (1 units)
 */

import java.io.*;
import java.util.*;

interface IPackage {
    void setId(int id);
    int getId();
    void setName(String name);
    String getName();
    void setWeight(int weight);
    int getWeight();
    void setLength(int length);
    int getLength();
    void setWidth(int width);
    int getWidth();
    void setHeight(int height);
    int getHeight();
}

interface IShipping {
    void addPackage(IPackage pack);
    void removePackage(int id);
    int calculateTotalCost();
    Map<String, Integer> categoryPrices();
    Map<String, Integer> packageList();
}
class Package implements IPackage {
    int id;
    String name;
    int weight;
    int length;
    int width;
    int height;
    public void setId(int id) {
        this.id = id;
    }
    public int getId() {
        return this.id;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    public void setWeight(int weight) {
        this.weight = weight;
    }
    public int getWeight() {
        return weight;
    }
    
    public void setLength(int length) {
        this.length = length;
    }
    public int getLength() {
        return length;
    }
    
    public void setWidth(int width) {
        this.width = width;
    }
    
    public int getWidth() {
        return width;
    }
    
    public void setHeight(int height) {
        this.height = height;
    }
    
    public int getHeight() {
        return height;
    }
}

enum Category {
    Small,
    Medium,
    Large
}

class Cargo implements IShipping {
    List<IPackage> packages;
    public Cargo() {
        packages = new ArrayList<>();
    }
    
    public void addPackage(IPackage pack) {
        packages.add(pack);
    }
    
    public void removePackage(int id) {
        IPackage removePack = null;
        for (IPackage pack : packages) {
            if (pack.getId() == id) {
                removePack = pack;
            }
        }
        if (removePack != null) {
            packages.remove(removePack);
        }
    }
    
    public int calculateTotalCost() {
        int totalCost = 0;
        for (IPackage pack : packages) {
            totalCost += getPrice(pack);
        }
        return totalCost;
    }
    
    private String getCategory(IPackage pack) {
        if (pack.getWeight() <= 1 && pack.getLength() <= 30 
            && pack.getWidth()<=30 && pack.getHeight() <= 30) {
                return Category.Small.name();
            }
        else if (pack.getWeight() <= 3 && pack.getLength() <= 60 
            && pack.getWidth()<=60 && pack.getHeight() <= 60) {
                return Category.Medium.name();
            }
        return Category.Large.name();
    }
    
    public Map<String, Integer> categoryPrices() {
        Map<String, Integer> categoryBasedPackages = new TreeMap<>();
        for (IPackage pack : packages) {
            String category = getCategory(pack);
            int currentCount = categoryBasedPackages.getOrDefault(category, 0);
            categoryBasedPackages.put(category, currentCount+getPrice(pack));
        }
        return categoryBasedPackages;
    }
    
    private int getPrice(IPackage pack) {
        int volume = pack.getLength()*pack.getWidth()*pack.getHeight();
        if (volume <= 100000) {
            return 10;
        }
        
        if (volume <= 500000) {
            return 20;
        }
        
        return 30;
    }
    
    public Map<String, Integer> packageList() {
        Map<String, Integer> nameBasedPackages = new TreeMap<>();
        for (IPackage pack : packages) {
            int currentPrice = nameBasedPackages.getOrDefault(pack.getName(), 
                0);
            nameBasedPackages.put(pack.getName(), currentPrice+1);
        }
        return nameBasedPackages;
    }
}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        IShipping cargo = new Cargo();
        int cCount = Integer.parseInt(br.readLine().trim());
        //System.out.println(cCount);
        for (int i = 1; i <= cCount; i++) {
            String[] a = br.readLine().trim().split(" ");
            IPackage e = new Package();
            e.setId(Integer.parseInt(a[0]));
            e.setName(a[1]);
            e.setWeight(Integer.parseInt(a[2]));
            e.setLength(Integer.parseInt(a[3]));
            e.setWidth(Integer.parseInt(a[4]));
            e.setHeight(Integer.parseInt(a[5]));
            cargo.addPackage(e);
        }
        int totalCost = cargo.calculateTotalCost();
        out.println("Total Cost: " + totalCost);

        Map<String, Integer> categoryPrices = cargo.categoryPrices();
        for (Map.Entry<String, Integer> categoryPrice : categoryPrices.entrySet()) {
            out.println(categoryPrice.getKey() + " Category Price: " + categoryPrice.getValue());
        }

        Map<String, Integer> packageList = cargo.packageList();
        for (Map.Entry<String, Integer> packageEntry : packageList.entrySet()) {
            out.println(packageEntry.getKey() + " (" + packageEntry.getValue() + " units)");
        }

        out.flush();
        out.close();
    }
}