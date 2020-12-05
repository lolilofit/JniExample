import org.graalvm.polyglot.Source;
import org.graalvm.polyglot.Context;
import org.graalvm.polyglot.Value;

import java.io.File;
import java.io.IOException;

public class MainP {
    public static void main(String[] args) throws IOException  {
        Source s = Source.newBuilder("llvm", new File("/JniExample/JniProjectC/main.bc")).build();
        Context c = Context.newBuilder().allowNativeAccess(true).build();

        Value fn = c.eval(s).getMember("getInfo");
        String res = fn.execute().asString();

        System.out.println(res);
    }
}
