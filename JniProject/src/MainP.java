import org.graalvm.polyglot.Source;
import org.graalvm.polyglot.Context;
import org.graalvm.polyglot.Value;

import java.io.File;
import java.io.IOException;

public class MainP {
    public static void main(String[] args) throws IOException  {
        Source s = Source.newBuilder("llvm", new File("/JniExample/JniProjectC/main.bc")).build();
        Context c = Context.newBuilder().allowAllAccess(true).build();

        Value e = c.eval(s);
        Value fb = e.getMember("getInfo");
        String res = fn.execute().asString();

        System.out.println(res);
    }
}
