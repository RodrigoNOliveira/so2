import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
public class OSProcess {
    public static void main( String [] args ) throws IOException {
        if ( args.length != 1 ) {
            System.err.println("Uso : java OSProcess <comando>");
            System.exit( -1 ); 
        }
        ProcessBuilder pb = new ProcessBuilder( args[0] );
        Process proc = pb.start();
        InputStream is = proc.getInputStream();
        InputStreamReader isr = new InputStreamReader( is );
        BufferedReader br = new BufferedReader( isr );
        String line;
        while( ( line = br.readLine() ) != null ) {
            System.out.println( line );
        }
        br.close();
    }
}
