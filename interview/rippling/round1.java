import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;



// Design and implement an Excel Spreadsheet.
// You are building a library that a front-end team may use to surface a spreadsheet to some users.
// We want this to be a MVP library that can be expanded in the future if necessary.
// All data can be stored in memory.

// We have the following requirements:

// We need to support integer values and formula values for the plus operator.

// For example, cell values may be:

// * -9, 2, 3, 100, etc. (maximum of 3 digits per integer)
// * =2+8, =100+2, etc. (with exactly two integers)

// We need to be able to reset cells to their default value, by giving the empty string.

// We need to be able to view the spreadsheet, with both the raw and computed values shown.
// For example, for “=2+8”, the raw value is “=2+8” and the computed value is “10”.
// This does not have to look like a real spreadsheet, as long as the values are clear when printed.
// Create a print method to print the whole spreadsheet, or return the spreadsheet data as a string.

// The team will later focus on reference values, such as `=A1+B2`.

/**
let's define each cell as:
A1, A2,
B1, B2
..

A1 -> "12", "=2+3"
Map -> <Key, Value>
Value {
    String raw;
    String computed;
}

computed part -> 
if raw start with "=" then we need to do computation

**/

class Cell {
    String raw;
    String computed;
    
    public Cell(String raw) {
        if (raw == "") {
            raw = null;
        }
        this.raw = raw;
    }
    
    public String getRaw() {
        return raw;
    }
    
    public String getComputed() {
        return computed;
    }
    
    public void setRaw(String raw) {
        if (raw != this.raw) {
            setComputed(null);
        }
        this.raw = raw;
        
    }
    
    public void setComputed(String computed) {
        this.computed = computed;
    }
}
//map<k, list<p>>

public class Excel {
    
    private Map<String, Cell> spreadSheet;
    
    public Excel() {
        spreadSheet = new TreeMap<String, Cell>();
    }
    
    public  Map<String, Cell> getSpreadSheet() {
        return spreadSheet;
    }
    
    public void setSpreadSheet( Map<String, Cell> spreadSheet) {
        this.spreadSheet = spreadSheet;
    }
    
    public Integer parseInteger(String val) {
        try {
            //  1. if A1 ="B1+B2" computeCellValue(A1, ="raw")
            // 2. B1 =C1+C2 computeCellValue(B1, C1+C2)
            return Integer.parseInt(val);
        } catch (Exception ex) {
            throw ex;
        }
    }
    
    private Cell getCell(String key) {
        return spreadSheet.get(key) == null ? new Cell("") : spreadSheet.get(key);
    }
    
    private void computeCellValue(String key, String raw) {
        Cell cell = getCell(key);
        if (raw == null || !raw.startsWith("=")) {
            cell.setComputed(raw);
            spreadSheet.put(key, cell);
            return;
        }
        System.out.println("Computing... " + raw);
        String[] values = raw.substring(1).split("\\+");
        // 1. B1 + B2
        Integer firstVal = parseInteger(values[0]);
        Integer secondVal = parseInteger(values[1]);
        
        cell.setComputed(String.valueOf(firstVal + secondVal));
        spreadSheet.put(key, cell);
    }
    
    private void print() {
        for(Map.Entry<String, Cell> cell: spreadSheet.entrySet()) {
            Cell currentCell = cell.getValue();
            String cellKey = cell.getKey();
            if (currentCell.getComputed() == null) {
                computeCellValue(cellKey, currentCell.getRaw());
            }
            System.out.println(cell.getKey() + " contains raw: " + currentCell.getRaw() + " computed: " + currentCell.getComputed());
        }
    }
    

    public static void main(String[] args) {
        Excel excel = new Excel();
        Map<String, Cell> spreadSheet = new TreeMap<String, Cell>();
        spreadSheet.put("A1", new Cell("12"));
        spreadSheet.put("A2", new Cell("=-1+2"));
        spreadSheet.put("B1", new Cell("=-1+-2"));
        spreadSheet.put("B2", new Cell("=1+-2"));
        spreadSheet.put("A3", new Cell(""));
        excel.setSpreadSheet(spreadSheet);
        excel.print();
        System.out.println("==============");
        excel.getSpreadSheet().get("A2").setRaw("");
        excel.print();
        System.out.println("==============");
        excel.getSpreadSheet().get("A2").setRaw("=-9+-99");
        excel.print();
        
    }
}
