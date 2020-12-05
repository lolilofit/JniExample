import org.graalvm.polyglot.Source;
import org.graalvm.polyglot.Context;
import org.graalvm.polyglot.Value;

import java.io.File;

public class MainP {
    public static void main(String[] args) {
        Source s = Source.newBuilder("llvm", new File("/JniExample/JniProject/main.bc")).build();
        Context c = Context.newBuilder().allowNativeAccess(true).build();

        Value fn = c.eval(s).getMember("getInfo");
        String res = fn.execute().asString();

        System.out.println(res);
    }
}
