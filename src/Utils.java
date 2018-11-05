import static java.lang.Math.max;
import static java.lang.Math.min;

public class Utils {

    public static int lsc(String s1,String s2){
        final int s1Len=s1.length();
        final int s2Len=s2.length();
        int board[][]=new int[s1Len+1][s2Len+1];
        for(int i=0;i<=s1Len;++i){
            for(int j=0;j<=s2Len;++j){
                if(i==0||j==0){
                    board[i][j]=0;
                }else if(s1.charAt(i-1)==s2.charAt(j-1)){
                    board[i][j]=board[i-1][j-1]+1;
                }else {
                    board[i][j]=max(board[i-1][j],board[i][j-1]);
                }
            }
        }
        return board[s1Len][s2Len];
    }

    public static String toCodeModule(String line){
        StringBuffer result=new StringBuffer();
        for(int i=0;i<line.length();++i){
            if(Character.isLetterOrDigit(line.charAt(i))||Character.isWhitespace(line.charAt(i))){
                result=result.append(line.charAt(i));
            }
        }
        return result.toString();
    }

    public static double genS(String s1,String s2){
        double res=lsc(s1,s2);
        double len=min(s1.length(),s2.length());
        return res/len;
    }

    public static int genD(double res,double r){
        if(res>r){
            return 1;
        }else {
            return 0;
        }
    }
}
