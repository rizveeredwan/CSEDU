import java.io.*;
import java.util.*;


class HashingString {

    int theHashValue(String a, int modNumber) {
      int sum=0;
      int stringLength=a.length();
      for(int i=0;i<=stringLength-1;i++) {
         char character = a.charAt(i);
         sum = sum + (character)%modNumber;
      }
      return sum;
    }
}



public class test {

  public static void main(String[] args) {
    HashingString object = new HashingString();
    int value = object.theHashValue("ABC",7);
    System.out.println("value = " + value);
  } 

}
