import java.util.Scanner;

public class RadicalSimplification {
    public static void main(String[] args) {
        //创建Scanner对象
        Scanner scanner = new Scanner(System.in);
        //读入根式里的数字
        System.out.print("sqrt:");
        int n = scanner.nextInt();
        //读入次数
        System.out.print("times:");
        int times = scanner.nextInt();
        int ans = simp(n, times);
        if (Math.pow(ans, times) == n) {
            //刚好开完
            System.out.println(ans);
        } else if (ans == 1) {
            //无法化简
            System.out.println("sqrt" + times + "(" + n + ")");
        } else {
            //其他化简情况
            System.out.println(ans + " sqrt" + times + "(" + (int) (n / Math.pow(ans, times)) + ")");
        }
    }

    //判断是否整除
    static boolean isEvenly(int a, int b, int times) {
        for (int i = 0; i < times; i++) {
            if (a % b != 0) {
                return false;
            }
            a /= b;
        }
        return true;
    }

    //判断质数
    static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    //化简二次根式
    static int simp(int n, int times) {
        int result = 1;
        //如果是质数直接返回1
        if (isPrime(n)) {
            return result;
        }
        //在2~sqrt[times](n)中寻找i^times能被n整除的数
        for (int i = 2; Math.pow(i, times) <= n; i++) {
            if (isEvenly(n, i, times)) {
                //将当前n乘入结果
                result *= i;
                //将剩下的数表示出来，递归分解
                n = (int) (n / Math.pow(i, times));
                result *= simp(n, times);
                //找到一个就停止
                break;
            }
        }
        return result;
    }
}
