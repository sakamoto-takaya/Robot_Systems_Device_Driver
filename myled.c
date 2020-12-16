#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>　
#include <linux/delay.h>

MODULE_AUTHOR("Takaya Sakamoto and Ryuichi Ueda and Yuya hasegawa");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
char* c = [30];
int i , j;
i = 0;
j = 0;

if(copy_from_user(&c,buf,sizeof(char)))
return -EFAULT;

for(i = 0; i < 30; i++){
  if(c[i] == 'a' || c[i] == 'A'){ //・ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i]r == 'b' || c[i] == 'B'){//ー・・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'c' || c[i] == 'C'){//ー・－・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'd' || c[i] == 'D'){//ー・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'e' || c[i] == 'E'){//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'f' || c[i] == 'F'){//・・－・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'g' || c[i] == 'G'){//ーー・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'h' || c[i] == 'H'){//・・・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'i' || c[i] == 'I'){//・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'j' || c[i] == 'J'){//・－－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'k' || c[i] == 'K'){//ー・－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'l' || c[i] == 'L'){//・－・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'm' || c[i] == 'M'){//ーー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'n' || c[i] == 'N'){//ー・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'o' || c[i] == 'O'){//ーーー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'p' || c[i] == 'P'){//・－－・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 'q' || c[i] == 'Q'){//ーー・－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'r' || c[i] == 'R'){//・－・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 's' || c[i] == 'S'){//・・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == 't' || c[i] == 'T'){//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'u' || c[i] == 'U'){//・・－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'v' || c[i] == 'V'){//・・・－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'w' || c[i] == 'W'){//・－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'x' || c[i] == 'X'){//ー・・－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'y' || c[i] == 'Y'){//ー・－－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == 'z' || c[i] == 'Z'){//ーー・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == '1'){//・－－－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == '2'){//・・－－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == '3'){//・・・－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == '4'){//・・・・－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (c[i] == '5'){//・・・・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == '6'){//ー・・・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == '7'){//ーー・・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == '8'){//ーーー・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == '9'){//ーーーー・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (c[i] == '0'){//ーーーーー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else {//例外処理
    for (j = 0; j < 5; j++){
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);
    }

    gpio_base[10] = 1 << 25;
    msleep(1000);
  }
  gpio_base[10] = 1 << 25;
  msleep(500);
  }

return 1;
}

static struct file_operations led_fops = {
 .owner = THIS_MODULE,
 .write = led_write
};

static int __init init_mod(void)
{
 int retval;

 gpio_base = ioremap_nocache(0xfe200000, 0xA0);
 const u32 led = 25;
 const u32 index = led/10;
 const u32 shift = (led%10)*3;
 const u32 mask = ~(0x7 << shift);
 gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);

 retval =  alloc_chrdev_region(&dev, 0, 1, "myled");
 if(retval < 0){
  printk(KERN_ERR "alloc_chrdev_region failed.\n");
  return retval;
 }
 printk(KERN_INFO "%s is loaded. major:%d\n",__FILE__,MAJOR(dev));

 cdev_init(&cdv, &led_fops);
 retval = cdev_add(&cdv, dev, 1);
 if(retval < 0){
  printk(KERN_ERR "cdev_add failed. major:%d, minor:%d",MAJOR(dev),MINOR(dev));
  return retval;
}
 cls = class_create(THIS_MODULE,"myled");
 if(IS_ERR(cls)){
  printk(KERN_ERR "class_create failed.");
  return PTR_ERR(cls);
 }
 device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));
 return 0;
}


static void __exit cleanup_mod(void)
{
 cdev_del(&cdv);
 device_destroy(cls, dev);
 class_destroy(cls);
 unregister_chrdev_region(dev, 1);
 printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
 iounmap(gpio_base);
}

module_init(init_mod);
module_exit(cleanup_mod);
