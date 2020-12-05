public class Main {
    static {
        System.loadLibrary("libJniProject");
    }

    private native String getInfo();

    public static void main(String[] args) {
        String[] info = new Main().getInfo().split(":");
        if(info.length > 0)
            System.out.println("THREADS NUMBER: " + info[0]);
        if(info.length > 1)
            System.out.println("CPU MODEL/FREQUENCY: " + info[1]);
    }
}
