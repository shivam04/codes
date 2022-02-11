import java.util.*;

class Program {
  public static boolean isMonotonic(int[] array) {
    int n = array.length;
		boolean isInc = true;
		boolean isDec = true;
		for(int i=1;i<n;i++) {
			isInc = isInc && (array[i]>=array[i-1]);
		}
		
		for(int i=1;i<n;i++) {
			isDec = isDec && (array[i]<=array[i-1]);
		}
    return (isInc || isDec);
  }
}
