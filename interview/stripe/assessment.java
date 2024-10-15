// For some items, shipping the first item is more expensive than shipping additional items. Update the shipping matrix to reflect
// quantity based discounts.



// The order remain unchanged and the shipping cost matrix has been updated like the following:


// Order:
// {
//   "country": "US", // or "CA" for the CA order
//   "items": [
//     {"product": "mouse", "quantity": 20},
//     {"product": "laptop", "quantity": 5}
//   ]
// }



// Shipping Cost:


// Each country/product has its own shipping cost tiers:
// {
//   "US": [
//     {
//       "product": "mouse",
//       "costs": [
//         {
//           "minQuantity": 0,
//           "maxQuantity": null,
//           "cost": 550
//         }
//       ]
//     },
//     {
//       "product": "laptop",
//       "costs": [
//         {
//           "minQuantity": 0,
//           "maxQuantity": 2,
//           "cost": 1000
//         },
//         {
//           "minQuantity": 3,
//           "maxQuantity": null,
//           "cost": 900
//         }
//       ]
//     }
//   ],
//   "CA": [
//     {
//       "product": "mouse",
//       "costs": [
//         {
//           "minQuantity": 0,
//           "maxQuantity": null,
//           "cost": 750
//         }
//       ]
//     },
//     {
//       "product": "laptop",
//       "costs": [
//         {
//           "minQuantity": 0,
//           "maxQuantity": 2,
//           "cost": 1100
//         },
//         {
//           "minQuantity": 3,
//           "maxQuantity": null,
//           "cost": 1000
//         }
//       ]
//     }
//   ]
// }

// Update the function calculate_shipping_cost to now calculate shipping based upon the tiered discount.



// Examples:

// calculate_shipping_cost(order_us, shipping_cost) == 15700
// calculate_shipping_cost(order_ca, shipping_cost) == 20200
// Part 1

// Imagine an online hardware store that sells products of different sizes. The store could sell small items like a mouse or larger items like a laptop. These items cost a different amount to be shipped out. Shipping to different countries can also cost a different amount. Imagine you have an order object that looks like the below.
 
// Order:
// {
//   "country": "US", // or "CA" for the CA order
//   "items": [
//       {"product": "mouse", "quantity": 20},
//       {"product": "laptop", "quantity": 5}
//   ]
// }
 
// Note: In your solution you can pass in an in memory object that has the same shape as the json. You don't need to worry about parsing json for this problem.
  
// The US and CA orders have the same shape, they are just different countries.
 
// Each country/product has a corresponding shipping cost matrix. The cost is stored in the smallest currency unit.
  
// Shipping Cost:
// Each product has its own shipping cost
// {
//   "US": [
//     {"product": "mouse", "cost": 550},
//     {"product": "laptop", "cost": 1000}
//   ],
//   "CA": [
//     {"product": "mouse", "cost": 750},
//     {"product": "laptop", "cost": 1100}
//   ]
// }
 
// Write a function called calculate_shipping_cost that takes in an order and shipping cost matrix and returns the shipping cost.
 
// Examples:
// calculate_shipping_cost(order_us, shipping_cost) == 16000
// calculate_shipping_cost(order_ca, shipping_cost) == 20500
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Cost {
    Integer price;
    Integer minQuanitiy;
    Integer maxQuantity;
    
    public Cost(Integer price, Integer maxQuantity, Integer minQuanitiy) {
        this.price = price;
        this.maxQuantity = maxQuantity;
        this.minQuanitiy = minQuanitiy;
    }
    
    public Integer getPrice() {
        return this.price;
    }
    
    public Integer getMinQuanitiy() {
        return this.minQuanitiy;
    }
    
    public Integer getMaxQuantity() {
        return this.maxQuantity;
    }
}

class Product {
    private String name;
    private List<Cost> costList;
    
    public Product(String name, List<Cost> costList) {
        this.name = name;
        this.costList = costList;
    }

    public String getName() {
        return this.name;
    }
    
    public List<Cost> getCostList() {
        return this.costList;
    }
}

class ProductOrder {
    private String name;
    private Integer quantity;
    
    public ProductOrder(String name, int quantity) {
        this.name = name;
        this.quantity = quantity;
    }
    
    public String getName() {
        return this.name;
    }
    
    public Integer getQuantity() {
        return this.quantity;
    }
}

class Store {
    public int calculateShippingCost(
        String orderCountry, List<ProductOrder> productOrders,
        Map<String, List<Product>> shippingCost) throws Exception {
        int totalShippingCost = 0;
        List<Product> shippingCostByCountry = shippingCost.getOrDefault(orderCountry, null);
        if (shippingCostByCountry == null) {
            throw new Exception("Shipping not supported");
        }
        for (ProductOrder productOrder: productOrders) {
            for (Product product: shippingCostByCountry) {
                if (product.getName().equals(productOrder.getName())) {
                    totalShippingCost += getShippingCost(product, productOrder);
                }
            }
        }
        return totalShippingCost;
    }

	private int getShippingCost(Product product, ProductOrder productOrder) {
        int quantity = productOrder.getQuantity();
        int initialQuantity = productOrder.getQuantity();
        int totalCost = 0;
        for (Cost cost: product.getCostList()) {
            if (cost.getMaxQuantity() == null || cost.getMaxQuantity() >= initialQuantity) {
                totalCost += cost.getPrice()*quantity;
                return totalCost;
            }
            int quantityToMeasure = (cost.getMaxQuantity() - cost.getMinQuanitiy() + 1);
            quantity -= quantityToMeasure;
            totalCost += quantityToMeasure*cost.getPrice();
        }
        return totalCost;
	}
}

class Solution {
    
    public static void main(String args[] ) throws Exception {
         Map<String, List<Product>> shippingCost = new HashMap<>();
         List<Product> productUS = new ArrayList();
         List<Cost> costUSMouse = new ArrayList<>();
         costUSMouse.add(new Cost(550, null, 1));
         productUS.add(new Product("mouse", costUSMouse));
         List<Cost> costLaptop = new ArrayList<>();

         costLaptop.add(new Cost(1000, 2, 1));
         costLaptop.add(new Cost(900, null, 3));
         productUS.add(new Product("laptop", costLaptop));
         shippingCost.put("US", productUS);
         
         
         List<Product> productCA = new ArrayList();
         List<Cost> costCAMouse = new ArrayList<>();
         costCAMouse.add(new Cost(750, null, 1));
         productCA.add(new Product("mouse", costCAMouse));
         List<Cost> costCALaptop = new ArrayList<>();
         costCALaptop.add(new Cost(1100, 2, 1));
         costCALaptop.add(new Cost(1000, 4, 3));
         costCALaptop.add(new Cost(900, null, 5));
         productCA.add(new Product("laptop", costCALaptop));
         shippingCost.put("CA", productCA);
         
         List<ProductOrder> orders = new ArrayList<>();
         orders.add(new ProductOrder("mouse", 20));
         orders.add(new ProductOrder("laptop", 5));
         orders.add(new ProductOrder("keyboard", 5));
         
         Store store = new Store();
         
         System.out.println(store.calculateShippingCost("US", orders, shippingCost)); // 15700
         System.out.println(store.calculateShippingCost("CA", orders, shippingCost)); // 20100
         System.out.println(store.calculateShippingCost("IN", orders, shippingCost)); //exception
    }
}

/***

mouse -> 20
laptop -> 5

US -> mouse -> 550, laptop ->1000
550*20 + 900*3 + 2*1000 = 15700

CA -> 20*750 + 2*1100 + 3*1000 = 20200 
Assuming cost list is sorted based on min and max quanity w/o overlapping

*/