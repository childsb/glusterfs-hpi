package org.apache.hadoop.fs.glusterfs;

import java.io.File;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;

import org.apache.hadoop.fs.FSError;
import org.apache.hadoop.fs.FSInputStream;
import org.apache.hadoop.fs.HasFileDescriptor;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.fs.FileSystem.Statistics;


public class GlusterFileIn extends FSInputStream implements HasFileDescriptor{
    protected Statistics statistics;
    
    class TrackingFileInputStream extends FileInputStream {
        public TrackingFileInputStream(File f) throws IOException {
          super(f);
        }
        
        @Override
        public int read() throws IOException {
          int result = super.read();
          if (result != -1) {
            statistics.incrementBytesRead(1);
          }
          return result;
        }
        
        @Override
        public int read(byte[] data) throws IOException {
          int result = super.read(data);
          if (result != -1) {
            statistics.incrementBytesRead(result);
          }
          return result;
        }
        
        @Override
        public int read(byte[] data, int offset, int length) throws IOException {
          int result = super.read(data, offset, length);
          if (result != -1) {
            statistics.incrementBytesRead(result);
          }
          return result;
        }
      }
    
    private FileInputStream fis;
    private long position;

    public GlusterFileIn(File f) throws IOException {
      this.fis = new TrackingFileInputStream(f);
    }
    
    @Override
    public void seek(long pos) throws IOException {
      fis.getChannel().position(pos);
      this.position = pos;
    }
    
    @Override
    public long getPos() throws IOException {
      return this.position;
    }
    
    @Override
    public boolean seekToNewSource(long targetPos) throws IOException {
      return false;
    }
    
    /*
     * Just forward to the fis
     */
    @Override
    public int available() throws IOException { return fis.available(); }
    @Override
    public void close() throws IOException { fis.close(); }
    @Override
    public boolean markSupported() { return false; }
    
    @Override
    public int read() throws IOException {
        int value = fis.read();
        if (value >= 0) {
          this.position++;
        }
        return value;
    }
    
    @Override
    public int read(byte[] b, int off, int len) throws IOException {
        int value = fis.read(b, off, len);
        if (value > 0) {
          this.position += value;
        }
        return value;
     
    }
    
    @Override
    public int read(long position, byte[] b, int off, int len)
      throws IOException {
      ByteBuffer bb = ByteBuffer.wrap(b, off, len);
        return fis.getChannel().read(bb, position);
     }
    
    @Override
    public long skip(long n) throws IOException {
      long value = fis.skip(n);
      if (value > 0) {
        this.position += value;
      }
      return value;
    }

    public FileDescriptor getFileDescriptor() throws IOException {
      return fis.getFD();
    }
}
