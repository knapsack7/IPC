import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileReader;

public class clientJava{
   private static final String FIFO = "temp";

   public static void main(String[] args){
      System.out.println("Trying to communicate to c generated file");
      BufferedReader in = null;
      try{
         System.out.println("JAVA SIDE!!");
         in = new BufferedReader(new FileReader(FIFO));
         while(in.ready()){
             System.out.println(in.readLine());
         }
         //done, however you can choose to cycle over this line
         //in this thread or launch another to check for new input
         in.close();
      }catch(IOException ex){
         System.err.println("IO Exception at buffered read!!");
         System.exit(-1);
      }
   }
}
