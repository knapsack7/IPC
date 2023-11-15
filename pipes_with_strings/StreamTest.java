import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;

public class StreamTest{
    private static final int buffer = 4096;
    
    public static void main(String[] args){
        InputStream is = null;
        BufferedInputStream bis = null;
        try{
            bis = new BufferedInputStream(System.in,buffer);
            StringBuilder sb = new StringBuilder();
            //sb.append((char)bis.read());
            while(bis.available() > 0){
                sb.append((char)bis.read());
            }
            System.out.println("JAVA SIDE: "+sb.toString());
            bis.close();
        }catch(IOException ex){
            
        }finally{
            
            
        }
    }
}
