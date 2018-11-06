import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        FileInputStream inputStream1=new FileInputStream("/home/popo/Desktop/alghw4/src/B0.c++");
        BufferedReader bufferedReader1=new BufferedReader(new InputStreamReader(inputStream1));
        String line1=null;
        String line2=null;
        while ((line1=bufferedReader1.readLine())!=null){
            line1=Utils.toCodeModule(line1);
            if("".equals(line1)){
                continue;
            }
            FileInputStream inputStream2=new FileInputStream("/home/popo/Desktop/alghw4/src/A0.c++");
            BufferedReader bufferedReader2=new BufferedReader(new InputStreamReader(inputStream2));
            while ((line2=bufferedReader2.readLine())!=null){
                line2=Utils.toCodeModule(line2);
                if("".equals(line2)){
                    continue;
                }
                System.out.print(Utils.genD(Utils.genS(line1,line2),0.9));
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}
