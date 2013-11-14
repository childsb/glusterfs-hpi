package org.apache.hadoop.fs.glusterfs;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import org.apache.hadoop.fs.FSError;
import org.apache.hadoop.fs.Path;

public class GlusterFileOut extends OutputStream{
   private FileOutputStream fos;
    
    private GlusterFileOut(File f, boolean append) throws IOException {
      this.fos = new FileOutputStream(f, append);
    }
    
    /*
     * Just forward to the fos
     */
    @Override
    public void close() throws IOException { fos.close(); }
    @Override
    public void flush() throws IOException { fos.flush(); }
    @Override
    public void write(byte[] b, int off, int len) throws IOException {
        fos.write(b, off, len);
    }
    
    @Override
    public void write(int b) throws IOException {
        fos.write(b);
    }

}
