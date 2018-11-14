import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {

        int rowNum=0;
        int columnNum=0;
        ArrayList<Integer> DList=new ArrayList<Integer>();

        FileInputStream inputStream1=new FileInputStream("/home/popo/Desktop/alghw4/src/A2.c++");
        BufferedReader bufferedReader1=new BufferedReader(new InputStreamReader(inputStream1));
        String line1=null;
        String line2=null;
        while ((line1=bufferedReader1.readLine())!=null){
            line1=Utils.toCodeModule(line1);
            if("".equals(line1)){
                continue;
            }
            FileInputStream inputStream2=new FileInputStream("/home/popo/Desktop/alghw4/src/B2.c++");
            BufferedReader bufferedReader2=new BufferedReader(new InputStreamReader(inputStream2));
            while ((line2=bufferedReader2.readLine())!=null){
                line2=Utils.toCodeModule(line2);
                if("".equals(line2)){
                    continue;
                }
                if(rowNum==0){
                    columnNum++;
                }
                DList.add(Utils.genD(Utils.genS(line1,line2),0.9));
            }

            rowNum++;
        }

        System.out.println(Utils.getResult(rowNum,columnNum,DList));
    }
}
