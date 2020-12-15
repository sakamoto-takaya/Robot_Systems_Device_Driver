#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>　
#include <linux/dilay.h>

MODULE_AUTHOR("Takaya Sakamoto and Ryuichi Ueda and Yuya hasegawa");
MODULE_DESCRIPTION("driver for LED control");                                                                                                                                                                                                           MODULE_AUTHOR("Yuya Hasegawa and Ryuichi Ueda , Takaya Sakamoto");                                                   MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
char c;
if(copy_from_user(&c,buf,sizeof(char)))
return -EFAULT;

char *ptr = c;

while(*ptr != '\0'){
  if(*ptr == 'a' || *ptr == 'A'){ //・ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'b' || *ptr == 'B'){//ー・・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'c' || *ptr == 'C'){//ー・－・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'd' || *ptr == 'D'){//ー・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'e' || *ptr == 'E'){//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'f' || *ptr == 'F'){//・・－・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'g' || *ptr == 'G'){//ーー・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'h' || *ptr == 'H'){//・・・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'i' || *ptr == 'I'){//・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'j' || *ptr == 'J'){//・－－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'k' || *ptr == 'K'){//ー・－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'l' || *ptr == 'L'){//・－・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'm' || *ptr == 'M'){//ーー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'n' || *ptr == 'N'){//ー・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'o' || *ptr == 'O'){//ーーー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'p' || *ptr == 'P'){//・－－・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 'q' || *ptr == 'Q'){//ーー・－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'r' || *ptr == 'R'){//・－・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 's' || *ptr == 'S'){//・・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == 't' || *ptr == 'T'){//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'u' || *ptr == 'U'){//・・－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'v' || *ptr == 'V'){//・・・－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'w' || *ptr == 'W'){//・－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'x' || *ptr == 'X'){//ー・・－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'y' || *ptr == 'Y'){//ー・－－
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == 'z' || *ptr == 'Z'){//ーー・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == '1'){//・－－－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == '2'){//・・－－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == '3'){//・・・－－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == '4'){//・・・・－
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else if (*ptr == '5'){//・・・・・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == '6'){//ー・・・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == '7'){//ーー・・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == '8'){//ーーー・・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == '9'){//ーーーー・
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(200); gpio_base[10] = 1 << 25; msleep(200);//・
  } else if (*ptr == '0'){//ーーーーー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
    gpio_base[7] = 1 << 25; msleep(600); gpio_base[10] = 1 << 25; msleep(200);//ー
  } else {//例外処理
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
 .write = led_write,
 .read = sushi_read
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