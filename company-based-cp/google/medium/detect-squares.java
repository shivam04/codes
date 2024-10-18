class DetectSquares {

    //store [x,y] points in HashMap and their count as value since duplicates are allowed
    HashMap<String, Integer> map;

    public DetectSquares() {
        map = new HashMap<>();    
    }
    
    //add point [x,y] to the HashMap
    public void add(int[] point) {
        String s = point[0] + ":" + point[1];
        map.put(s, map.getOrDefault(s, 0) + 1);
    }
    
    //get the count of squares which can be made for the given input point with 3 other points in the HashMap
    public int count(int[] point) {
        
        //init
        int count = 0;

        //loop through each point in the HashMap and check if it can be treated as a diagonal for the input point
        for(String k: map.keySet()){
            
            int x = Integer.parseInt(k.split(":")[0]);
            int y = Integer.parseInt(k.split(":")[1]);

            //if the current co-ordinate's x or y is same as input point, it cannot be a diagnonal so we can continue   
            //the length of the sides parallel to x and y should be same in order to form a square as well         
            if( (x == point[0] || y == point[1]) || (Math.abs(point[0]-x) != Math.abs(point[1]-y) ))
                continue;
            
            //if [x,y] can be a diagnonal for the input point, we can determine the co-ordinates of other two points 
            //but at this point, it can be a rectangle also. We will add a check for square also.
            //First Point: [x1, y1] = [p[0], y]
            //Second Point: [x2, y2] = [x, p[1]]
            int x1 = point[0];
            int y1 = y;
            
            int x2 = x;
            int y2 = point[1];

            //if the above two points are present in the HashMap, then we can form a square
            if(map.containsKey((x1 + ":" + y1)) && map.containsKey((x2 +":" +y2))){

                    //since duplicates are allowed, the number of ways we can form that square is:
                    //count += frequency of point 1 + frequency of point 2 + frequency of current diagonal point
                    count +=( map.get(x1 + ":" + y1) * map.get(x2 +":" +y2) * map.get(k));
            }

        }

        return count;

    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */