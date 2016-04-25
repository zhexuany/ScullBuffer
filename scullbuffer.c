#include <linux/configfs.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h>	/* printk() */
#include <linux/slab.h>		/* kmalloc() */
#include <linux/fs.h>		/* everything... */
#include <linux/errno.h>	/* error codes */
#include <linux/types.h>	/* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>	/* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>
//Linux kernel is changing rapidly. asm/uaccess.h is not available any more
#include <linux/uaccess.h>	/* copy_*_user */

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Zhexuan Yang");

/*declare function prototype*/

int open_device(struct inode *inode, struct file *fd);
int close_device(struct inode *inode, struct file *fd);
ssize_t read_from_device(struct file *fd, char *temp_buffer, size_t bytes_read, loff_t *offset);
ssize_t write_to_device(struct file *fd, const char __user *temp_buffer, size_t count,
                        loff_t *f_pos);
int initialize_device(void);
void destruct_device(void);



