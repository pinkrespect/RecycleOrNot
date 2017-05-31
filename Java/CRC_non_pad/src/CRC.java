import java.util.Arrays;
import java.util.stream.IntStream;

/**
 * Created by maisie on 17. 5. 31.
 */
public class CRC {
    static int[] CRC_Checker(int[] input){
        int[] divisor = new int[]{1, 1, 0, 1, 0, 1};
        int[] register = new int[divisor.length-1];

        IntStream.range(0, input.length).forEachOrdered(i -> {
            System.out.println("loop: " + (i+1));
            IntStream.range(0, divisor.length).forEachOrdered(j ->{
                if(j == 0){
                    register[register.length-2] = register[register.length-1];
                    register[register.length-1] = input[j] ^ register[j];
                }else if(j < register.length - 1){
                    if(divisor[j] == 1)
                        register[j-1] = register[j] ^ register[register.length-1];
                    else
                        register[j-1] = register[j];
                }
            });
            for (int k = 0; k < register.length;k++)
                System.out.println("register["+ k + "]" + register[k]);
            System.out.println();
        });
        return IntStream.concat(Arrays.stream(input), Arrays.stream(register)).toArray();
    }
    public static void main(String args[]) {
        System.out.println(Arrays.toString(CRC_Checker(new int[]{1, 0, 1, 0, 0, 0, 1, 1, 0, 1})));
    }
}
