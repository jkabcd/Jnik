package dd.sdl.com.myapplication;


public class GPIOControl {
    // JNI
    public static native int nativeReadGpio(String path);
    public static native int nativeWriteGpio(String path, String value);
    private static final String mPathstr = "/sys/class/gpio/gpio";
    private static final String mDirectDir = "/direction";
    private static final String mValueDir = "/value";
    public static int writeGpioValue(int num, int value)
     {
         String dataPath = composePinPath(num).concat(mValueDir);
         return nativeWriteGpio(dataPath, Integer.toString(value));
     }
     public static int readGpioValue(int num)
     {
         String dataPath = composePinPath(num).concat(mValueDir);
         return nativeReadGpio(dataPath);
     }
     public static int writeGpioDirection(int num, int value)
    {
        String dataPath = composePinPath(num).concat(mDirectDir);
        String direct; if(value == 0) { direct = "in";
        } else if(value == 1) {
            direct = "out";
        } else {
            return -1;
        }
        return nativeWriteGpio(dataPath, direct);
    }
    public static int readGpioDirection(int num)
    {
        String dataPath = composePinPath(num).concat(mDirectDir);
        return nativeReadGpio(dataPath);
    }
    private static String composePinPath(int num)
    {
        String numstr; numstr = Integer.toString(num);
        return mPathstr.concat(numstr);
    }
    static
    {
        System.loadLibrary("GPIOControl");
    }
}
