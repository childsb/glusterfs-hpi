# typedef struct glfs;
# typedef struct glfs glfs_t;

glfs_t *glfs_new (const char *volname);


int glfs_set_volfile (glfs_t *fs, const char *volfile);


int glfs_set_volfile_server (glfs_t *fs, const char *transport,
			     const char *host, int port);


int glfs_set_logging (glfs_t *fs, const char *logfile, int loglevel);



int glfs_init (glfs_t *fs);


int glfs_fini (glfs_t *fs);


struct glfs_fd;
typedef struct glfs_fd glfs_fd_t;

glfs_fd_t *glfs_open (glfs_t *fs, const char *path, int flags);


glfs_fd_t *glfs_creat (glfs_t *fs, const char *path, int flags,
		       mode_t mode);

int glfs_close (glfs_fd_t *fd);

glfs_t *glfs_from_glfd (glfs_fd_t *fd);

int glfs_set_xlator_option (glfs_t *fs, const char *xlator, const char *key,
			    const char *value);

typedef void (*glfs_io_cbk) (glfs_fd_t *fd, ssize_t ret, void *data);


ssize_t glfs_read (glfs_fd_t *fd, void *buf, size_t count, int flags);
ssize_t glfs_write (glfs_fd_t *fd, const void *buf, size_t count, int flags);
int glfs_read_async (glfs_fd_t *fd, void *buf, size_t count, int flags,
		     glfs_io_cbk fn, void *data);
int glfs_write_async (glfs_fd_t *fd, const void *buf, size_t count, int flags,
		      glfs_io_cbk fn, void *data);


ssize_t glfs_readv (glfs_fd_t *fd, const struct iovec *iov, int iovcnt,
		    int flags);
ssize_t glfs_writev (glfs_fd_t *fd, const struct iovec *iov, int iovcnt,
		     int flags);
int glfs_readv_async (glfs_fd_t *fd, const struct iovec *iov, int count,
		      int flags, glfs_io_cbk fn, void *data);
int glfs_writev_async (glfs_fd_t *fd, const struct iovec *iov, int count,
		       int flags, glfs_io_cbk fn, void *data);


ssize_t glfs_pread (glfs_fd_t *fd, void *buf, size_t count, off_t offset,
		    int flags);
ssize_t glfs_pwrite (glfs_fd_t *fd, const void *buf, size_t count,
		     off_t offset, int flags);
int glfs_pread_async (glfs_fd_t *fd, void *buf, size_t count, off_t offset,
		      int flags, glfs_io_cbk fn, void *data);
int glfs_pwrite_async (glfs_fd_t *fd, const void *buf, int count, off_t offset,
		       int flags, glfs_io_cbk fn, void *data);


ssize_t glfs_preadv (glfs_fd_t *fd, const struct iovec *iov, int iovcnt,
		     off_t offset, int flags);
ssize_t glfs_pwritev (glfs_fd_t *fd, const struct iovec *iov, int iovcnt,
		      off_t offset, int flags);
int glfs_preadv_async (glfs_fd_t *fd, const struct iovec *iov, int count,
		       off_t offset, int flags, glfs_io_cbk fn, void *data);
int glfs_pwritev_async (glfs_fd_t *fd, const struct iovec *iov, int count,
			off_t offset, int flags, glfs_io_cbk fn, void *data);


off_t glfs_lseek (glfs_fd_t *fd, off_t offset, int whence);

int glfs_truncate (glfs_t *fs, const char *path, off_t length);

int glfs_ftruncate (glfs_fd_t *fd, off_t length);
int glfs_ftruncate_async (glfs_fd_t *fd, off_t length, glfs_io_cbk fn,
			  void *data);

int glfs_lstat (glfs_t *fs, const char *path, struct stat *buf);
int glfs_stat (glfs_t *fs, const char *path, struct stat *buf);
int glfs_fstat (glfs_fd_t *fd, struct stat *buf);

int glfs_fsync (glfs_fd_t *fd);
int glfs_fsync_async (glfs_fd_t *fd, glfs_io_cbk fn, void *data);

int glfs_fdatasync (glfs_fd_t *fd);
int glfs_fdatasync_async (glfs_fd_t *fd, glfs_io_cbk fn, void *data);

int glfs_access (glfs_t *fs, const char *path, int mode);

int glfs_symlink (glfs_t *fs, const char *oldpath, const char *newpath);

int glfs_readlink (glfs_t *fs, const char *path, char *buf, size_t bufsiz);

int glfs_mknod (glfs_t *fs, const char *path, mode_t mode, dev_t dev);

int glfs_mkdir (glfs_t *fs, const char *path, mode_t mode);

int glfs_unlink (glfs_t *fs, const char *path);

int glfs_rmdir (glfs_t *fs, const char *path);

int glfs_rename (glfs_t *fs, const char *oldpath, const char *newpath);

int glfs_link (glfs_t *fs, const char *oldpath, const char *newpath);

glfs_fd_t *glfs_opendir (glfs_t *fs, const char *path);

int glfs_readdir_r (glfs_fd_t *fd, struct dirent *dirent,
		    struct dirent **result);

int glfs_readdirplus_r (glfs_fd_t *fd, struct stat *stat, struct dirent *dirent,
			struct dirent **result);

long glfs_telldir (glfs_fd_t *fd);

void glfs_seekdir (glfs_fd_t *fd, long offset);

int glfs_closedir (glfs_fd_t *fd);

int glfs_statvfs (glfs_t *fs, const char *path, struct statvfs *buf);

int glfs_chmod (glfs_t *fs, const char *path, mode_t mode);

int glfs_fchmod (glfs_fd_t *fd, mode_t mode);

int glfs_chown (glfs_t *fs, const char *path, uid_t uid, gid_t gid);

int glfs_lchown (glfs_t *fs, const char *path, uid_t uid, gid_t gid);

int glfs_fchown (glfs_fd_t *fd, uid_t uid, gid_t gid);

int glfs_utimens (glfs_t *fs, const char *path, struct timespec times[2]);

int glfs_lutimens (glfs_t *fs, const char *path, struct timespec times[2]);

int glfs_futimens (glfs_fd_t *fd, struct timespec times[2]);

ssize_t glfs_getxattr (glfs_t *fs, const char *path, const char *name,
		       void *value, size_t size);

ssize_t glfs_lgetxattr (glfs_t *fs, const char *path, const char *name,
			void *value, size_t size);

ssize_t glfs_fgetxattr (glfs_fd_t *fd, const char *name,
			void *value, size_t size);

ssize_t glfs_listxattr (glfs_t *fs, const char *path, void *value, size_t size);

ssize_t glfs_llistxattr (glfs_t *fs, const char *path, void *value,
			 size_t size);

ssize_t glfs_flistxattr (glfs_fd_t *fd, void *value, size_t size);

int glfs_setxattr (glfs_t *fs, const char *path, const char *name,
		   const void *value, size_t size, int flags);

int glfs_lsetxattr (glfs_t *fs, const char *path, const char *name,
		    const void *value, size_t size, int flags);

int glfs_fsetxattr (glfs_fd_t *fd, const char *name,
		    const void *value, size_t size, int flags);

int glfs_removexattr (glfs_t *fs, const char *path, const char *name);

int glfs_lremovexattr (glfs_t *fs, const char *path, const char *name);

int glfs_fremovexattr (glfs_fd_t *fd, const char *name);

int glfs_fallocate(glfs_fd_t *fd, int keep_size, off_t offset, size_t len);

int glfs_discard(glfs_fd_t *fd, off_t offset, size_t len);

int glfs_discard_async (glfs_fd_t *fd, off_t length, size_t lent,
			glfs_io_cbk fn, void *data);

char *glfs_getcwd (glfs_t *fs, char *buf, size_t size);

int glfs_chdir (glfs_t *fs, const char *path);

int glfs_fchdir (glfs_fd_t *fd);

char *glfs_realpath (glfs_t *fs, const char *path, char *resolved_path);

int glfs_posix_lock (glfs_fd_t *fd, int cmd, struct flock *flock);

glfs_fd_t *glfs_dup (glfs_fd_t *fd);

